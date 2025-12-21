/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:54:03 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/21 23:30:00 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool game_init(t_data *data)
{
    data->height = get_map_height(data->map);
    data->witdh = get_map_width(data->map);
    data->mlx = mlx_init(MAP_WITDH, MAP_HEIGHT, "cub3D", false);
    if (!data->mlx)
        return (free(data->mlx), false);
    // if (texture_load(data) == false || load_image(data) == false)
    //     return (false);
    set_minimap_img(data);
    // load_map(data);
    if (draw_minimap(data) == false)
        return(printf("here\n"), false);
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
