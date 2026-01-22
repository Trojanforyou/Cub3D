/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:54:03 by msokolov          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/09 14:54:45 by msokolov         ###   ########.fr       */
=======
/*   Updated: 2026/01/10 22:04:21 by msokolov         ###   ########.fr       */
>>>>>>> origin
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
<<<<<<< HEAD
#include <math.h>

<<<<<<<< HEAD:src/window_init.c
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
=======

bool game_init(t_data *data, s_player *player )
{
    data->height = get_map_height(data->map);
    data->width = get_map_width(data->map);
    data->mlx = mlx_init(MAP_WITDH, MAP_HEIGHT, "cub3D", false);
    if (!data->mlx)
        return (printf("MLX init failed\n"), false);
    if (texture_load(data) == false || load_image(data) == false)
        return (printf("Texture loading failed\n"), false);
    if (set_minimap_img(data) == false)
        return(false);
    data->player = player;
	data->img = mlx_new_image(data->mlx, MAP_WITDH, MAP_HEIGHT);
	if (!data->img)
		return (printf("Failed to create image\n"), 1);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		return (printf("Failed to add image to window\n"), 1);
    change_perspective(data);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
>>>>>>> origin
    return true;
}

int get_map_width(char  **str)
{
    int y;
    int x;
<<<<<<< HEAD
========
// int get_map_width(char  **str)
// {
//     int y;
//     int x;

//     y = 0;

//     while (str[y])
//     {
//         if (str[y][0] == '\0')
//         {
//             y++;
//             continue;
//         }
//         x = 0;
//         while (str[y][x])
//             x++;
//         y++;
//     }
//     return(x);
// }
>>>>>>>> origin:parse/window_init.c

=======

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
>>>>>>> origin
