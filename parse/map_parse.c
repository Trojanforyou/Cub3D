/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data->map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:54:26 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/06 13:25:33 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	map_char_check(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1' || data->map[y][x] == '0' || data->map[y][x] == 'N' || data->map[y][x] == ' ' ||
			data->map[y][x] == 'W' || data->map[y][x] == 'S' || data->map[y][x] == 'E')
				x++;
			else
				return(printf("data->map has non valid characters\n"), -1);
		}
		y++;
	}
	return(0);
}
