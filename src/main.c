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
    player_init(player);
    if (!game_init(&data))
        return (printf("Game init failed\n"), 1);

    mlx_key_hook(data.mlx, &move_forward, player);
    raycast_and_draw(&data, player);
    mlx_loop(data.mlx);
    free(data.map);
    free(player);
}