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
			if (data->map[y][x] == '1' || data->map[y][x] == '0' || data->map[y][x] == 'N' || data->map[y][x] == ' ' ||
			data->map[y][x] == 'W' || data->map[y][x] == 'S' || data->map[y][x] == 'E')
				x++;
			else
				return(printf("data->map has non valid characters\n"), -1);
		}
		y++;
	}
	return(0);
}
char wall_height_check(t_data *data)
{
	int	y;
	int	last;

	y = 0;
	last = get_map_height(data->map);
	while (data->map[0][y + 1])
	{
		if(data->map[0][y] == '0' || data->map[0][y] == 'P')
			return(printf("An error occured while reading a map1\n"), -1);
		y++;
	}
	y = 0;
	while (data->map[last - 1][y + 1])
	{
		if (data->map[last -1][y] != '1' && data->map[last -1][y] != ' ')
			return(printf("An error occured while reading a map2\n"), -1);
		y++;
	}
	return (0);
}
char map_witdh_check(t_data *data)
{
	int	x;
	int	last;
	
	x = 0;
	last = get_map_height(data->map);
	while (x < last  - 1)
	{
		if (data->map[x][0] != '1' && data->map[x][0] != ' ')
			return(printf("An error occured while reading a map3\n"), -1);
		x++;
	}
	x = 0;
	while (data->map[x])
	{
		if (data->map[x][ft_strlen(data->map[x]) - 1] != '1' && data->map[x][ft_strlen(data->map[x]) - 1] != ' ')
			return(printf("An error occured while reading a map4\n"), -1);
		x++;
	}
	return (0);
}
// static char	map_shape(t_data *data, size_t x, size_t y)
// {
// 	while (y < ft_strlen(data->map[x]))  // пока не конец строки
// 	{
//     	if (data->map[x][check_y] == '1')
//         	break;  // стена
//     	if (data->map[x])
// 			ap[x][check_y] == '0' || игрок)
//         	break;
//     	if (data->map[x][check_y] == ' ')
//         	check_y++;  // пробел - идем вправо
//     	else
//         	return ERROR;
// }
char map_validation(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 1;
	while (data->map[y])
	{
		x = 2;
		while (data->map[y][x])
		{
			if ((data->map[y][x] == 'P' || data->map[y][x] == '0'))
			{
				if (data->map[y][x + 1] == ' ')
				{
					int	check_x = x + 2;
					while (data->map[y][check_x] && data->map[y][check_x] == ' ')
						check_x++;
					if (data->map[y][check_x] == '\0')
						return(printf("error\n"), -1);
					if (data->map[y][check_x] != '1'&& data->map[y][check_x] != '0' && data->map[y][check_x] != 'P')
						return(printf("error\n"), -1);
				}
				if (x > 0 && data->map[y][x - 1] == ' ')
				{
					int	check_x = x - 2;
					while (check_x >= 0 && data->map[y][check_x] == ' ')
						check_x--;
					if (check_x < 0)
						return(printf("error\n"), -1);
					if (data->map[y][check_x] != '1' && data->map[y][check_x] != '0' && data->map[y][check_x] != 'P')
						return(printf("error\n"), -1);
				}
				if (data->map[y + 1] && data->map[y + 1][x] == ' ')
				{
					int	check_y1 = y + 1;
					while (data->map[check_y1] && data->map[check_y1][x] == ' ')
						check_y1++;
					if (!data->map[check_y1][x]  || x >= ft_strlen(data->map[check_y1]))
						return(printf("error\n"), -1);
					if (data->map[check_y1][x] != '1'&& data->map[check_y1][x] != '0' && data->map[check_y1][x] != 'P')
						return(printf("error\n"), -1);
				}
				if (data->map[y - 1][x] && data->map[y - 1][x] == ' ')
				{
					int	check_y = y - 2;
					while (check_y >= 0 && data->map[check_y][x] == ' ')
						check_y--;
					if (check_y < 0 || x >= ft_strlen(data->map[check_y]))
						return(printf("Error\n"), -1);
					if (data->map[check_y][x] != '1'&& data->map[check_y][x] != '0' && data->map[check_y][x] != 'P')
						return(printf("error\n"), -1);
				}
			}
			x++;
		}
		y++;
	}
	return(0);
}
