/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:11:41 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/17 18:23:15 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char    **trim_celing(char **ceiling)
{
    int i;
    char *temp;
    
    i = 0;
    temp = 0;
    while (ceiling[i])
	{
		temp = ceiling[i];
		ceiling[i] = ft_strtrim(temp, "\n");
		free(temp);
		i++;
	}
	return(ceiling);
}
char	**trim_floor(char **floor)
{
	int i;
    char *temp;
    
    i = 0;
    temp = 0;
    while (floor[i])
	{
		temp = floor[i];
		floor[i] = ft_strtrim(temp, "\n");
		free(temp);
		i++;
	}
	return(floor);
}