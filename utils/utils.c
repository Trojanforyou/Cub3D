/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:57:55 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/17 17:09:31 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map_height(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return(y);
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
				return(printf("here:%d\n", floor[i][j]), false);
			j++;
		}
		i++;
	}
	return(true);
}
bool	ceiling_error_check(char ** ceiling)
{
	int	i;
	int	j;
	
	i = 0;
	if (!ceiling || !ceiling[0] || !ceiling[1] || !ceiling[2])
	{
		if (ceiling)
			free(ceiling);
		return (printf("Invalid or missing ceiling color\n"), false);
	}
	while (ceiling[i])
	{
		j = 0;
		while (ceiling[i][j] != '\n' && ceiling[i][j] != '\0')
		{
			if (!ft_isdigit(ceiling[i][j] ))
				return(printf("Floor has Non [INT] value"), false);
			j++;
		}
		i++;
	}
	return(true);
}
bool	additional_check(char *line, t_data *data)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 ||
	ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "WE", 2) == 0)
		if (set_walls_texture(data, line) == false)
			return(false);
	if (*line == 'F' || *line == 'C')
	{
		if (*line == 'F')
			if (parse_floor(line, data, data->tmp_floor) == false)
				return(false);
		if (*line == 'C')
			if (parse_ceiling(line, data, data->tmp_ceiling) == false)
				return(false);
		return(true);
	}
	return(true);
}

