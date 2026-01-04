
#include "../cub3d.h"

void calculate_perp_wall_dist(s_Ray *ray, s_player *player)
{
    if (ray->side == 0)
        ray->perpWallDist =
            (ray->mapX - player->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
    else
        ray->perpWallDist =
            (ray->mapY - player->posY + (1 - ray->stepY) / 2) / ray->rayDirY;
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
    ray->rayDirX = player->dirX + player->planeX * cameraX;
    ray->rayDirY = player->dirY + player->planeY * cameraX;
    ray->mapX = (int)player->posX;
    ray->mapY = (int)player->posY;
    ray->deltaDistX = delta(ray->rayDirX);
    ray->deltaDistY = delta(ray->rayDirY);
}
