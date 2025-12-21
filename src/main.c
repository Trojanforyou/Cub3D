/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:17:09 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/19 17:57:35 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (printf("Program requires MORE than 2 arguments\n"), 1);
	if (prefix_check(av[1]))
		return(1);
	data_init(&data);
	if (!map_reader(av[1], &data))
		return(-1);
	if(map_init(&data) == false)
		return(-1);
	if (game_init(&data) == false)
		return(false);
	free(data.map);
}
