/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:27:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/06 13:18:32 by msokolov         ###   ########.fr       */
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

char	**cordinates_check(char *filename, t_data *data)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*full_file;;

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
	data->map = ft_split(full_file, '\n');
	free(full_file);
	close(fd);
	return (0);
}

char	dublicate_check(t_data *data)
{
	int	x;
	int	y;
	int	flag;

	y = 0;
	flag = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if(data->map[y][x] == 'N' || data->map[y][x] == 'W' || data->map[y][x] == 'S' || data->map[y][x] == 'E')
			{
				flag++;
				data->map[y][x] = 'P';
			}
			x++;
		}
		y++;
	}
	if (flag > 1 || flag == 0)
		return (printf("Wrong [CORDINATE] usage\n"), -1);
	return(0);
}

char map_validation(t_data *data)
{
	size_t	x;
	size_t	y;

	x = 1;
	while (data->map[x])
	{
		y = 1;
		while (data->map[x][y])
		{
			if ((data->map[x][y] == 'P' || data->map[x][y] == '0'))
			{
				// printf("here\n");
				if (y > 0)
					if (data->map[x][y - 1] == ' ')
						return(printf("An error occured while reading a map\n"), -1);
				if (x > 0)
					if (data->map[x -1][y] == ' ')
						return(printf("An error occured while reading a map\n"), -1);
				if (y < ft_strlen(data->map[x]) - 1)
					if (data->map[x][y + 1] == ' ' && data->map[x + 1][y])
						return(printf("An error occured while reading a map\n"), -1);
				if (data->map[x + 1])
					if (data->map[x + 1][y] == ' ')
						return(printf("An error occured while reading a map\n"), -1);
			}
			y++;
		}
		x++;
	}
	return(0);
}

char wall_height_check(t_data *data)
{
	int	y;
	int	last;

	y = 0;
	last = get_map_height(data->map);
	while (data->map[0][y + 1])
	{
		if(data->map[0][y] != '1' && data->map[0][y] != ' ')
			return(printf("An error occured while reading a map1\n"), -1);
		y++;
	}
	y = 0;
	while (data->map[last - 1][y + 1])
	{
		if (data->map[last -1][y] != '1' && data->map[last -1][y] != ' ')
			return(printf("An error occured while reading a map2\n"), -1);
		y++;
	}
	return (0);
}
char map_witdh_check(t_data *data)
{
	int	x;
	int	last;
	
	x = 0;
	last = get_map_height(data->map);
	while (x < last  - 1)
	{
		if (data->map[x][0] != '1' && data->map[x][0] != ' ')
			return(printf("An error occured while reading a map3\n"), -1);
		x++;
	}
	x = 0;
	while (data->map[x])
	{
		if (data->map[x][ft_strlen(data->map[x]) - 1] != '1' && data->map[x][ft_strlen(data->map[x]) - 1] != ' ')
			return(printf("An error occured while reading a map4\n"), -1);
		x++;
	}
	return (0);
}
