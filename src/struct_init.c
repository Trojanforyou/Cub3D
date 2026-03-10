/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:42:06 by msokolov          #+#    #+#             */
/*   Updated: 2026/03/08 12:43:48 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	data_init(t_data *data)
{
	data->map = NULL;
	data->floor = 0;
	data->ceiling = 0;
	data->height = 0;
	data->width = 0;
	data->so = 0;
	data->no = 0;
	data->ea = 0;
	data->we = 0;
	data->n_flag = 0;
	data->tmp_ceiling = NULL;
	data->tmp_floor = NULL;
	data->img = 0;
	data->we_flag = 0;
	data->ea_flag = 0;
	data->no_flag = 0;
	data->so_flag = 0;
	data->door_count = 0;
	data->door_flag = -1;
	data->key_e_was_pressed = 0;
	data->door_y = 0;
	data->ceiling_flag = 0;
	data->floor_flag = 0;
	data->door_x = 0;
	data->minimap_i = NULL;
}

static void	player_direction(t_player *player, t_data *data)
{
	if (data->player_dir == 'S')
	{
		player->dir.x = 0.0;
		player->dir.y = 1.0;
		player->plane.x = -0.5;
		player->plane.y = 0.0;
	}
	else if (data->player_dir == 'E')
	{
		player->dir.x = 1.0;
		player->dir.y = 0.0;
		player->plane.x = 0.0;
		player->plane.y = -0.5;
	}
	else if (data->player_dir == 'W')
	{
		player->dir.x = -1.0;
		player->dir.y = 0.0;
		player->plane.x = 0.0;
		player->plane.y = 0.5;
	}
}

int	player_init(t_player *player, t_data *data)
{
	if (data && data->player_dir)
	{
		if (data->player_dir == 'N')
		{
			player->dir.x = 0.0;
			player->dir.y = -1.0;
			player->plane.x = 0.5;
			player->plane.y = 0.0;
		}
		player_direction(player, data);
	}
	player->data = data;
	player->speed = 0.1;
	return (1);
}
