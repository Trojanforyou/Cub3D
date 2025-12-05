/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:27:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/05 16:09:26 by msokolov         ###   ########.fr       */
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
		if (line[0] == '1')
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
			if(map[y][x] == 'N' || map[x][y] == 'W' || map[x][y] == 'S' || map[x][y] == 'E')
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
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
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

char map_validation(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x++])
		if(map[0][x] == 'P' || map[0][y] == '0')
			return(printf("An error occured while reading a map\n"), -1);
	x = 0;
	while (map[get_map_height(map) - 1][x])
		if (map[get_map_height(map) - 1][x] != 0 && )
			return(printf("An error occured while reading a map\n"), -1);
	while (map[0][y++])
		if (map[0][y] != '1')
			return(printf("An error occured while reading a map\n"), -1);
	while (map[y++])
		if (map[y][ft_strlen(map[y]) - 1] != '1')
			return(printf("An error occured while reading a map\n"), -1);
	return (0);
}
int	get_map_height(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return(y);
}




