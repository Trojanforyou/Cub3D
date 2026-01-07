/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otanovic <otanovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:32:09 by otanovic          #+#    #+#             */
/*   Updated: 2026/01/07 13:36:27 by otanovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_perp_wall_dist(s_Ray *ray, s_player *player)
{
	if (ray->side == 0)
		ray->perpWallDist = 
			(ray->map.x - player->pos.x + 
				(1 - ray->step.x) / 2) / ray->rayDir.x;
	else
		ray->perpWallDist = 
			(ray->map.y - player->pos.y + 
				(1 - ray->step.y) / 2) / ray->rayDir.y;
}

// infinite if the ray is perfect hor / ver
// fabs is just an absolute function
// 1e30 is to represent infinity
static double	delta(double rayDir)
{
	if (rayDir == 0)
		return (1e30);
	return (fabs(1.0 / rayDir));
}

void	init_ray(s_Ray *ray, s_player *player, int x, int width)
{
	double	camera_x;

	ray->hit = 0;
	ray->side = 0;
	camera_x = 2.0 * x / (double)width - 1.0;
	ray->rayDir.x = player->dir.x + player->plane.x * camera_x;
	ray->rayDir.y = player->dir.y + player->plane.y * camera_x;
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
	ray->deltaDist.x = delta(ray->rayDir.x);
	ray->deltaDist.y = delta(ray->rayDir.y);
	ray->sideDist.x = 0.0;
	ray->sideDist.y = 0.0;
}
