/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:42:06 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/12 15:53:16 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    data_init(t_data *data)
{
    data->map = NULL;
    data->floor = 0;
    data->ceiling = 0;
	data->wall_found = 0;
}
