/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addictional_parse_fucntions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:03:44 by msokolov          #+#    #+#             */
/*   Updated: 2026/03/11 12:56:06 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	map_y_check(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y])
		y++;
	if (data->map[y - 2] && data->map[y - 2][x] == '\0')
		return (printf("New line at the end of the map\n"), false);
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

bool	wall_path_check(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		return (false);
	return (true);
}
bool	arg_space_check(char **path)
{
	int	k;
	int	j;

	k = 0;
	while (k < 3 && path[k])
	{
		j = 0;
		while (path[k][j])
		{
			if (path[k][j] == ' ' && path[k][j + 1] && ft_isdigit(path[k][j + 1]))
				return (printf("Invalid or missing floor or ceiling color\n"), false);
			j++;
		}
		k++;
	}
	return(true);
}
