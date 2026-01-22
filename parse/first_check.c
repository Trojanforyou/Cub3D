/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:27:59 by msokolov          #+#    #+#             */
/*   Updated: 2026/01/17 13:49:48 by msokolov         ###   ########.fr       */
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

char	**map_reader(char *filename, t_data *data)
{
	int		fd;
	char	*line;
	char	**temp;
	int		i;

	i = 0;
	line = NULL;
	temp = ft_calloc(MAX_MAP_LINES + 1, sizeof(char *));
	if (!temp)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return(printf("Sosal?\n"), NULL);
	if (set_map(line, fd, data, temp, &i) == NULL)
		return(NULL);
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

bool parse_floor(char *path, t_data *data, char **tmp_floor)
{
<<<<<<< HEAD
	int	r;
	int	g;
	int	b;

	if (!tmp_floor || !tmp_floor[0] || !tmp_floor[1] || !tmp_floor[2])
	{
	    printf("Floor RGB is incomplete\n");
	    return false;
	}
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
=======
	int		r;
	int		g;
	int		b;
	char	*tmp;

	r = 0;
	g = 0;
	b = 0;
	tmp = path + 2;
	tmp_floor = ft_split(tmp, ',');
	tmp_floor = trim_floor(tmp_floor);
	if (floor_error_check(tmp_floor) == false)
		return(false);
	if (path[0] == 'F')
	{
		r = ft_atoi(tmp_floor[0]);
		g = ft_atoi(tmp_floor[1]);
		b = ft_atoi(tmp_floor[2]);
		if ((r < 0 || r > 256) || (g < 0 || g > 256) || (b  < 0 || b > 256))
			return(printf("RGB is out from range [0-256]"), false);
		data->floor = RGB(r, g, b);
	}
	clean_floor(tmp_floor);
	return(true);
}
bool	parse_ceiling(char *path, t_data *data, char **tmp_ceiling)
>>>>>>> origin
{
	int		r;
	int		g;
	int		b;
	char	*tmp;
	// char **split;

	r = 0;
	g = 0;
	b = 0;
	tmp = path + 2;
	tmp_ceiling = ft_split(tmp, ',');
	tmp_ceiling = trim_celing(tmp_ceiling);
	// clean_floor(split);
	if (ceiling_error_check(tmp_ceiling) == false)
		return(false);
	if (path[0] == 'C')
	{
		r = ft_atoi(tmp_ceiling[0]);
		g = ft_atoi(tmp_ceiling[1]);
		b = ft_atoi(tmp_ceiling[2]);
		if ((r < 0 || r > 256) || (g < 0 || g > 256) || (b  < 0 || b > 256))
			return(printf("RGB is out from range [0-256]"), false);
		data->ceiling = RGB(r, g, b);
	}
<<<<<<< HEAD
	parse_rgb(data, tmp_ceiling, tmp_floor);
	close(fd);
	return(0);
=======
	clean_floor(tmp_ceiling);
	return(true);
>>>>>>> origin
}
