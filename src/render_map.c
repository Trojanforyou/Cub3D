#include "../cub3d.h"

// DDA loop: marches ray through the map until a wall is hit
void DDA_loop(Ray *ray, t_data *data)
{
    ray->hit = 0;
    while (ray->hit == 0)
    {
        if (ray->sideDistX < ray->sideDistY)
        {
            ray->sideDistX += ray->deltaDistX;
            ray->mapX += ray->stepX;
            ray->side = 0;
        }
        else
        {
            ray->sideDistY += ray->deltaDistY;
            ray->mapY += ray->stepY;
            ray->side = 1;
        }

        if (data->map[ray->mapY][ray->mapX] != '0')
            ray->hit = data->map[ray->mapY][ray->mapX] - '0';
    }
}

// find the nearst vertical and horizontal lines
void calculate_step_and_side_dist(Ray *ray, s_player *player)
{
    if (ray->rayDirX < 0)
    {
        ray->stepX = -1;
        ray->sideDistX = (player->posX - ray->mapX) * ray->deltaDistX;
    }
    else
    {
        ray->stepX = 1;
        ray->sideDistX = (ray->mapX + 1.0 - player->posX) * ray->deltaDistX;
    }

    if (ray->rayDirY < 0)
    {
        ray->stepY = -1;
        ray->sideDistY = (player->posY - ray->mapY) * ray->deltaDistY;
    }
    else
    {
        ray->stepY = 1;
        ray->sideDistY = (ray->mapY + 1.0 - player->posY) * ray->deltaDistY;
    }
}

// Draws a Y axis texture line at column x
void draw_vertical_stripe(mlx_image_t *img, mlx_image_t *tex, int x, int drawStart, int drawEnd, int lineHeight, int texX)
{
    int y;
    int texY;
    uint8_t *pixel;
    uint32_t color;

    for (y = drawStart; y < drawEnd; y++)
    {
        texY = ((y - drawStart) * (int)tex->height) / lineHeight;

        if (texY < 0) 
            texY = 0;
        if (texY >= (int)tex->height) 
            texY = (int)tex->height - 1;

        pixel = &tex->pixels[4 * (texY * (int)tex->width + texX)];
        color = (pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3];
        mlx_put_pixel(img, x, y, color);
    }
}

void draw_textured_wall( t_data *data, s_player *player, mlx_image_t *img, Ray *ray, int x)
{
    int         lineHeight;
    int         drawStart;
    int         drawEnd;
    mlx_image_t *tex;
    double      wallX;
    int         texX;

    lineHeight = (int)(data->height / ray->perpWallDist);
    drawStart = -lineHeight / 2 + data->height / 2;
    drawEnd = lineHeight / 2 + data->height / 2;
    if (drawStart < 0)
        drawStart = 0;
    if (drawEnd >= data->height)
        drawEnd = data->height - 1;
    tex = data->wall_img[ray->hit];
    if (ray->side == 0)
        wallX = player->posY + ray->perpWallDist * ray->rayDirY;
    else
        wallX = player->posX + ray->perpWallDist * ray->rayDirX;
    wallX -= floor(wallX);
    texX = (int)(wallX * tex->width);
    if ((ray->side == 0 && ray->rayDirX > 0)
        || (ray->side == 1 && ray->rayDirY < 0))
        texX = tex->width - texX - 1;
    draw_vertical_stripe(img, tex, x, drawStart, drawEnd, lineHeight, texX);
}

void    raycast_and_draw(t_data *data, s_player *player)
{
    mlx_image_t *img;
    Ray         ray;
    double      cameraX;

    img = mlx_new_image(data->mlx, data->width, data->height);
    if (!img)
        return;
    for (int x = 0; x < data->width; x++)
    {
        cameraX = 2 * x / (double)data->width - 1;
        ray.rayDirX = player->dirX + player->planeX * cameraX;
        ray.rayDirY = player->dirY + player->planeY * cameraX;
        ray.mapX = (int)player->posX;
        ray.mapY = (int)player->posY;
        ray.deltaDistX = fabs(1 / ray.rayDirX);
        ray.deltaDistY = fabs(1 / ray.rayDirY);
        calculate_step_and_side_dist(&ray, player);
        DDA_loop(&ray, data);
        ray.perpWallDist = (ray.mapY - player->posY + (1 - ray.stepY) / 2) / ray.rayDirY;
        if (ray.side == 0)
            ray.perpWallDist = (ray.mapX - player->posX + (1 - ray.stepX) / 2) / ray.rayDirX;
        draw_textured_wall(data, player, img, &ray, x);
    }
    mlx_image_to_window(data->mlx, img, 0, 0);
}
