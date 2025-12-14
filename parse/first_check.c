/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:27:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/14 00:13:07 by msokolov         ###   ########.fr       */
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
	char	**temp;
	int		i;
	i = 0;
	temp = malloc(sizeof(char *) * (MAX_MAP_LINES + 1));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return(printf("Sosal?\n"), NULL);
	while ((line = get_next_line(fd)))
	{
		if (line[0] == '1' || line[0] == '0' || line[0] == ' ' || line[0] == '\n')
		{
			if (line[1] == 'O' || line[1] == 'O' || line[1] == 'E' || line[1] == 'A') // change it to strcnmp check
				line++;

			temp[i] = line;
			i++;
		}
		// else
		// 	free(line);
	}
	temp[i] = NULL;
	data->map = temp;
	close(fd);
	return (data->map);
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

static bool	parse_rgb(t_data *data,char **tmp_ceiling, char **tmp_floor)
{
	int	r;
	int	g;
	int	b;
	r = ft_atoi(tmp_floor[0]);
	g = ft_atoi(tmp_floor[1]);
	b = ft_atoi(tmp_floor[2]);
	if ((r < 0 && r > 256) || (g < 0 && g > 256) || (b  < 0 && b > 256))
		return(printf("RGB is out from ragne [0-256]"), false);
	data->floor = RGB(r, g, b);
	r = ft_atoi(tmp_ceiling[0]);
	g = ft_atoi(tmp_ceiling[1]);
	b = ft_atoi(tmp_ceiling[2]);
	if ((r < 0 && r > 256) || (g < 0 && g > 256) || (b  < 0 && b > 256))
		return(printf("RGB is out from ragne [0-256]"), false);
	data->ceiling = RGB(r, g, b);
	return(true);
}
char	color_set(char *filename, t_data *data)
{
	int		fd;
	char	*line;
	char	**tmp_floor;
	char	**tmp_ceiling;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return(printf("File is non READABLE\n"), -1);
	while ((line = get_next_line(fd)))
	{
		if (line[0] == 'C')
			tmp_floor = ft_split(line + 2, ',');
		else if (line[0] == 'F')
			tmp_ceiling = ft_split(line + 2, ',');
		free(line);
	}
	parse_rgb(data, tmp_ceiling, tmp_floor);
	free(tmp_ceiling);
	free(tmp_floor);
	close(fd);
	return(0);
}
