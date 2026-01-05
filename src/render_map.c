#include "../cub3d.h"

//raycast_and_draw
//│
//├─ init_ray                // math setup
//├── calculate_step_and_side // grid stepping setup
//├── DDA_loop                // map collision
//├── calculate_perp_dist     // camera correction
//└── draw_textured_wall      // rendering only

// seg faultin here for 
// whenever I go past the last walls so its due to reading 
// from the map past a valid place
// DDA loop: marches ray through the map until a wall is hit

void draw_vertical_stripe(mlx_image_t *img, mlx_image_t *tex, s_stripe stripe)
{
    int        y;
    int        texY;
    uint8_t    *pixel;
    uint32_t   color;

    y = stripe.drawStart;
    while (y < stripe.drawEnd)
    {
        texY = ((y - stripe.drawStart) * (int)tex->height) / stripe.lineHeight;
        if (texY < 0) 
            texY = 0;
        if (texY >= (int)tex->height) 
            texY = (int)tex->height - 1;
        pixel = &tex->pixels[4 * (texY * (int)tex->width + stripe.texX)];
        color = (pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3];
        mlx_put_pixel(img, stripe.x, y++, color); // slow should replace with direct change
    }
}

void draw_textured_wall(s_player *player, mlx_image_t *img, s_Ray *ray, int x)
{
    s_stripe stripe;
    double wallX;

    stripe.x = x; // current screen column
    // wall height
    stripe.lineHeight = (int)(player->data->height / ray->perpWallDist);
    // top & bottom on screen
    stripe.drawStart = -stripe.lineHeight / 2 + player->data->height / 2;
    stripe.drawEnd = stripe.lineHeight / 2 + player->data->height / 2;
    if (stripe.drawStart < 0) 
        stripe.drawStart = 0;
    if (stripe.drawEnd >= player->data->height) 
        stripe.drawEnd = player->data->height - 1;
    if (ray->side == 0)
        wallX = player->pos.y + ray->perpWallDist * ray->rayDir.y;
    else
        wallX = player->pos.x + ray->perpWallDist * ray->rayDir.x;
    wallX -= floor(wallX);
    // texture
    stripe.texX = (int)(wallX * player->data->wall_img[ray->hit]->width);
    if ((ray->side == 0 && ray->rayDir.x > 0) 
     || (ray->side == 1 && ray->rayDir.y < 0))
        stripe.texX = player->data->wall_img[ray->hit]->width - stripe.texX - 1;
    draw_vertical_stripe(img, player->data->wall_img[ray->hit], stripe);
}

void    raycast_and_draw(t_data *data, s_player *player)
{
    mlx_image_t *img = data->img;
    s_Ray ray;
    int x;

    x = 0;
    while (x < data->width)
    {
        init_ray(&ray, player, x, data->width);
        calculate_step_and_side_dist(&ray, player);
        if (ray.hit != -1)
        {
            DDA_loop(&ray, data);
            calculate_perp_wall_dist(&ray, player);
            draw_textured_wall(player, img, &ray, x++);
        }
    }
    mlx_image_to_window(data->mlx, img, 0, 0);
}
