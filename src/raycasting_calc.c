
#include "../cub3d.h"

void    DDA_loop(s_Ray *ray, t_data *data)
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
        if (ray->mapX < 0 || ray->mapX >= (data->width - 1)
         || ray->mapY < 0 || ray->mapY >= (data->height - 1))
        {
            ray->hit = -1;
            return;
        }
        if (data->map[ray->mapY][ray->mapX] != '0')
            ray->hit = data->map[ray->mapY][ray->mapX] - '0';
    }
}

void calculate_step_and_side_dist(s_Ray *ray, s_player *player)
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
