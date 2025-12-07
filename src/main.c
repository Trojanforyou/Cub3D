/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:17:09 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/07 18:15:12 by msokolov         ###   ########.fr       */
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
	if (!color_set(av[1], &data))
		printf("%s", av[1]);
	cordinates_check(av[1], &data);
	map_validation(&data);
	map_char_check(&data); 
	if (!dublicate_check(&data))
		printf("lesgoon");
	map_witdh_check(&data);
	wall_height_check(&data);
}
