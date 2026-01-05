
#include "../cub3d.h"

void DDA_loop(s_Ray *ray, t_data *data)
{
    ray->hit = 0;
    while (ray->hit == 0)
    {
        if (ray->sideDist.x < ray->sideDist.y)
        {
            ray->sideDist.x += ray->deltaDist.x;
            ray->map.x += ray->step.x;
            ray->side = 0;
        }
        else
        {
            ray->sideDist.y += ray->deltaDist.y;
            ray->map.y += ray->step.y;
            ray->side = 1;
        }
        if (ray->map.y < 0 || ray->map.y >= data->height
         || ray->map.x < 0 || ray->map.x >= data->width
         || !data->map || !data->map[ray->map.y])
        {
            ray->hit = -1;
            return;
        }
        if (data->map[ray->map.y][ray->map.x] != '0')
            ray->hit = data->map[ray->map.y][ray->map.x] - '0';
    }
}

void calculate_step_and_side_dist(s_Ray *ray, s_player *player)
{
    if (ray->rayDir.x < 0)
    {
        ray->step.x = -1;
        ray->sideDist.x = (player->pos.x - ray->map.x) * ray->deltaDist.x;
    }
    else
    {
        ray->step.x = 1;
        ray->sideDist.x = (ray->map.x + 1.0 - player->pos.x) * ray->deltaDist.x;
    }
    if (ray->rayDir.y < 0)
    {
        ray->step.y = -1;
        ray->sideDist.y = (player->pos.y - ray->map.y) * ray->deltaDist.y;
    }
    else
    {
        ray->step.y = 1;
        ray->sideDist.y = (ray->map.y + 1.0 - player->pos.y) * ray->deltaDist.y;
    }
}
