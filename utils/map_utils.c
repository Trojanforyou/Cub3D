/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:38:26 by msokolov          #+#    #+#             */
/*   Updated: 2026/02/12 16:00:07 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	map_up_check(t_data *data, size_t x, size_t y)
{
	if (data->map[0][x] == ' ')
		x++;
	if (data->map[y + 1]
		&& y <= ft_strlen(data->map[y])
		&& data->map[y + 1][x] == ' ')
	{
		while (y > 0 && data->map[y][x] == ' ')
			y--;
		if (data->map[y][x] == '1')
			return (true);
		if (data->map[y][x] == '0'
			|| data->map[y][x] == 'P'
			|| data->map[y][x] == 'D')
			return (printf("Map is not covered by the walls\n"), false);
		else
			return (true);
	}
	return (true);
}

bool	map_down_check(t_data *data, size_t x, size_t y)
{
	if (data->map[0][x] == ' ')
	{
		while (y <= ft_strlen(data->map[y]) && data->map[y][x] == ' ')
			y++;
		if (data->map[y][x] == '0' || data->map[y][x] == 'P'
			|| data->map[y][x] == 'D')
			return (printf("Map is not covered by the walls\n"), false);
	}
	if (y > 0 && x < ft_strlen(data->map[y - 1])
		&& (data->map[y - 1][x] == '0'
		|| data->map[y - 1][x] == 'P' || data->map[y - 1][x] == 'D'))
		return (printf("Map is not covered by the walls\n"), false);
	else if (data->map[y][x] == ' ' && (data->map[y - 1][x] == '1'
		|| data->map[y - 1][x] == '\n'))
	{
		while (y > 0 && data->map[y] && data->map[y][x] == ' ')
			y++;
		if (data->map[y] && data->map[y][x] == '1')
			return (true);
	}
	return (true);
}

bool	map_right_check(t_data *data, size_t x, size_t y)
{
	if (data->map[y][0] == ' ')
	{
		while (data->map[y][x] == ' ')
			x++;
		if (data->map[y][x] == '0'
			|| data->map[y][x] == 'P' || data->map[y][x] == 'D')
			return (printf("Map is not covered by the walls\n"), false);
	}
	if (data->map[y][x - 1] == '0'
		|| data->map[y][x - 1] == 'P' || data->map[y][x - 1] == 'D')
		return (printf("Map is not covered by the walls\n"), false);
	if (x > 0 && data->map[y][x - 1] == '1')
	{
		while (data->map[y][x] == ' ')
			x++;
		if (data->map[y][x] == '1')
			return (true);
		if (data->map[y][x] == '0' || data->map[y][x] == 'P'
			|| data->map[y][x] == 'D')
			return (printf("Map is not covered by the walls\n"), false);
	}
	return (true);
}

bool	map_left_check(t_data *data, size_t x, size_t y)
{
	if (x + 1 < ft_strlen(data->map[y]) && (data->map[y][x + 1] == '0'
		|| data->map[y][x + 1] == 'P' || data->map[y][x + 1] == 'D'))
		return (printf("Map is not covered by the walls\n"), false);
	if (x + 1 < ft_strlen(data->map[y]) && data->map[y][x + 1] == '1')
	{
		while (data->map[y][x] == ' ')
			x--;
		if (data->map[y][x] == '1')
			return (true);
		if (data->map[y][x] == 'P' || data->map[y][x] == '0'
			|| data->map[y][x] == 'D')
			return (printf("Map is not covered by the walls\n"), false);
	}
	return (true);
}

bool	island_check(t_data *data, size_t y, size_t x)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'P'
		|| data->map[y][x] == 'D')
	{
		if (y != 0 && (data->map[y - 1][x] == '\n'
			|| data->map[y - 1][x] == '\0'))
			return (printf("Map is not covered by the walls\n"), false);
		if (data->map[y + 1] && y < ft_strlen(data->map[y])
			&& (data->map[y + 1][x] == '\n' || data->map[y + 1][x] == '\0'))
			return (printf("Map is not covered by the walls\n"), false);
		if ((data->map[y][x - 1] == '\n' || data->map[y][x - 1] == '\0'))
			return (printf("Map is not covered by the walls\n"), false);
		if (data->map[y][x + 1] == '\n' || data->map[y][x + 1] == '\0')
			return (printf("Map is not covered by the walls\n"), false);
	}
	return (true);
}
bool	find_last(t_data *data)
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
			if ((size_t)flag == ft_strlen(data->map[y]))
			{
				y++;
				if (data->map[y] && data->map[y][0] == '\0')
				{
					if (data->map[y + 1])
					{
						while (data->map[y + 1] && data->map[y][0] == ' ')
							y++;
						if (data->map[y - 1][0] == '1')
							return(printf("Input has NOT valid\n"), false);
					}
				}
				else if (!data->map[y - 1])
					return(true);

			}
			x++;

		}
		y++;
	}
	return(true);
}
bool	find_prev(t_data *data)
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
				if ((data->map[y + 1][x] || data->map[y - 1][x]) && data->map[y][x] == '1')
					return(printf("Input has NOT valid\n"), false);
				else
					return(true);
			}
			x++;
		}
		y++;
	}
	return(true);
}

