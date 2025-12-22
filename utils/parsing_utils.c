/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:38:22 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/22 14:43:55 by msokolov         ###   ########.fr       */
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
