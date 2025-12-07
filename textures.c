/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 20:43:38 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/07 14:00:24 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_load(t_text *texture)
{
    texture->wall[0] = mlx_load_png("./texture/Northwall.png");
    texture->wall[1] = mlx_load_png("./texture/southwall.png");
    texture->wall[0] = mlx_load_png("./texture/westwall.png");
    texture->wall[0] = mlx_load_png("./texture/eastwall.png");
    if (texture->wall[0] == NULL || texture->wall[1] == NULL || texture->wall[2] == NULL 
    || texture->wall[3] == NULL)
        return ;
}
