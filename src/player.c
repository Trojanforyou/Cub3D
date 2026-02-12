/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhan <orhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:36:31 by otanovic          #+#    #+#             */
/*   Updated: 2026/02/12 13:20:26 by orhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_free_tile(t_data *data, double x, double y)
{
	int	tx;
	int	ty;

	tx = (int)x;
	ty = (int)y;
	if (ty < 0 || !data->map[ty])
		return (0);
	if (tx < 0 || !data->map[ty][tx] || data->map[ty][tx] == '\n')
		return (0);
	return (data->map[ty][tx] == '0' || data->map[ty][tx] == 'P');
}

void	rotate_camera(t_player *p, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	p->dir.x = p->dir.x * cos(rot) - p->dir.y * sin(rot);
	p->dir.y = old_dir_x * sin(rot) + p->dir.y * cos(rot);
	p->plane.x = p->plane.x * cos(rot) - p->plane.y * sin(rot);
	p->plane.y = old_plane_x * sin(rot) + p->plane.y * cos(rot);
}

void	arrow_look(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_camera(data->player, 0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_camera(data->player, -0.1);
}

void	collision_and_update(t_data *data, double *move)
{
	double new_x;
	double new_y;

	new_x = data->player->pos.x + move[0];
	new_y = data->player->pos.y + move[1];
	if (is_free_tile(data, new_x + ((move[0] > 0) ? PLAYER_COLLISION_BUFFER : -PLAYER_COLLISION_BUFFER),
			data->player->pos.y))
		data->player->pos.x = new_x;
	if (is_free_tile(data, data->player->pos.x,
			new_y + ((move[1] > 0) ? PLAYER_COLLISION_BUFFER : -PLAYER_COLLISION_BUFFER)))
		data->player->pos.y = new_y;
}


void	move_player(t_data *data)
{
	double	move[2];

	ft_bzero(move, sizeof(move));
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		move[0] += data->player->dir.x * data->player->speed;
		move[1] += data->player->dir.y * data->player->speed;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		move[0] -= data->player->dir.x * data->player->speed;
		move[1] -= data->player->dir.y * data->player->speed;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		move[0] -= data->player->dir.y * data->player->speed;
		move[1] += data->player->dir.x * data->player->speed;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		move[0] += data->player->dir.y * data->player->speed;
		move[1] -= data->player->dir.x * data->player->speed;
	}
	collision_and_update(data, move);
}
