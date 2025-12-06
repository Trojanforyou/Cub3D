/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:54:26 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/06 12:06:28 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	map_char_check(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == ' ')
				x++;
			else
				return(printf("Map has non valid characters\n"), -1);
		}
		y++;
	}
	return(0);
}
