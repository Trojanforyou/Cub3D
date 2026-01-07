/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:36:31 by otanovic          #+#    #+#             */
/*   Updated: 2026/01/07 17:07:20 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_free_tile(t_data *data, int x, int y)
{
	if (y < 0 || !data->map[y])
		return (0);
	if (x < 0 || !data->map[y][x] || data->map[y][x] == '\n')
		return (0);
	return (data->map[y][x] == '0' || data->map[y][x] == 'P');
}

void	rotate_camera(s_player *p, double rot)
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
	if (is_free_tile(data, (int)(data->player->pos.x + move[0]), (int)data->player->pos.y))
		data->player->pos.x += move[0];
	if (is_free_tile(data, (int)data->player->pos.x, (int)(data->player->pos.y + move[1])))
		data->player->pos.y += move[1];
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

void mouse_look(t_data *data)
{
	int		x;
	int		y;
	int		cx;
	double	dx;

	cx = data->width / 2;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	dx = x - cx;
	if (dx > 1 || dx < -1)
		rotate_camera(data->player, dx * 0.002);
	mlx_set_mouse_pos(data->mlx, cx, (data->height / 2));
}
