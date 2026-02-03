/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:35:45 by msokolov          #+#    #+#             */
/*   Updated: 2026/02/03 15:35:57 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_data(t_data *data)
{
	int	i;

	i = 0;
	if (data)
	{
		if (data->map)
		{
			while (data->map && data->map[i])
			{
				free(data->map[i]);
				i++;
			}
		}
		free(data->map);
		if (data->no)
			free(data->no);
		if (data->so)
			free(data->so);
		if (data-> we)
			free(data->we);
		if (data->ea)
			free(data->ea);
	}
}

void	clean_floor(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free (data);
}

void	clean_ceiling(t_data *data)
{
	int	i;

	i = 0;
	if (data->mlx)
	{
		while (i < 3)
		{
			if (data->wall_img[i])
				mlx_delete_image(data->mlx, data->wall_img[i]);
			i++;
		}
	}
}
