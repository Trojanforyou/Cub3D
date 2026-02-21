/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:54:26 by msokolov          #+#    #+#             */
/*   Updated: 2026/02/13 15:14:59 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			if (data->map[y][x] == '1' || data->map[y][x] == '0'
				|| data->map[y][x] == 'P' || data->map[y][x] == ' '
				|| data->map[y][x] == '\n' || data->map[y][x] == 'D')
				x++;
			else
				return (printf ("Map has non valid CHARS\n"), -1);
		}
		y++;
	}
	return (0);
}

bool collums_check(t_data *data)
{
    int y;
    int x;

    if (!data || !data->map)
        return (false);
    y = 0;
    while (data->map[y])
    {
        x = 0;
        /* stop at '\0' or '\n' */
        while (data->map[y][x] && data->map[y][x] != '\n')
        {
            if (!column_check_helper(data, x, y))
                return (false);
            ++x;
        }
        ++y;
    }
    return (true);
}

/* …the rest of the file remains unchanged… */

char	map_validation(t_data *data)
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
					return (-1);
				if (map_down_check(data, x, y) == false)
					return (-1);
				if (map_left_check(data, x, y) == false)
					return (-1);
				if (map_up_check(data, x, y) == false)
					return (-1);
			}
			if (island_check(data, y, x) == false)
				return (-1);
		}
	}
	return (0);
}

bool	map_init(t_data *data)
{
	if (dublicate_check(data) == -1)
		return (false);
	if (map_char_check(data) == -1)
		return (false);
	if (collums_check(data) == false)
		return (false);
	if (map_validation(data) == -1)
		return (false);
	return (true);
}
