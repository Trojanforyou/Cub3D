/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:38:22 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/22 15:16:04 by msokolov         ###   ########.fr       */
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
		{
			free(line);
			continue;
		}
		temp[*i] = line;
		(*i)++;
	}
	return(temp);
}
bool	set_collor(t_data *data, int y, int x)
{
	int	color;

	color = 0;
    while (data->map[y])
    {
		x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == '0')
                color = 0x654321FF; // Hex (RGBA / 0xRRGGBBAA):
            else if (data->map[y][x] == '1')
                color = 0x000000FF; // Hex (RGBA / 0xRRGGBBAA):
            else if (data->map[y][x] == 'P')
                color = 0xFF0000FF; // Hex (RGBA / 0xRRGGBBAA):
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
