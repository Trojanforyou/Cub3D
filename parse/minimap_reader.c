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

bool    set_minimap_img(t_data *data)
{
    data->minimap_i = mlx_new_image(data->mlx, get_map_width(data->map) * MINIMAP_SIZE, get_map_height(data->map) * MINIMAP_SIZE);
    if (!data->minimap_i)
        return(printf("Image was not created\n"), false);
    return(true);

}
bool draw_minimap(t_data *data)
{
    int y;
    int x;
    int color;

    y = 0;
    color = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == '0')
                color = 0x654321FF; // Hex (RGBA / 0xRRGGBBAA):
            else if (data->map[y][x] == '1')
                color = 0x000000FF; // Hex (RGBA / 0xRRGGBBAA):
            else if (data->map[y][x] == 'P')
                color = 0xFF0000FF; // Hex (RGBA / 0xRRGGBBAA):
            else
            {
                x++;
                continue;
            }
            put_pixel(data, x, y, color);
            x++;
        }
        y++;
    }
    if (mlx_image_to_window(data->mlx, data->minimap_i, OFFSET_X, OFFSET_Y) < false)
        return(false);
    return true;
}
bool    put_pixel(t_data *data, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    while (i < MINIMAP_SIZE -1)
    {
        j = 0;
        while (j < MINIMAP_SIZE - 1)
        {
            mlx_put_pixel(data->minimap_i, x * MINIMAP_SIZE + i, y * MINIMAP_SIZE + j, color);
            j++;
        }
        i++;
    }
    return(true);
}

