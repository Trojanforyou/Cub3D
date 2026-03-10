/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:38:22 by msokolov          #+#    #+#             */
/*   Updated: 2026/03/10 16:55:01 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_tile_color(t_data *data, int x, int y)
{
	if (data->player && (int)data->player->pos.x == x
		&& (int)data->player->pos.y == y)
		return (0xFF0000FF);
	else if (data->map[y][x] == '0')
		return (0x654321FF);
	else if (data->map[y][x] == '1')
		return (0x000000FF);
	else if (data->map[y][x] == 'D')
		return (0x00FF00FF);
	return (-1);
}

// bool is_map_line(char *line)
// {
//     int i;

//     i = 0;
//     while (line[i])
//     {
//         if (line[i] != ' ' && line[i] != '0' && line[i] != '1' 
//             && line[i] != 'N' && line[i] != 'S' && line[i] != 'W' 
//             && line[i] != 'E' && line[i] != 'D' && line[i] != '\n')
//             return (false);
//         i++;
//     }
//     return (true);
// }

char	**set_map(int fd, t_data *data, char **temp, int *i)
{
	char	*line;
	int		map_started;
	
	map_started = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (additional_check(line, data) == false)
			return (free(line), get_next_line(-1), NULL);
		if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
			|| ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "WE", 2) == 0
			|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		{
		if (map_started == 1)
			return(free(line), 
				printf("Map Has non valid ending\n"), NULL);
		free(line);
		line = get_next_line(fd);
		continue ;
		}
		if (set_map_helper(line, temp, i, &map_started) == false)
			return(free(line), printf("Map have a New Line\n"), NULL);
		line = get_next_line(fd);
	}
	get_next_line(-1);
	return (temp);
}


bool	set_collor(t_data *data, int y, int x)
{
	int	color;

	if (!data || !data->map)
		return (printf("Error: data or map is NULL\n"), false);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			color = get_tile_color(data, x, y);
			if (color == -1)
			{
				x++;
				continue ;
			}
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
	return (true);
}
