/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:21:40 by msokolov          #+#    #+#             */
/*   Updated: 2026/03/07 17:09:19 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	prefix_check(char *filename)
{
	if (ft_strlen(filename) < 4)
		return (-1);
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".cub", 4) != 0)
		return (printf("Maps prefix has to be [.cub]\n"), -1);
	return (0);
}

void	mouse_look(t_data *data)
{
	int		x;
	int		y;
	int		cx;
	double	dx;

	cx = data->width / 2;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	dx = x - cx;
	if (dx > 1 || dx < -1)
		rotate_camera(data->player, -dx * 0.002);
	mlx_set_mouse_pos(data->mlx, cx, (data->height / 2));
}

bool	coullum_check_helper(t_data *data, int *x, int *y)
{
	if (data->map[*y][*x] == ' ')
	{
		if (data->map[*y + 1] && (data->map[*y + 1][*x] == 'P'
			|| data->map[*y + 1][*x] == '0'
			|| data->map[*y + 1][*x] == 'D'))
			return (printf("Map is not covered by the walls"), false);
	}
	else if (data->map[*y][*x] == '\n')
		if (data->map[*y + 1] && (data->map[*y + 1][*x] == 'P'
			|| data->map[*y + 1][*x] == '0'
			|| data->map[*y + 1][*x] == 'D'))
			return (printf("Map is not covered by the walls"), false);
	return (true);
}
void	set_map_helper(char *line, char **temp, int *i, int *map_started)
{
	if (line[0] == '\n')
	{
		line[0] = '\0';
		temp[*i] = line;
		(*i)++;
	}
	else
	{
		temp[*i] = line;
		*map_started = 1;
		(*i)++;
	}
}