/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:17:09 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/14 15:37:36 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void clear_screen(t_data *data)
{
    size_t  size;

    if (!data || !data->img || !data->img->pixels)
        return;

    size = (size_t)data->img->width * (size_t)data->img->height * 4;
    memset(data->img->pixels, 0, size);
}

void game_loop(void *param)
{
    t_data *data = param;

    move_player(data);
    mouse_look(data);
    clear_screen(data);
    raycast_and_draw(data, data->player);
}

int main(int ac, char **av)
{
    t_data	data;
    s_player *player;

    player = malloc(sizeof(s_player));
    if (!player)
        return (printf("Failed to allocate memory for player\n"), 1);
    if (ac < 2)
        return (printf("Program requires MORE than 2 arguments\n"), 1);
    if (prefix_check(av[1]))
        return(1);

    data_init(&data);
    walls_set(av[1], &data);
    color_set(av[1], &data);
    if (!cordinates_check(av[1], &data))
        return(-1);
    map_init(&data);
    player_init(player, &data);
    if (!game_init(&data))
        return (printf("Game init failed\n"), 1);
    data.player = player;
    data.img = mlx_new_image(data.mlx, data.width, data.height);
    if (!data.img)
        return (printf("Failed to create image\n"), 1);
    mlx_set_cursor_mode(data.mlx, MLX_MOUSE_DISABLED);
    mlx_loop_hook(data.mlx, game_loop, &data);
    mlx_loop(data.mlx);
    free(data.map);
    free(player);
}