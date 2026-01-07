/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:35:45 by msokolov          #+#    #+#             */
/*   Updated: 2026/01/01 21:18:13 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    clean_data(t_data *data)
{
    int i;

    i = 0;
    while (data->map && data->map[i])
    {
        free(data->map[i]);
        i++;
    }
    free(data->map);
    free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
}
void    clean_floor(char **data)
{
    int i;

    i = 0;
    while (data[i])
    {
        free(data[i]);
        i++;
    }
    free(data);
}
void    clean_ceiling(t_data *data)
{
    int i;

    i = 0;
    while (data->tmp_ceiling[i])
    {
        free(data->tmp_ceiling[i]);
        i++;
    }
    // free(data->tmp_ceiling);
}