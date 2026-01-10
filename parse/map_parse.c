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
			if (data->map[y][x] == '1' || data->map[y][x] == '0' || data->map[y][x] == 'P' || data->map[y][x] == ' ' || data->map[y][x] == '\n')
				x++;
			else
				return(printf("Map has non valid CHARS\n"), -1);
		}
		y++;
	}
	return(0);
}
bool	collums_check(t_data *data)
{
	int	x;
	int	y;
	// int	heigth;

	data->width = get_map_width(data->map);
	// heigth = get_map_height(data->map);
	x = 0;
	while (x < data->width)
	{
		y = 0;
		while (data->map[y])
		{
			if (x >= (int)ft_strlen(data->map[y]))
            {
                y++;
                continue;
            }
			if (data->map[y][x] == ' ')
			{
				if (data->map[y + 1] && (data->map[y + 1][x] == 'P' || data->map[y + 1][x] == '0'))
					return(printf("here"), false);
			}
			else if (data->map[y][x] == '\n')
				if (data->map[y + 1] && (data->map[y + 1][x] == 'P' || data->map[y + 1][x] == '0'))
					return(printf("here"), false);

			y++;
		}
		x++;
	}
	return(true);
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
