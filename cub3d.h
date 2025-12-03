#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft.h"

char prefix_check(char *str);

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
	struct t_player info;
}	s_data;

typedef struct t_player
{
	double	plain;
	double	dir;
	double	fov;
}	s_player;
#endif
