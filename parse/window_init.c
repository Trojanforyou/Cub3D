/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:54:03 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/21 12:54:23 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool game_init(t_data *data)
{
    data->height = MAP_HEIGHT;
    data->witdh = MAP_WITDH;
    data->mlx = mlx_init(data->witdh, data->height, "cub3D", false);
    if (!data->mlx)
        return (free(data->mlx), false);
    if (texture_load(data) == false || load_image(data) == false)
        return (false);
    // if (minimap_textures(data) == false || minimap_image(data) == false)
    //     return(false);
    // if (draw_minimap(data) == false)
    //     return(false);
    load_map(data);
    mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
    return true;
}
int get_map_width(char  **str)
{
    int y;
    int x;

    y = 0;
    while (str[y])
    {
        x = 0;
        while (str[y][x])
            x++;
        y++;
    }
    return(x);
}
