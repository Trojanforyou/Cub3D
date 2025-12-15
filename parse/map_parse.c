/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data->map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:54:26 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/06 13:25:33 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	map_char_check(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			printf("%c", data->map[y][x]);
			if (data->map[y][x] == '1' || data->map[y][x] == '0' || data->map[y][x] == 'P' || data->map[y][x] == ' ' || data->map[y][x] == '\n')
				x++;
			else
				return(printf("Map has non valid CHARS\n"), -1);
		}
		y++;
	}
	return(0);
}
char wall_height_check(t_data *data)
{
	int	y;
	int	len;
	int	x;

	x = 0;
	len = 0;
	y = 0;
	len = get_map_height(data->map) - 1;
	while (data->map[x][0] != ' ' && data->map[x][0] != '0' && data->map[x][0] != '1' && data->map[x][0] != 'P')
		x++;
	if (data->map[x][0] == '0' || data->map[x][0] == 'P')
		return (printf("not here\n"), -1);
	while (data->map[len][y])
	{
		if (data->map[len][y] == '0' || data->map[len][y] == 'P')
			return (printf("nope"), -1);
		y++;
	}
	return(0);
}
char map_witdh_check(t_data *data)
{
    int x;

	x = 0;

	while (data->map[0][x])
	{
		printf("%c\n", data->map[0][x]);
		if (data->map[0][x] == '0')
			return(printf("here1"), -1);
		x++;
	}
	return(0);
}
char map_validation(t_data *data)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if ((data->map[y][x] == ' '))
			{
				if (map_right_check(data, x, y) == false)
					return(-1);
				if (map_down_check(data, x, y) == false)
					return(-1);
				if (map_left_check(data, x, y) == false)
					return(-1);
				if (map_up_check(data, x, y) == false)
					return (-1);
			}
			if (island_check(data, y, x) == false)
				return(-1);
		}
	}
	return(0);
}
