
#include "../cub3d.h"

void calculate_perp_wall_dist(s_Ray *ray, s_player *player)
{
    if (ray->side == 0)
        ray->perpWallDist =
            (ray->mapX - player->pos.x + (1 - ray->stepX) / 2) / ray->rayDir.x;
    else
        ray->perpWallDist =
            (ray->mapY - player->pos.y + (1 - ray->stepY) / 2) / ray->rayDir.y;
}

// infinite if the ray is perfect hor / ver
// fabs is just an absolute function
// 1e30 is to represent infinity
static double delta(double rayDir)
{
    if (rayDir == 0)
        return 1e30;
    return fabs(1.0 / rayDir);
}

void init_ray(s_Ray *ray, s_player *player, int x, int width)
{
    double cameraX;

    cameraX = 2.0 * x / (double)width - 1.0;
    ray->rayDir.x = player->dir.x + player->plane.x * cameraX;
    ray->rayDir.y = player->dir.y + player->plane.y * cameraX;
    ray->mapX = (int)player->pos.x;
    ray->mapY = (int)player->pos.y;
    ray->deltaDist.x = delta(ray->rayDir.x);
    ray->deltaDist.y = delta(ray->rayDir.y);
}
