/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:38:22 by msokolov          #+#    #+#             */
/*   Updated: 2026/02/03 16:28:14 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**set_map(int fd, t_data *data, char **temp, int *i)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (additional_check(line, data) == false)
			return (NULL);
		if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
			|| ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "WE", 2) == 0 ||
		line[0] == 'F' || line[0] == 'C')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		if (line[0] == '\n')
			line[0] = '\0';
		temp[*i] = line;
		(*i)++;
		line = get_next_line(fd);
	}
	return (temp);
}
bool	set_collor(t_data *data, int y, int x)
{
	int	color;

	color = 0;
	if (!data || !data->map)
		return (printf("Error: data or map is NULL\n"), false);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->player && (int)data->player->pos.x ==
				x && (int)data->player->pos.y == y)
				color = 0xFF0000FF;
			else if (data->map[y][x] == '0')
				color = 0x654321FF;
			else if (data->map[y][x] == '1')
				color = 0x000000FF;
			else if (data->map[y][x] == 'D')
				color = 0x00FF00FF;
			else
			{
				(x)++;
				continue;
			}
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
	return (true);
}
