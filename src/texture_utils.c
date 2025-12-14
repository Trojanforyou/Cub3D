/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:38:07 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/14 13:07:20 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool    set_no_so_walls(t_data *data, char *ptr)
{
    int i = 0;
    if (!ptr[i])
        return(printf("An error occured on text route\n"), -1);
    if (ft_strncmp(ptr, "NO", 2) == 0)
    {
        i += 2;
        while (ptr[i] != '.')
            i++;
        if (ptr[i + 1] == '/')
            data->no = ft_strdup(ptr + i);
        printf("%s\n", data->no);  
    }
    if (ft_strncmp(ptr, "SO", 2) == 0)
    {
        i += 2;
        while (ptr[i] != '.')
            i++;
        if (ptr[i + 1] == '/')
            data->so = ft_strdup(ptr + i);
        printf("%s\n", data->so);  
    }
    return(true);
}
bool    set_we_ea_walls(t_data *data, char *ptr)
{
    int i;

    i = 0;
        if (!ptr[i])
        return(printf("An error occured on text route\n"), -1);
    if (ft_strncmp(ptr, "WE", 2) == 0)
    {
        i += 2;
        while (ptr[i] != '.')
            i++;
        if (ptr[i + 1] == '/')
            data->we = ft_strdup(ptr + i);
        printf("%s\n", data->we);  
    }
    if (ft_strncmp(ptr, "EA", 2) == 0)
    {
        i += 2;
        while (ptr[i] != '.')
            i++;
        if (ptr[i + 1] == '/')
            data->ea = ft_strdup(ptr + i);
        printf("%s\n", data->ea);    
    }
    return(true);
}
