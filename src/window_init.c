/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:54:03 by msokolov          #+#    #+#             */
/*   Updated: 2026/01/07 17:18:27 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool game_init(t_data *data, s_player *player)
{
    data->height = get_map_height(data->map);
    data->width = get_map_width(data->map);
    printf("Initializing MLX...\n");
    data->mlx = mlx_init(MAP_WITDH, MAP_HEIGHT, "cub3D", false);
    if (!data->mlx)
        return (printf("MLX init failed\n"), false);
    printf("Loading textures...\n");
    if (texture_load(data) == false || load_image(data) == false)
        return (printf("Texture loading failed\n"), false);
    printf("Setting minimap image...\n");
    if (set_minimap_img(data) == false)
        return(false);
    printf("Drawing minimap...\n");
    printf("Creating main image...\n");
    data->player = player;
	data->img = mlx_new_image(data->mlx, MAP_WITDH, MAP_HEIGHT);
	if (!data->img)
		return (printf("Failed to create image\n"), 1);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		return (printf("Failed to add image to window\n"), 1);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free(data->map);
	free(player);
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
