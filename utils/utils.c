/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:57:55 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/14 18:03:04 by msokolov         ###   ########.fr       */
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
bool	map_error_check(char **floor, char **ceiling)
{
	if (!floor || !ceiling || !floor[0] || !floor[1] || !floor[2] || !ceiling[0] || !ceiling[1] || !ceiling[2])
	{
		if (floor)
			free(floor);
		if (ceiling)
			free(ceiling);
		return (printf("Invalid or missing floor/ceiling color\n"), false);
	}
	return(true);
}

