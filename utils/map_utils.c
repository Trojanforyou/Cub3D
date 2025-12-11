/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:38:26 by msokolov          #+#    #+#             */
/*   Updated: 2025/12/11 16:42:07 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	map_up_check(t_data *data, size_t x, size_t y)
{
    size_t check_y = 0;
    if (!data->map[y] || ft_strlen(data->map[y]))
        if (y > 0 && !data->map[y - 1] && data->map[y + 1][x] != '1')
            return (printf("Map is not covered by the walls\n"), -1);
    printf("here\n");
    if (data->map[y - 1])
    {
        check_y = y;
        while(data->map[check_y][x] && data->map[check_y][x] == ' ')
            check_y--;
        if (data->map[check_y][x] != '1' && data->map[y][x + 1] && 
        data->map[y][x + 1] != '1')
            return (printf("Map is not covered by the walls1\n"), -1);
    }
    return(0);
}
char map_down_check(t_data *data, size_t x, size_t y)
{
    size_t check_y = 0;
    
    if (!data->map[y + 1] || ft_strlen(data->map[y + 1]))
        if (data->map[y] && data->map[y - 1][x] != '1' && data->map[y][x - 1] &&
        data->map[y][x - 1] != '1' && data->map[y][x + 1] && data->map[y][x + 1] != '1')
            return (printf("Map is not covered by the walls23\n"), -1);
    check_y = y;
    if (data->map[check_y])
    {
        while (data->map[check_y] && x < ft_strlen(data->map[check_y]) && data->map[check_y][x] == ' ')
            check_y++;
        if (data->map[y][x + 1] != '1'&& data->map[check_y][x] != '1')
            return (printf("Map is not covered by the walls32\n"), -1);
    }
    return(0);
}
char	map_right_check(t_data *data, size_t x, size_t y)
{
    int	check_x;
    if (!data->map[y][x + 1])
        if (data->map[y][x - 1] != '1')
            return (printf("Map is not covered by the walls12\n"), -1);
    if (data->map[y][x + 1])
    {
        check_x = x;
        while (data->map[y][check_x] == ' ')
            check_x++;
        if (data->map[y][check_x] != '1' )
            return (printf("Map is not covered by the walls1\n"), -1);
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
