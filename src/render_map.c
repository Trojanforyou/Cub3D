
#include "../cub3d.h"

void raycast_and_draw(t_data *data, s_player *player)
{
    int h = data->height;

    mlx_image_t *img = mlx_new_image(data->mlx, data->width, h);
    if (!img)
        return;

    for (int x = 0; x < data->width; x++)
    {
        double cameraX = 2 * x / (double)data->width - 1;
        double rayDirX = player->dirX + player->planeX * cameraX;
        double rayDirY = player->dirY + player->planeY * cameraX;

        int mapX = (int)player->posX;
        int mapY = (int)player->posY;

        double sideDistX;
        double sideDistY;

        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        int stepX, stepY;
        int hit = 0;
        int side;

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (player->posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player->posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (player->posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player->posY) * deltaDistY;
        }

        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (data->map[mapY][mapX] == '1')
                hit = 1;
        }

        if (side == 0)
            perpWallDist = (mapX - player->posX + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - player->posY + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(h / perpWallDist);

        int drawStart = -lineHeight / 2 + h / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + h / 2;
        if (drawEnd >= h) drawEnd = h - 1;

        // Texture selection (example: always wall_img[0])
        mlx_image_t *tex = data->wall_img[0];
        int tex_width = tex->width;
        int tex_height = tex->height;

        double wallX;
        if (side == 0)
            wallX = player->posY + perpWallDist * rayDirY;
        else
            wallX = player->posX + perpWallDist * rayDirX;
        wallX -= floor(wallX);

        int texX = (int)(wallX * (double)tex_width);
        if (side == 0 && rayDirX > 0) texX = tex_width - texX - 1;
        if (side == 1 && rayDirY < 0) texX = tex_width - texX - 1;

        for (int y = drawStart; y < drawEnd; y++)
        {
            int d = y * 256 - h * 128 + lineHeight * 128;
            int texY = ((d * tex_height) / lineHeight) / 256;
            uint8_t *pixel = &tex->pixels[4 * (texY * tex_width + texX)];
            uint32_t color = (pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3];
            mlx_put_pixel(img, x, y, color);
        }
    }
    mlx_image_to_window(data->mlx, img, 0, 0);
}


void    render_map(t_data *data)
{
    int y;
    int x;

    y = -1;
    while (data->map[++y])
    {
        x = -1;
        while (data->map[y][++x])
        {
            if (data->map[y][x] == '1')
            {
                mlx_image_to_window(data->mlx, data->wall_img[0], x * TITLE_SIZE, y * TITLE_SIZE);
            }
            else if (data->map[y][x] == '0')
            {
                // floors
            }
        }
    }
}
