/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:27:59 by msokolov          #+#    #+#             */
/*   Updated: 2026/02/03 14:19:04 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	main_dublicate_check(t_data *data, int *y, int *x, int *flag)
{
	if (data->map[*y][*x] == 'N' || data->map[*y][*x] == 'W'
		|| data->map[*y][*x] == 'S' || data->map[*y][*x] == 'E')
	{
		(*flag)++;
		data->map[*y][*x] = 'P';
	}
	else if (data->map[*y][*x] == 'D')
		data->door_count++;
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
		return (printf("File does not exist\n"), NULL);
	if (set_map(line, fd, data, temp, &i) == NULL)
		return (NULL);
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
			main_dublicate_check(data, &y, &x, &flag);
			x++;
		}
		y++;
	}
	if (flag > 1 || flag == 0 || data->door_count > 1)
		return (printf("Wrong [CORDINATE] usage\n"), -1);
	return (0);
}

// static bool	value_check(char **line)
// {
// 	if (ft_strlen(line[0]) == 0 || ft_strlen(line[1]) == 0
// 		|| ft_strlen(line[2]) == 0)
// 		return (printf("RGB args is not valid\n"), false);
// 	return (true);
// }

bool	parse_floor_ceiling(char *path, t_data *data, char **line)
{
	int		r;
	int		g;
	int		b;
	char	*tmp;

	r = 0;
	g = 0;
	b = 0;
	tmp = path + 2;
	line = ft_split(tmp, ',');
	line = trim_floor(line);
	if (floor_ceiling_check(line) == false)
		return (false);
	r = ft_atoi(line[0]);
	g = ft_atoi(line[1]);
	b = ft_atoi(line[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (printf("RGB is out from range [0-256]"), false);
	if (path[0] == 'F')
		data->floor = RGB(r, g, b);
	if (path[0] == 'C')
		data->ceiling = RGB(r, g, b);
	clean_floor(line);
	return (true);
}
