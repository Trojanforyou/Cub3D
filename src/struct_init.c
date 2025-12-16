/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:42:06 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/14 14:26:21 by msokolov         ###   ########.fr       */
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
    // data->wall[0] = NULL;
    // data->wall[1] = NULL;
    // data->wall[2] = NULL;
    // data->wall[3] = NULL;
}

void player_init(s_player *player)
{
    player->posX = 22.0;
    player->posY = 12.0;
    player->dirX = -1.0;
    player->dirY = 0.0;
    player->planeX = 0.0;
    player->planeY = 0.66;
}