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

bool texture_load(t_data *texture)
{
    texture->wall[0] = mlx_load_png("./textures/northwall.png");
    texture->wall[1] = mlx_load_png("./textures/southwall.png");
    texture->wall[2] = mlx_load_png("./textures/westwall.png");
    texture->wall[3] = mlx_load_png("./textures/eastwall.png");
    if (!texture->wall[0] || !texture->wall[1] || !texture->wall[2] || !texture->wall[3])
        return (printf("Texture load error\n"), false);
    return true;
}
bool load_image(t_data *texture)
{
    texture->wall_img[0] = mlx_texture_to_image(texture->mlx, texture->wall[0]);
    texture->wall_img[1] = mlx_texture_to_image(texture->mlx, texture->wall[1]);
    texture->wall_img[2] = mlx_texture_to_image(texture->mlx, texture->wall[2]);
    texture->wall_img[3] = mlx_texture_to_image(texture->mlx, texture->wall[3]);
    if (!texture->wall_img[0] || !texture->wall_img[1] || !texture->wall_img[2] || !texture->wall_img[3])
        return (printf("Image load error\n"), false);
    mlx_delete_texture(texture->wall[0]);
    mlx_delete_texture(texture->wall[1]);
    mlx_delete_texture(texture->wall[2]);
    mlx_delete_texture(texture->wall[3]);
    return true;
}
bool     load_map(t_data *data)
{
    int y;
    int x;

    y = -1;
    while (data->map[++y])
    {
        x = -1;
        while (data->map[y][++x])
        {
            if (data->map[y][x] == '0')
                if (data->wall_img[1])
                    mlx_image_to_window(data->mlx, data->wall_img[1], x * TITLE_SIZE, y * TITLE_SIZE);
        }
    }
    return(true);
}
