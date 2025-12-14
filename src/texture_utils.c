/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:38:07 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/14 13:29:08 by msokolov         ###   ########.fr       */
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
        if (data->no[ft_strlen(data->no) - 1] == '\n')
            data->no[ft_strlen(data->no) - 1] = '\0';
    }
    if (ft_strncmp(ptr, "SO", 2) == 0)
    {
        i += 2;
        while (ptr[i] != '.')
            i++;
        if (ptr[i + 1] == '/')
            data->so = ft_strdup(ptr + i);
        if (data->so[ft_strlen(data->so) - 1] == '\n')
            data->so[ft_strlen(data->so) - 1] = '\0'; 
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
        if (data->we[ft_strlen(data->we) - 1] == '\n')
            data->we[ft_strlen(data->we) - 1] = '\0';
    }
    if (ft_strncmp(ptr, "EA", 2) == 0)
    {
        i += 2;
        while (ptr[i] != '.')
            i++;
        if (ptr[i + 1] == '/')
            data->ea = ft_strdup(ptr + i);
        if (data->ea[ft_strlen(data->ea) - 1] == '\n')
            data->ea[ft_strlen(data->ea) - 1] = '\0'; 
    }
    return(true);
}
