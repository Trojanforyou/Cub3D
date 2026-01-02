/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:54:03 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/14 15:40:09 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

bool game_init(t_data *data)
{
    data->height = get_map_height(data->map) * TITLE_SIZE;
    data->width = get_map_width((data->map)) * TITLE_SIZE;
    data->mlx = mlx_init(data->width, data->height, "cub3D", false);
    data->screen_width = data->width;
    data->render_width = data->width;
    if (!data->mlx)
        return (free(data->mlx), false);
    if (!texture_load(data) || !load_image(data))
        return false;
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
