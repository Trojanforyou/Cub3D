/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:27:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/04 14:33:53 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char prefix_check(char *filename)
{
	if (ft_strlen(filename) < 4)
		return(-1);
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".cub", 4) != 0)
		return (printf("Maps prefix has to be [.cub]\n"), -1);
	return (0);
}

char	cordinates_check(char *filename)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*full_file;
	char	**map;
	
	map = NULL;
	full_file = ft_strdup("");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return(printf("Sosal?\n"), -1);
	while ((line = get_next_line(fd)))
	{
		if (line[0] == '1')
		{
			temp = ft_strjoin(full_file, line);
			full_file = temp;
		}
	}
	map = ft_split(full_file, '\n');
	free(full_file);
	close(fd);
	return (**map);
}	

// char	dublicate_check(char **map)
// {
// 	int	x;
// 	int	y;
// 	int	flag;

// 	x = 0;
// 	flag = 0;
// 	while (map[x])
// 	{
// 		y = 0;
// 		while (map[x][y])
// 		{
// 			if(map[x][y] == 'N' || map[x][u])
// 		}
// 	}
// }


