/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:57:55 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/14 14:35:40 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map_height(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return(y);
}
bool	check_bottom_row(t_data *data)
{
	size_t	x;
	size_t last;
	size_t len;

	x = 0;
	last = 0;
    while (data->map[last + 1])
        last++;
    len = ft_strlen(data->map[last]);
    while (x < len)
    {
		if (data->map[last][x] != '1' && data->map[last][x] != ' ')
			return (printf("Map is not covered by the walls"), false);
        x++;
    }
    return true;
}

