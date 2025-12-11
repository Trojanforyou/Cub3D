/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:38:26 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/11 22:49:32 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool    map_up_check(t_data *data, size_t x, size_t y)
{
    if (y == 0 )
        return(true);
    if (data->map[y + 1][x] == ' ')
    {
        while (data->map[y][x] == ' ')
            y--;
        if (data->map[y][x] == '1')
            return(true);
        if (data->map[y][x] == '0' || data->map[y][x] == 'P')
            return (printf("Map is not covered by the walls\n"), false);
        else
            return(true);
    }
    else if (data->map[y + 1][x] == '0' || data->map[y + 1][x] == 'P')
        return (printf("Map is not covered by the walls\n"), false);
    return(true);
}
bool    map_down_check(t_data *data, size_t x, size_t y)
{
    if (y - 1 >= get_map_height(data->map))
        return(true);
    if (data->map[y - 1][x] == '0' || data->map[y - 1][x] == 'P')
        return (printf("Map is not covered by the walls1\n"), false);
    if (data->map[y - 1][x] == '1')
    {
        while (data->map[y][x] == ' ')
            y++;
        if (data->map[y][x] == '1')
            return(true);
        if (data->map[y][x] == '0' || data->map[y][x] == 'P')
            return (printf("Map is not covered by the walls2\n"), false);
        else
            return(false);
    }

    return(true);
}
bool	map_right_check(t_data *data, size_t x, size_t y)
{
    if (x == 0)
        return(true);
    if (data->map[y][x - 1] == '1')
    {
        while(data->map[y][x] == ' ')
            x++;
        if (data->map[y][x] == '1')
            return (true);
        if (data->map[y][x] == '0' || data->map[y][x] == 'P')
            return (printf("Map is not covered by the walls\n"), false);
        else
            return(true);
    }
    else if (data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'P')
        return (printf("Map is not covered by the walls\n"), false);
    return(true);
}

bool    map_left_check(t_data *data, size_t x, size_t y)
{
    if (x >= ft_strlen(data->map[y]))
        return(true);
    if (data->map[y][x + 1] == '1')
    {
        while (data->map[y][x] == ' ')
            x--;
        if (data->map[y][x] == '1')
            return(true);
        if (data->map[y][x] == 'P' || data->map[y][x] == '0')
            return (printf("Map is not covered by the walls\n"), false);
        else
            return(true);
    }
    else if (data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'P')
        return (printf("Map is not covered by the walls\n"), false);
    return(true);
}
