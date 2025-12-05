/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:17:09 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/06 00:01:25 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int main(int ac, char **av)
{
	char	**map;
	
	map = NULL;
	if (ac < 2)
		return (printf("Program requires MORE than 2 arguments\n"), 1);
	if (prefix_check(av[1]))
		return(1);
	map = cordinates_check(av[1]);
	if (!dublicate_check(map))
		printf("lesgoo\n");
	wall_check(map);
	map_validation(map);
}
