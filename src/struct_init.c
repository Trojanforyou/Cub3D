/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:42:06 by msokolov          #+#    #+#             */
/*   Updated: 2026/01/10 21:24:29 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    data_init(t_data *data)
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
	data->minimap_i = NULL;
}

int player_init(s_player *player, t_data *data)
{
    player->pos.x = 22.0;
    player->pos.y = 12.0;
    player->dir.x = -1.0;
    player->dir.y = 0.0;
    player->plane.x = 0.0;
    player->plane.y = 0.66;
    player->data = data;
    player->speed = 0.1;
    return (1);
}