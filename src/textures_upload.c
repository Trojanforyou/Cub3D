/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_upload.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 20:43:38 by msokolov          #+#    #+#             */
/*   Updated: 2026/02/03 15:44:17 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	texture_load(t_data *data)
{
	if (!data->no || !data->so || !data->we || !data->ea)
		return (printf("Texture paths not set\n"), false);
	data->wall[0] = mlx_load_png(data->no);
	data->wall[1] = mlx_load_png(data->so);
	data->wall[2] = mlx_load_png(data->we);
	data->wall[3] = mlx_load_png(data->ea);
	data->wall[4] = mlx_load_png("textures/exito.png");
	if (!data->wall[0] || !data->wall[1] || !data->wall[2]
		|| !data->wall[3] || !data->wall[4])
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
