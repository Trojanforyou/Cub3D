/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:21:40 by msokolov          #+#    #+#             */
/*   Updated: 2026/02/11 13:52:04 by otanovic       ########   odam.nl        */
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

bool column_check_helper(t_data *data, int x, int y)
{
    size_t len;

    if (!data || !data->map || !data->map[y])
        return (false);
    if (data->map[y][x] == ' ' || data->map[y][x] == '\n')
    {
        if (data->map[y + 1])
        {
            len = ft_strlen(data->map[y + 1]);
            if ((size_t)x < len)            /* bounds check! */
            {
                char c = data->map[y + 1][x];
                if (c == 'P' || c == '0' || c == 'D')
                    return (printf("Map is not covered by the walls\n"), false);
            }
        }
    }
    return (true);
}