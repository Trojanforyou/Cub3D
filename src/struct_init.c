/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:42:06 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/21 23:32:43 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    data_init(t_data *data)
{
    data->map = NULL;
    data->floor = 0;
    data->ceiling = 0;
    data->height = 0;
    data->witdh = 0;
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
