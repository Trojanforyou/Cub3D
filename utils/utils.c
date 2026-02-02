/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:57:55 by msokolov          #+#    #+#             */
/*   Updated: 2026/02/02 15:33:43 by msokolov         ###   ########.fr       */
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
char get_max_witdh(t_data *data)
{
	int	y;
	int	max;

	max = 0;
	y = 0;
	int	len;
	while (data->map[y])
	{
		len = ft_strlen(data->map[y]);
		if (len > max)
			max = len;
		y++;
	}
	return(max);
}

bool	ceiling_error_check(char ** ceiling)
{
	int	i;
	int	j;

	i = 0;
	if (!ceiling || !ceiling[0] || !ceiling[1] || !ceiling[2] || ceiling[3])
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
				return(printf("Ceiling has Non [INT] value"), false);
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
			if (parse_floor_ceiling(line, data, data->tmp_floor) == false)
				return(false);
		if (*line == 'C')
			if (parse_floor_ceiling(line, data, data->tmp_ceiling) == false)
				return(false);
		return(true);
	}
	return(true);
}
void    change_perspective(t_data *data)
{
    int y;
    int x;

	y = 0;
    while(data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {   if (data->map[y][x] == 'P')
                if (data->player->pos.x != 0 || data->player->pos.y != 0 )
                    data->map[y][x] = '0';
            x++;
        }
        y++;
    }
}

