/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:12:40 by msokolov          #+#    #+#             */
/*   Updated: 2026/01/29 00:11:51 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	find_door(t_data *data)
{
	int	y;
	int	x;

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
				return;
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
	
	y = data->door_y;
	x = data->door_x;
	if (data->map[(int)player->pos.y - 1][(int)player->pos.x] == data->map[y][x] && mlx_is_key_down(data->mlx, MLX_KEY_E)
	&& data->door_flag == 0)
		data->map[y][x]= '0';
	else if (data->map[(int)player->pos.y + 1][(int)player->pos.x] == data->map[y][x]  && mlx_is_key_down(data->mlx, MLX_KEY_E) 
	&& data->door_flag == 0)
		data->map[y][x]= '0';
	else if (data->map[(int)player->pos.y][(int)player->pos.x - 1] == data->map[y][x]  && mlx_is_key_down(data->mlx, MLX_KEY_E)
	&& data->door_flag == 0)
		data->map[y][x]= '0';
	else if (data->map[(int)player->pos.y][(int)player->pos.x + 1] == data->map[y][x]  && mlx_is_key_down(data->mlx, MLX_KEY_E)
	&& data->door_flag == 0)
		data->map[y][x]= '0';
	data->door_flag = 1;
}
static void	close_the_door(t_data *data, s_player *player)
{
	int	y;
	int	x;
	
	y = data->door_y;
	x = data->door_x;
	if (data->map[(int)player->pos.y - 1][(int)player->pos.x] == data->map[y][x]&& mlx_is_key_down(data->mlx, MLX_KEY_E)
	&& data->door_flag == 1)
		data->map[y][x]= 'D';
	else if (data->map[(int)player->pos.y + 1][(int)player->pos.x] == data->map[y][x] && mlx_is_key_down(data->mlx, MLX_KEY_E) 
	&& data->door_flag == 1)
		data->map[y][x]= 'D';
	else if (data->map[(int)player->pos.y][(int)player->pos.x - 1] == data->map[y][x] && mlx_is_key_down(data->mlx, MLX_KEY_E)
	&& data->door_flag == 1)
		data->map[y][x]= 'D';
	else if (data->map[(int)player->pos.y][(int)player->pos.x + 1] == data->map[y][x] && mlx_is_key_down(data->mlx, MLX_KEY_E)
	&& data->door_flag == 1)
		data->map[y][x]= 'D';
	data->door_flag = 0;
}
void	door(t_data *data, s_player *player)
{
	find_door(data);
	open_the_door(data, player);
	close_the_door(data, player);
}