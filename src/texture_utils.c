/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:38:07 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/19 17:16:02 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool    set_no_walls(t_data *data, char *ptr)
{
    int i;

    data->no_flag++;
    i = 0;
    if (data->no_flag != 1)
        return(printf("Path has MORE than required ARGS [NO]\n"), false);
    if (!ptr[i])
        return(printf("An error occured on text route\n"), false);
    if (!ptr[0])
        return(printf("Empty path\n"), false);
    i += 2;
    while (ptr[i] == ' ')
         i++;
    if (ptr[i] == '.' && ptr[i + 1] == '/')
        data->no = ft_strdup(ptr + i);
    else
        return(printf("Wrong path [ARG]\n"), false);
    if (data->no[ft_strlen(data->no) - 1] == '\n')
        data->no[ft_strlen(data->no) - 1] = '\0';

    return(true);
}
static bool set_we_walls(t_data *data, char *ptr)
{
    int i;

    i = 0;
    data->we_flag++;
    if (data->we_flag != 1)
        return(printf("Path has MORE than required ARGS [WE]\n"), false);
    if (!ptr[i])
        return(printf("An error occured on text route\n"), false);
    if (!ptr[0])
        return(printf("Empty path\n"), false);
    i += 2;
    while (ptr[i] == ' ')
        i++;
    if (ptr[i] == '.' && ptr[i + 1] == '/')
        data->we = ft_strdup(ptr + i);
    else
        return(printf("Wrong path [ARG]\n"), false);
    if (data->we[ft_strlen(data->we) - 1] == '\n')
        data->we[ft_strlen(data->we) - 1] = '\0';
    return(true);
}
static bool    set_ea_wall(t_data *data, char *ptr)
{
    int i;

    i = 0;
    data->ea_flag++;
    if (data->ea_flag != 1)
        return(printf("Path has MORE than required ARGS [EA]\n"), false);
    if (!ptr[i])
        return(printf("An error occured on text route\n"), false);
    if (!ptr[0])
        return(printf("Empty path\n"), false);
    i += 2;
    while (ptr[i] == ' ')
        i++;
    if (ptr[i] == '.' && ptr[i + 1] == '/')
        data->ea = ft_strdup(ptr + i);
    else
        return(printf("Wrong path [ARG]\n"), false);
    if (data->ea[ft_strlen(data->ea) - 1] == '\n')
        data->ea[ft_strlen(data->ea) - 1] = '\0'; 

    return(true);
}
static bool set_so_walls(t_data *data, char *ptr)
{
    int i;

    i = 0;
    data->so_flag++;
    if (data->so_flag != 1)
        return(printf("Path has MORE than required ARGS [SO]\n"), false);
    if (!ptr[i])
        return(printf("An error occured on text route\n"), false);
    if (!ptr[0])
        return(printf("Empty path\n"), false);
    i += 2;
    while (ptr[i] == ' ')
        i++;
    if (ptr[i] == '.' && ptr[i + 1] == '/' && ptr[i + 2] == 't')
        data->so = ft_strdup(ptr + i);
    else
        return(printf("Wrong path [ARG]\n"), false);
    if (data->so[ft_strlen(data->so) - 1] == '\n')
        data->so[ft_strlen(data->so) - 1] = '\0'; 
    return(true);
}
bool    set_walls_texture(t_data *data, char *ptr)
{
    if (ft_strncmp(ptr, "SO", 2) == 0)
        if (set_so_walls(data, ptr) == false)
            return(false);
    if (ft_strncmp(ptr, "NO", 2) == 0)
        if (set_no_walls(data, ptr) == false)
            return(false);
    if (ft_strncmp(ptr, "EA", 2) == 0)
        if (set_ea_wall(data, ptr) == false)
            return(false);
    if (ft_strncmp(ptr, "WE", 2) == 0)
        if (set_we_walls(data, ptr) == false)
            return(false);
    return(true);
}