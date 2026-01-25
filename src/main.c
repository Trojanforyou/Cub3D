/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:17:09 by msokolov          #+#    #+#             */
/*   Updated: 2026/01/17 13:14:55 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	clear_screen(t_data *data)
{
	size_t	size;

	if (!data || !data->img || !data->img->pixels)
		return ;
	size = (size_t)data->img->width * (size_t)data->img->height * 4;
	memset(data->img->pixels, 0, size);
}

void	game_loop(void *param)
{
	t_data	*data;

	data = param;
	move_player(data);
	mouse_look(data);
	arrow_look(data);
	clear_screen(data);
	raycast_and_draw(data, data->player);
	draw_minimap(data);
}
void	find_player(t_data *data, s_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				player->pos.x = x;
				player->pos.y = y;
			}
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	s_player	*player;

	player = malloc(sizeof(s_player));
	if (!player)
		return (printf("Failed to allocate memory for player\n"), 1);
	if (ac < 2)
		return (printf("Program requires MORE than 2 arguments\n"), 1);
	if (prefix_check(av[1]))
		return (-1);
	data_init(&data);
	if (!map_reader(av[1], &data))
		return(free(player), clean_data(&data), -1);
	if(!map_init(&data))
		return(free(player), clean_data(&data), -1);
	find_player(&data, player);
	if (!player_init(player, &data))
		return (free(player), -1);
	if (!game_init(&data, player))
		return (printf("Game init failed\n"), -1);
	clean_data(&data);
	free(player);
	// clean_ceiling(&data);
	return 0;
}
