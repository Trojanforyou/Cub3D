/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:38:22 by msokolov          #+#    #+#             */
/*   Updated: 2026/01/09 15:57:02 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char **set_map(char *line, int fd, t_data *data, char **temp, int *i)
{
	while ((line = get_next_line(fd)))
	{
		if (additional_check(line, data) == false)
			return(NULL);
		if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 ||
		ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "WE", 2) == 0 ||
		line[0] == 'F' || line[0] == 'C')
		{
			free(line);
			continue;
		}
		if (line[0] == '\n')
			line[0] = '\0';
		temp[*i] = line;
		(*i)++;
	}
	return(temp);
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
			if (data->player && (int)data->player->pos.x == x && (int)data->player->pos.y == y)
                color = 0xFF0000FF; // Red - Player position
			else if (data->map[y][x] == '0')
                color = 0x654321FF; // Brown - Floor
            else if (data->map[y][x] == '1')
                color = 0x000000FF; // Black - Wall
			// else if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || 
            //          data->map[y][x] == 'E' || data->map[y][x] == 'W')
            //     color = 0xFF0000FF; // Red - Player spawn
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
	return(true);
}
