/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:12:40 by msokolov          #+#    #+#             */
/*   Updated: 2026/02/03 15:43:14 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_door(t_data *data)
{
	int		y;
	int		x;

	if (data->door_flag == 0 || data->door_flag == 1)
		return ;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'D')
			{
				data->door_y = y;
				data->door_x = x;
				data->door_flag = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	open_the_door(t_data *data, s_player *player)
{
	int	y;
	int	x;
	int	px;
	int	py;

	y = data->door_y;
	x = data->door_x;
	px = (int)player->pos.x;
	py = (int)player->pos.y;
	if (((py - 1 == y && px == x) || (py + 1 == y && px == x)
			|| (px - 1 == x && py == y) || (px + 1 == x && py == y)))
	{
		data->door_flag = 1;
		data->map[y][x] = '0';
		return ;
	}
}

static void	close_the_door(t_data *data, s_player *player)
{
	int	y;
	int	x;
	int	px;
	int	py;

	y = data->door_y;
	x = data->door_x;
	px = (int)player->pos.x;
	py = (int)player->pos.y;
	if (((py - 1 == y && px == x) || (py + 1 == y && px == x)
			|| (px - 1 == x && py == y) || (px + 1 == x && py == y)))
	{
		data->door_flag = 0;
		data->map[y][x] = 'D';
		return ;
	}
}

void	door(t_data *data, s_player *player)
{
	int	key_is_pressed;

	key_is_pressed = mlx_is_key_down(data->mlx, MLX_KEY_E);
	if (key_is_pressed && !data->key_e_was_pressed)
	{
		if (data->door_flag == 0)
			open_the_door(data, player);
		else if (data->door_flag == 1)
			close_the_door(data, player);
	}
	data->key_e_was_pressed = key_is_pressed;
}
