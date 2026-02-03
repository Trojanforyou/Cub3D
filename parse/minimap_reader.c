/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:51:42 by msokolov          #+#    #+#             */
/*   Updated: 2026/02/03 13:47:46 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	set_minimap_img(t_data *data)
{
	data->minimap_i = mlx_new_image(data->mlx, get_map_width(data->map)
			* MINIMAP_SIZE, get_map_height(data->map) * MINIMAP_SIZE);
	if (!data->minimap_i)
		return (printf("Image was not created\n"), false);
	return (true);
}

bool	draw_minimap(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	set_collor(data, y, x);
	if (mlx_image_to_window(data->mlx, data->minimap_i,
			OFFSET_X, OFFSET_Y) < false)
		return (false);
	return (true);
}

bool	put_pixel(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SIZE -1)
	{
		j = 0;
		while (j < MINIMAP_SIZE - 1)
		{
			mlx_put_pixel(data->minimap_i, x
				* MINIMAP_SIZE + i, y * MINIMAP_SIZE + j, color);
			j++;
		}
		i++;
	}
	return (true);
}
