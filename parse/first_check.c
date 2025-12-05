/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:27:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/06 00:13:03 by msokolov         ###   ########.fr       */
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

char	**cordinates_check(char *filename)
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
		return(printf("Sosal?\n"), NULL);
	while ((line = get_next_line(fd)))
	{
		if (line[0] == '1' || line[0] == '0' || line[0] == 'P') 
		{
			temp = ft_strjoin(full_file, line);
			free(full_file);
			full_file = temp;
		}
		free(line);
	}
	map = ft_split(full_file, '\n');
	free(full_file);
	close(fd);
	return (map);
}

char	dublicate_check(char **map)
{
	int	x;
	int	y;
	int	flag;

	y = 0;
	flag = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if(map[y][x] == 'N' || map[y][x] == 'W' || map[y][x] == 'S' || map[y][x] == 'E')
			{
				flag++;
				map[y][x] = 'P';
			}
			x++;
		}
		y++;
	}
	if (flag > 1 || flag == 0)
		return (printf("Wrong [CORDINATE] usage\n"), -1);
	return(0);
}

char map_validation(char **map)
{
	size_t	x;
	size_t	y;

	x = 1;
	while (map[x])
	{
		y = 1;
		while (map[x][y])
		{
			if ((map[x][y] == 'P' || map[x][y] == '0'))
			{
				// printf("here\n");
				if (y > 0)
					if (map[x][y - 1] == ' ')
						return(printf("An error occured while reading a map\n"), -1);
				if (x > 0)
					if (map[x -1][y] == ' ')
						return(printf("An error occured while reading a map\n"), -1);
				if (y < ft_strlen(map[x]) - 1)
					if (map[x][y + 1] == ' ' && map[x + 1][y])
						return(printf("An error occured while reading a map\n"), -1);
				if (map[x + 1])
					if (map[x + 1][y] == ' ')
						return(printf("An error occured while reading a map\n"), -1);
			}
			y++;
		}
		x++;
	}
	return(0);
}

char wall_check(char **map)
{
	int	x;
	int	y;
	int	last;

	x = 1;
	y = 0;
	last = get_map_height(map);
	while (map[0][y])
	{
		if(map[0][y] != '1' && map[0][y] != ' ')
			return(printf("An error occured while reading a map1\n"), -1);
		y++;
	}
	y = 0;
	while (map[last - 1][y++])
	{
		if (map[last -1][y] != '1' && map[last -1][y] != ' ')
			return(printf("An error occured while reading a map2\n"), -1);
		y++;
	}
	y = 0;
	while (x < last - 1)
	{
		if (map[x][0] != '1' && map[x][0] != ' ')
			return(printf("An error occured while reading a map3\n"), -1);
		x++;
	}
	x = 0;
	while (map[x])
	{
		if (map[x][ft_strlen(map[x]) - 1] != '1' && map[x][ft_strlen(map[x]) - 1] != ' ')
			return(printf("An error occured while reading a map4\n"), -1);
		x++;
	}
	return (0);
}





