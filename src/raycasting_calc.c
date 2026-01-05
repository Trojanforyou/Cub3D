
#include "../cub3d.h"

void    DDA_loop(s_Ray *ray, t_data *data)
{
    ray->hit = 0;

    while (ray->hit == 0)
    {
        if (ray->sideDist.x < ray->sideDist.y)
        {
            ray->sideDist.x += ray->deltaDist.x;
            ray->mapX += ray->stepX;
            ray->side = 0;
        }
        else
        {
            ray->sideDist.y += ray->deltaDist.y;
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
    if (ray->rayDir.x < 0)
    {
        ray->stepX = -1;
        ray->sideDist.x = (player->pos.x - ray->mapX) * ray->deltaDist.x;
    }
    else
    {
        ray->stepX = 1;
        ray->sideDist.x = (ray->mapX + 1.0 - player->pos.x) * ray->deltaDist.x;
    }
    if (ray->rayDir.y < 0)
    {
        ray->stepY = -1;
        ray->sideDist.y = (player->pos.y - ray->mapY) * ray->deltaDist.y;
    }
    else
    {
        ray->stepY = 1;
        ray->sideDist.y = (ray->mapY + 1.0 - player->pos.y) * ray->deltaDist.y;
    }
}
