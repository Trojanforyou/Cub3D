/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_t_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:51:42 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/21 12:17:53 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool    minimap_textures(t_data *data)
{
    data->minimap_t[0] =  mlx_load_png("./textures/minimap_t_floor.png");
    data->minimap_t[1] =  mlx_load_png("./textures/minimap_t_player.png");
    data->minimap_t[2] =  mlx_load_png("./textures/minimap_t_wall.png");
    if (!data->minimap_t[0] || !data->minimap_t[1] || data->minimap_t[2])
        return(false);
    return(true);
}
bool    minimap_image(t_data *data)
{
    data->minimap_i[0] = mlx_texture_to_image(data->mlx, data->minimap_t[0]);
    data->minimap_i[1] = mlx_texture_to_image(data->mlx, data->minimap_t[1]);
    data->minimap_i[2] = mlx_texture_to_image(data->mlx, data->minimap_t[2]);
    if (!data->minimap_i[0] || !data->minimap_i[1] || data->minimap_i[2])
        return(false);
    return(true);
}
bool    draw_minimap(t_data *data)
{
    int y;
    int x;

    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == '1')
                mlx_image_to_window(data->mlx, data->minimap_i[2], x, y);
            if (data->map[y][x] == '0')
                mlx_image_to_window(data->mlx, data->minimap_i[0], x, y);
            if (data->map[y][x] == 'P')
                mlx_image_to_window(data->mlx, data->minimap_i[1], x, y);
            x++;
        }
        y++;
    }
    return(true);
}

