/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:38:26 by msokolov          #+#    #+#             */
/*   Updated: 2026/01/28 15:51:15 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool    map_up_check(t_data *data, size_t x, size_t y)
{
    if (data->map[0][x] == ' ')
        x++;
    if (data->map[y + 1] && y <= ft_strlen(data->map[y]) && data->map[y + 1][x] == ' ')
    {
        while (y > 0 && data->map[y][x] == ' ')
            y--;
        if (data->map[y][x] == '1')
            return(true);
        if ((data->map[y][x] == '0' || data->map[y][x] == 'P'))
            return (printf("Map is not covered by the walls1\n"), false);
        else
            return(true);
    }
    return(true);
}

bool    map_down_check(t_data *data, size_t x, size_t y)
{
	// if (check_bottom_row(data) == false)
    //     return(-1);
	if (data->map[0][x] == ' ')
	{
		while(y <= ft_strlen(data->map[y]) && data->map[y][x] == ' ')
			y++;
		if (data->map[y][x] == '0' || data->map[y][x] == 'P')
			return (printf("Map is not covered by the walls8\n"), false);
    }
    if (y > 0 && x < ft_strlen(data->map[y-1]) && (data->map[y - 1][x] == '0' || data->map[y - 1][x] == 'P'))
        return (printf("Map is not covered by the walls11\n"), false);
    else if (data->map[y][x] == ' ' && (data->map[y - 1][x] == '1' || data->map[y - 1][x] == '\n'))
    {
        while (y > 0 && data->map[y] && data->map[y][x] == ' ')
            y++;
        if (data->map[y] && data->map[y][x] == '1')
            return(true);
    }
    return(true);
}
bool	map_right_check(t_data *data, size_t x, size_t y)
{
	if (data->map[y][0] == ' ')
	{
		while(data->map[y][x] == ' ')
			x++;
		if (data->map[y][x] == '0' || data->map[y][x] == 'P')
			return (printf("Map is not covered by the walls5\n"), false);
	}
	if (data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'P')
        return (printf("Map is not covered by the walls3\n"), false);
    if (x > 0 && data->map[y][x - 1] == '1')
    {
        while(data->map[y][x] == ' ')
            x++;
        if (data->map[y][x] == '1')
            return (true);
        if (data->map[y][x] == '0' || data->map[y][x] == 'P')
            return (printf("Map is not covered by the walls4\n"), false);
    }
    return(true);
}

bool    map_left_check(t_data *data, size_t x, size_t y)
{
    if (x + 1 < ft_strlen(data->map[y]) && (data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'P'))
        return (printf("Map is not covered by the walls\n"), false);
    if (x + 1 < ft_strlen(data->map[y]) && data->map[y][x + 1] == '1')
    {
        while (data->map[y][x] == ' ')
            x--;
        if (data->map[y][x] == '1')
            return(true);
        if (data->map[y][x] == 'P' || data->map[y][x] == '0')
            return (printf("Map is not covered by the walls2\n"), false);
    }
    return(true);
}
bool	island_check(t_data *data, size_t y, size_t x)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'P')
	{
		if (y != 0 && (data->map[y - 1][x] == '\n' || data->map[y - 1][x] == '\0'))
			return (printf("Map is not covered by the walls11\n"), false);
		if (data->map[y + 1] && y < ft_strlen(data->map[y]) && (data->map[y + 1][x] == '\n' || data->map[y + 1][x] == '\0'))
			return (printf("Map is not covered by the walls22\n"), false);
		if ((data->map[y][x - 1] == '\n' || data->map[y][x - 1] == '\0'))
			return (printf("Map is not covered by the walls33\n"), false);
		if (data->map[y][x + 1] == '\n' || data->map[y][x + 1] == '\0')
			return (printf("Map is not covered by the walls44\n"), false);
	}
	return (true);
}

bool    map_init(t_data *data)
{
	if (dublicate_check(data) == -1)
		return(false);
	if (map_char_check(data) == -1)
		return(false);
	if (collums_check(data) == false)
		return(false);
	if (map_validation(data) == -1)
		return(false);
    return(true);
}
