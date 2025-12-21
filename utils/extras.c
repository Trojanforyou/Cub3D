/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:11:41 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/19 01:43:56 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char    **trim_celing(char **ceiling)
{
    int i;
    char *temp;
    
    i = 0;
    temp = 0;
    while (ceiling[i])
	{
		temp = ceiling[i];
		ceiling[i] = ft_strtrim(temp, "\n");
		free(temp);
		i++;
	}
	return(ceiling);
}
char	**trim_floor(char **floor)
{
	int i;
    char *temp;
    
    i = 0;
    temp = 0;
    while (floor[i])
	{
		temp = floor[i];
		floor[i] = ft_strtrim(temp, "\n");
		free(temp);
		i++;
	}
	return(floor);
}
bool	floor_error_check(char **floor)
{
	int	i;
	int	j;

	i = 0;
	if (!floor || !floor[0] || !floor[1] || !floor[2])
	{
		if (floor)
			free(floor);
		return (printf("Invalid or missing floor color\n"), false);
	}
	while (floor[i])
	{
		j = 0;
		while (floor[i][j] != '\n' && floor[i][j] != '\0')
		{
			if (!ft_isdigit(floor[i][j] ))
				return(printf("Floor has Non [INT] value\n"), false);
			j++;
		}
		i++;
	}
	return(true);
}
bool	window_hight(t_data *data)
{
	int	x;
	int	y;
	int	witdh;

	witdh = get_map_width(data->map);
	// heigth = get_map_height(data->map);
	x = 0;
	while (x < data->witdh)
	{
		y = 0;
		while (data->map[y])
		{
			if (data->map[y][x] == ' ')
			{
				if (data->map[y + 1] && (data->map[y + 1][x] == '\n' || data->map[y + 1][x] == '0'))
					y++;
			}
			y++;
		}
		x++;
	}
	return(witdh);
}
bool	window_witdh(t_data *data)
{
	int	x;
	int	y;
	int	heigth;

	// data->witdh = get_map_width(data->map);
	heigth = get_map_height(data->map);
	y = 0;
	while (y < heigth)
	{
		x = 0;
		while (data->map[y])
		{
			if (data->map[y][x] == ' ')
			{
				if (data->map[y + 1] && (data->map[y][x + 1] == '\n' || data->map[y][x + 1] == '0'))
					continue;
			}
			x++;
		}
		y++;
	}
	return(heigth);
}

