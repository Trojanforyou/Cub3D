/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhan <orhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:32:09 by otanovic          #+#    #+#             */
/*   Updated: 2026/02/12 13:20:10 by orhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_perp_wall_dist(t_ray *ray, t_player *player)
{
if (ray->side == 0)
    ray->perpwalldist = (ray->map.x - player->pos.x + (1 - ray->step.x) / 2) / ray->raydir.x;
else
    ray->perpwalldist = (ray->map.y - player->pos.y + (1 - ray->step.y) / 2) / ray->raydir.y;

}

static double	delta(double raydir)
{
	if (raydir == 0)
		return (1e30);
	return (fabs(1.0 / raydir));
}

void	init_ray(t_ray *ray, t_player *player, int x, int width)
{
	double	camera_x;

	ray->hit = -1;
	ray->side = 0;
	camera_x = 2.0 * x / (double)width - 1.0;
	ray->raydir.x = player->dir.x + player->plane.x * camera_x;
	ray->raydir.y = player->dir.y + player->plane.y * camera_x;
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
	ray->deltadist.x = delta(ray->raydir.x);
	ray->deltadist.y = delta(ray->raydir.y);
	ray->sidedist.x = 0.0;
	ray->sidedist.y = 0.0;
}
