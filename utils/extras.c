/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:11:41 by msokolov          #+#    #+#             */
/*   Updated: 2026/02/03 16:13:45 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**trim_celing(char **ceiling)
{
	int		i;
	char	*temp;

	i = 0;
	temp = 0;
	while (ceiling[i])
	{
		temp = ceiling[i];
		ceiling[i] = ft_strtrim(temp, "\n");
		free(temp);
		i++;
	}
	return (ceiling);
}

char	**trim_floor(char **floor)
{
	int		i;
	char	*temp;

	i = 0;
	temp = 0;
	while (floor[i])
	{
		temp = floor[i];
		floor[i] = ft_strtrim(temp, "\n");
		free(temp);
		i++;
	}
	return (floor);
}

bool	floor_ceiling_check(char **path)
{
	int	i;
	int	j;

	i = 0;
	while (path[i])
	{
		j = 0;
		while (path[i][j])
		{
			if (ft_isalpha(path[i][j]))
				return (printf("Floor has Non [INT] value\n"), false);
			j++;
		}
		i++;
	}
	if (!path || !path[0] || !path[1] || !path[2] || path[3])
	{
		if (path)
			free(path);
		return (printf("Invalid or missing floor color\n"), false);
	}
	return (true);
}

bool	window_hight(t_data *data)
{
	int	x;
	int	y;
	int	width;

	width = get_map_width(data->map);
	x = 0;
	while (x < data->width)
	{
		y = 0;
		while (data->map[y])
		{
			if (data->map[y][x] == ' ')
			{
				if (data->map[y + 1] && (data->map[y + 1][x] == '\n'
					|| data->map[y + 1][x] == '0'))
					y++;
			}
			y++;
		}
		x++;
	}
	return (width);
}

bool	window_width(t_data *data)
{
	int	x;
	int	y;
	int	heigth;

	heigth = get_map_height(data->map);
	y = 0;
	while (y < heigth)
	{
		x = 0;
		while (data->map[y])
		{
			if (data->map[y][x] == ' ')
			{
				if (data->map[y + 1] && (data->map[y][x + 1] == '\n'
					|| data->map[y][x + 1] == '0'))
					continue ;
			}
			x++;
		}
		y++;
	}
	return (heigth);
}
