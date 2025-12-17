/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:27:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/17 18:21:52 by msokolov         ###   ########.fr       */
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
	i = -1;
	temp = malloc(sizeof(char *) * (MAX_MAP_LINES + 1));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return(printf("Sosal?\n"), NULL);
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
		temp[++i] = line;
	}
	temp[i + 1] = NULL;
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
	// printf("%s\n", tmp_floor[0]);
	int		r;
	int		g;
	int		b;
	char	*tmp;
	char	*tmp2;
	int	i=0;

	r = 0;
	g = 0;
	b = 0;
	tmp = path + 2;
	tmp_floor = ft_split(tmp, ',');
	tmp_floor = trim_floor(tmp_floor);
	while (tmp_floor[i])
	{
		tmp2 = tmp_floor[i];
		tmp_floor[i] = ft_strtrim(tmp2, "\n");
		free(tmp2);
		i++;
	}
	if (floor_error_check(tmp_floor) == false) 
		return(false);
	if (path[0] == 'F')
	{
		r = ft_atoi(tmp_floor[0]);
		g = ft_atoi(tmp_floor[1]);
		b = ft_atoi(tmp_floor[2]);
		if ((r < 0 && r > 256) || (g < 0 && g > 256) || (b  < 0 && b > 256))
			return(printf("RGB is out from range [0-256]"), false);
		data->floor = RGB(r, g, b);
	}
	return(true);
}
bool	parse_ceiling(char *path, t_data *data, char **tmp_ceiling)
{
	int		r;
	int		g;
	int		b;
	char	*tmp;

	r = 0;
	g = 0;
	b = 0;
	tmp = path + 2;
	tmp_ceiling = ft_split(tmp, ',');
	tmp_ceiling = trim_celing(tmp_ceiling);
	if (ceiling_error_check(tmp_ceiling) == false)
		return(false);
	if (path[0] == 'C')
	{
		data->ceiling = RGB(r, g, b);
		r = ft_atoi(tmp_ceiling[0]);
		g = ft_atoi(tmp_ceiling[1]);
		b = ft_atoi(tmp_ceiling[2]);
		if ((r < 0 && r > 256) || (g < 0 && g > 256) || (b  < 0 && b > 256))
			return(printf("RGB is out from range [0-256]"), false);
		data->ceiling = RGB(r, g, b);
	}
	return(true);
}
