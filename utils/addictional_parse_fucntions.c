/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addictional_parse_fucntions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:03:44 by msokolov          #+#    #+#             */
/*   Updated: 2026/02/13 15:13:41 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	bool	check_for_valid(t_data *data, int *y, int *flag)
{
	if ((size_t)(*flag) == ft_strlen(data->map[*y]))
	{
		(*y)++;
		if (data->map[*y] && data->map[*y][0] == '\0')
		{
			if (data->map[*y + 1])
			{
				while ((data->map[*y + 1]
						&& data->map[*y][0] == '\0') || data->map[*y][0] == ' ')
					(*y)++;
				if (ft_isprint(data->map[*y][0]) == '1' ||
				(data->map[*y - 1][0] == '\0'
					&& data->map[*y - 2][0] == '1' && data->map[*y][0] == '1'))
					return (printf("Input is NOT valid\n"), false);
			}
		}
		else if (!data->map[*y - 1])
			return (true);
	}
	return (true);
}

bool	map_y_check(t_data *data)
{
	int	y;
	int	x;
	int	flag;

	flag = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y] && data->map[y][x])
		{
			if (data->map[y][x] == '1')
				flag++;
			if (data->map[y][x] == '0' || data->map[y][x] == 'P')
				flag = 0;
			if (check_for_valid(data, &y, &flag) == false)
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	map_x_check(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == ' ')
			{
				while (data->map[y][x] == ' ')
					x++;
				if ((data->map[y + 1]
						|| data->map[y - 1]) && ft_isprint(data->map[y][x]))
					return (printf("Input is NOT valid\n"), false);
				else
					return (true);
			}
			x++;
		}
		y++;
	}
	return (true);
}

int	rgb(int r, int g, int b)
{
	return ((0xFF << 24) | ((b & 0xFF) << 16) | ((g & 0xFF) << 8) | (r & 0xFF));
}
