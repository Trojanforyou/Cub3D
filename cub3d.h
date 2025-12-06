#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

char	**cordinates_check(char *filename);
char 	prefix_check(char *filename);
char	dublicate_check(char **map);
char 	wall_height_check(char **map);
char 	map_witdh_check(char **map);
int		get_map_height(char **map);
char	map_validation(char **map);
char	map_char_check(char **map);

// typedef	enum e_obj
// {
// 	WALL = 1,
// 	FLOOR = 0,
// 	PLAYER = 'P'
// }	t_obj;
typedef struct t_data
{
	char	**map;
	int		witdh;
	int		height;
	char	*no;
	char	*so;
	char	*we;
	int		floor;
	int		ceiling;
	int		no_found;
	int		so_found;
	int		we_found;
}	s_data;

typedef struct t_player
{
	double	plain;
	double	dir;
	double	fov;
}	s_player;
#endif

