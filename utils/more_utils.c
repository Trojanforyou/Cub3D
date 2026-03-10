/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:21:40 by msokolov          #+#    #+#             */
/*   Updated: 2026/03/10 20:22:54 by msokolov         ###   ########.fr       */
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

	cx = SCREEN_WIDTH / 2;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	dx = x - cx;
	if (dx > 1 || dx < -1)
		rotate_camera(data->player, -dx * 0.002);
	mlx_set_mouse_pos(data->mlx, cx, (SCREEN_HEIGHT / 2));
}

bool	column_check_helper(t_data *data, int x, int y)
{
	size_t	len;
	char	c;

	c = 0;
	if (!data || !data->map || !data->map[y])
		return (false);
	if (data->map[y][x] == ' ' || data->map[y][x] == '\0')
	{
		if (data->map[y + 1])
		{
			len = ft_strlen(data->map[y + 1]);
			if ((size_t)x < len)
			{
				c = data->map[y + 1][x];
				if (c == 'P' || c == '0' || c == 'D')
					return (printf("Map is not covered by the walls\n"), false);
			}
		}
	}
	return (true);
}

bool	arg_check(char **path)
{
	int	k;
	int	j;

	k = 0;
	if (path[2] && path[2][0] && path[2][0] == ' ')
	{
		while (path[2][k] == ' ')
			k++;
		if (!path[2][k] + 1 && path[2][k] == '\0')
			return (printf
				("Invalid or missing floor or ceiling color\n"), false);
	}
	k = 0;
	while (path[k])
	{
		j = 0;
		while (path[k][j])
		{
			if (path[k][j] == ' ' && ft_isdigit(path[k][j + 1]))
				return(printf("Invalid or missing floor or ceiling color\n"), false);
			j++;
		}
		k++;
	}
	
	return (true);
}
bool	set_map_helper(char *line, char **temp, int *i, int *map_started)
{
	if (line[0] == '\n')
	{
		if (*map_started == 1)
			return(false);
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
	return(true);
}
