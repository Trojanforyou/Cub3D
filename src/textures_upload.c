#define TILE_SIZE 32
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 20:43:38 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/13 22:28:42 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// fix the memory leak if texture is not correct
bool	texture_load(t_data *data)
{
	if (!data->no || !data->so || !data->we || !data->ea)
		return (printf("Texture paths not set\n"), false);
	data->wall[0] = mlx_load_png(data->no);
	data->wall[1] = mlx_load_png(data->so);
	data->wall[2] = mlx_load_png(data->we);
	data->wall[3] = mlx_load_png(data->ea);
	data->wall[4] = mlx_load_png("textures/exito.png");
	if (!data->wall[0] || !data->wall[1] || !data->wall[2] || !data->wall[3] || !data->wall[4])
		return (printf("Texture load error\n"), false);
	return (true);
}

bool	load_image(t_data *texture)
{
	texture->wall_img[0] = mlx_texture_to_image(texture->mlx, texture->wall[0]);
	texture->wall_img[1] = mlx_texture_to_image(texture->mlx, texture->wall[1]);
	texture->wall_img[2] = mlx_texture_to_image(texture->mlx, texture->wall[2]);
	texture->wall_img[3] = mlx_texture_to_image(texture->mlx, texture->wall[3]);
	texture->wall_img[4] = mlx_texture_to_image(texture->mlx, texture->wall[4]);
	if (!texture->wall_img[0] || !texture->wall_img[1] || !texture->wall_img[2]
		|| !texture->wall_img[3] || !texture->wall_img[4])
		return (printf("Image load error\n"), false);
	mlx_delete_texture(texture->wall[0]);
	mlx_delete_texture(texture->wall[1]);
	mlx_delete_texture(texture->wall[2]);
	mlx_delete_texture(texture->wall[3]);
	mlx_delete_texture(texture->wall[4]);
	return (true);
}

bool	load_map(t_data *data)
{
	int	y;
	int	x;

	data->img = mlx_new_image(data->mlx, data->width * TITLE_SIZE, data->height * TITLE_SIZE);
	y = -1;
	while (data->map[++y])
	{
	    x = -1;
	    while (data->map[y][++x])
	    {
			if (data->map[y][x] == '1')
			{
				if (data->wall_img[1])
					mlx_image_to_window(data->mlx, data->wall_img[1], x * TITLE_SIZE, y * TITLE_SIZE);
			}
			else if (data->map[y][x] == '0')
			{
				for (int i = 0; i < TITLE_SIZE; i++)
					for (int j = 0; j < TITLE_SIZE; j++)
						mlx_put_pixel(data->img, x * TITLE_SIZE + i, y * TITLE_SIZE + j, data->floor);
			}
		}
	}
	//     if (!data->mlx) { printf("mlx is NULL\\n"); return false; }
	// if (!data->img) { printf("img is NULL\\n"); return false; }
	mlx_image_to_window(data->mlx, data->img, x - 25, y -25);
	return (true);
}
