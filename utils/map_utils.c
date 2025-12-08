/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:38:26 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/08 16:40:09 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	map_up_check(t_data *data, size_t x, size_t y)
{
	int	check_y;
	if (data->map[y + 1])
	{
		if (x >= ft_strlen(data->map[y + 1]))
			return(printf("An error occured while checking MAP\n"), -1); 
		if (data->map[y + 1][x] == ' ')
		{
			check_y = y + 1;
			while (data->map[check_y] && data->map[check_y][x] == ' ')
				check_y++;
			if (!data->map[check_y] || x >= ft_strlen(data->map[check_y]))
				return(printf("An error occured while checking MAP\n"), -1); 
			if (data->map[check_y][x] != '1'&& data->map[check_y][x] != '0' && data->map[check_y][x] != 'P')
				return(printf("An error occured while checking MAP\n"), -1); 
		}
	}
	return (0);
}
char map_down_check(t_data *data, size_t x, size_t y)
{
	int	check_y;
	if (y > 0 && data->map[y - 1][x] && data->map[y - 1][x] == ' ')
	{
		check_y = y - 1;
		while (check_y >= 0 && data->map[check_y][x] == ' ')
			check_y--;
		if (check_y < 0 || x >= ft_strlen(data->map[check_y]))
			return(printf("An error occured while checking MAP\n"), -1); 
		if (data->map[check_y][x] != '1'&& data->map[check_y][x] != '0' && data->map[check_y][x] != 'P')
			return(printf("An error occured while checking MAP\n"), -1); 
	}
		return (0);
}
char	map_left_check(t_data *data, size_t x, size_t y)
{
    int	check_x;

    if (data->map[y][x + 1] && data->map[y][x + 1] == ' ')
    {
        check_x = x + 1;
        while (data->map[y][check_x] && data->map[y][check_x] == ' ')
            check_x++;
        if (data->map[y][check_x] == '\0')
            return(printf("An error occured while checking MAP\n"), -1); 
        if (data->map[y][check_x] != '1')
            return(printf("An error occured while checking MAP\n"), -1); 
    }
    return (0);
}
char    map_right_check(t_data *data, size_t x, size_t y)
{
    int check_x;
        if (x > 0 && data->map[y][x - 1] == ' ')
    {
        check_x = x - 1;
        while (check_x >= 0 && data->map[y][check_x] == ' ')
            check_x--;
        if (check_x < 0)
            return(printf("An error occured while checking MAP\n"), -1); 
        if (data->map[y][check_x] != '1')
            return(printf("An error occured while checking MAP\n"), -1); 
    }
    if (data->map[y][x + 1] == '\0')
        return(printf("An error occured while checking MAP\n"), -1); 
    if (x == 0)
        return(printf("An error occured while checking MAP\n"), -1); 
    return (0);
}