/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:47:46 by otanovic          #+#    #+#             */
/*   Updated: 2026/02/11 10:50:26 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	face_from_ray(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->raydir.x > 0)
			return (3);
		else
			return (1);
	}
	if (ray->raydir.y > 0)
		return (0);
	else
		return (2);
}

void	dda_loop(t_ray *ray, t_data *data)
{
	ray->hit = -1;
	while (ray->hit == -1)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (ray->map.y < 0 || ray->map.y >= data->height
			|| ray->map.x < 0 || ray->map.x >= data->width
			|| !data->map || !data->map[ray->map.y])
			return ;
		if (data->map[ray->map.y][ray->map.x] == 'D')
			ray->hit = 4;
		if (data->map[ray->map.y][ray->map.x] != '0')
			ray->hit = face_from_ray(ray);
	}
}

void	calculate_step_and_side_dist(t_ray *ray, t_player *player)
{
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (player->pos.x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - player->pos.x) * ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (player->pos.y - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - player->pos.y) * ray->deltadist.y;
	}
}
