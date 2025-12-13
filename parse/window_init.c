/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:54:03 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/13 22:24:22 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool game_init(t_data *data)
{
    data->height = get_map_height(data->map);
    data->witdh = ft_strlen(*(data->map));
    data->mlx = mlx_init(data->witdh, data->height, "cub3D", false);
    if (!data->mlx)
        return (free(data->mlx), false);
    if (!texture_load(data) || !load_image(data))
        return false;
    load_map(data);
    return true;
}
// bool    load_textures(t_data *data)
// {
//     int x;
//     int y;

//     y = -1;
//     while (data->map[++y])
//     {
//         x = -1;
//         while (data->map[y][x])
//         {
//             if (data->floor)
//         }
//     }
//     re
// }