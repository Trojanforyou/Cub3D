/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:38:26 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/11 01:16:00 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	map_up_check(t_data *data, size_t x, size_t y)
{
    int check_y;
    if (data->map[y - 1][x])
    {
        check_y = y;
        if (data->map[check_y][x] == ' ' && check_y >= 0)
        {
            while (data->map[check_y][x] == ' ' && check_y >= 0)
                check_y--;
            if (data->map[check_y][x] != '1')
                return(printf("An error occured while checking MAP\n"), -1); 
            if (data->map[check_y][x] == '\0')
                return(printf("An error occured while checking MAP\n"), -1);
        } 
    }
    return(0);
}
// char map_down_check(t_data *data, size_t x, size_t y)
// {
// 	int	check_y;
//     if (data->map[y][x])
//     {
//         check_y = y;
//         while (data->map[check_y] && x < ft_strlen(data->map[check_y]) && data->map[check_y][x] == ' ')
//         {
//             check_y++;
//         }
//         if (data->map[check_y][x] != '1' && data->map[check_y + 1][x] == '\0')
//             return(printf("An error occured while checking MAP\n"), -1);
//     }
//     return(0);
// }
char	map_right_check(t_data *data, size_t x, size_t y)
{
    int	check_x;
    if (data->map[y][x + 1])
    {
        check_x = x + 1;
        if (data->map[y][check_x] && data->map[y][check_x] == ' ')
        {
            while (data->map[y][check_x] == ' ')
                check_x++;
            if (data->map[y][check_x] != '1' && data->map[y][check_x] != '\0')
                return (printf("Map is not covered by the walls\n"), -1);
        }
    }
    return(0);
}
char    map_left_check(t_data *data, size_t x, size_t y)
{
    int check_x;
    if (data->map[y][x - 1])
    {
        check_x = x - 1;
        if (data->map[y][check_x] == ' ')
        {
            while (data->map[y][check_x] == ' ')
                check_x--;
            if (data->map[y][check_x] != '1')
                return (printf("Map is not covered by the walls1\n"), -1);
            else if (data->map[y][check_x + 1] == '\0')
                return (printf("Map is not covered by the walls1\n"), -1);
        }   
    }
    return(0);
}
