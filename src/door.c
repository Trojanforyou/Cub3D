/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:12:40 by msokolov          #+#    #+#             */
/*   Updated: 2026/01/28 17:20:11 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	open_the_door(t_data *data, s_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[(int)player->pos.y - 1][(int)player->pos.x] == 'D' && mlx_is_key_down(data->mlx, MLX_KEY_E))
				data->map[(int)player->pos.y - 1][(int)player->pos.x] = '0';
			else if (data->map[(int)player->pos.y + 1][(int)player->pos.x] == 'D' && mlx_is_key_down(data->mlx, MLX_KEY_E))
				data->map[(int)player->pos.y + 1][(int)player->pos.x] = '0';
			else if (data->map[(int)player->pos.y][(int)player->pos.x - 1] == 'D' && mlx_is_key_down(data->mlx, MLX_KEY_E))
				data->map[(int)player->pos.y][(int)player->pos.x - 1] = '0';
			else if (data->map[(int)player->pos.y][(int)player->pos.x + 1] == 'D' && mlx_is_key_down(data->mlx, MLX_KEY_E))
				data->map[(int)player->pos.y][(int)player->pos.x + 1] = '0';
			x++;
		}
		y++;
	}
}
