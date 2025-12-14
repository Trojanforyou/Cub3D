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

bool	walls_set(char *filename, t_data *data)
{
    int		fd;
    char	*line;

    fd = open(filename, O_RDONLY);
    if (fd  < 0)
        return(printf("file descriptor failed\n"), false);
    while ((line = get_next_line(fd)))
    {
        if (!line)
            return(printf("path failed\n"), false);
        set_no_so_walls(data, line);
        set_we_ea_walls(data, line);
    }
    close(fd);
    return(true);
}
bool texture_load(t_data *data)
{
    data->wall[0] = mlx_load_png(data->no);
    data->wall[1] = mlx_load_png(data->so);
    data->wall[2] = mlx_load_png(data->we);
    data->wall[3] = mlx_load_png(data->ea);
    if (!data->wall[0] || !data->wall[1] || !data->wall[2] || !data->wall[3])
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
    return true;}

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
            if (data->map[y][x] == '1')
                if (data->wall_img[1])
                    mlx_image_to_window(data->mlx, data->wall_img[1], x * TITLE_SIZE, y * TITLE_SIZE);
                // if (data->map[y][x] == '0')
                //     mlx_image_to_window(data->mlx, data->floor, x, y);
        }
    }
    return(true);
}
