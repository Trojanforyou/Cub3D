#ifndef CUB3D_H
# define CUB3D_H
#define RGB(r, g, b) ((r << 16) | (g << 8) | b)
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	mlx_t 		*mlx;
	mlx_image_t *image;
	char		**map;
	int			witdh;
	int			height;
	char		*no;
	char		*so;
	char		*we;
	int			floor;
	int			ceiling;
	int			no_found;
	int			so_found;
	int			we_found;
}	t_data;
typedef struct t_player
{
	double	plain;
	double	dir;
	double	fov;
}	s_player;

// typedef struct s_texture
// {
// 	mlx_texture_t	*wall[4] // 0 = north, 1 = south, 2 = west, 3 = east
// }	t_text;

char	color_set(char *filename, t_data *data);
char	**cordinates_check(char *filename, t_data *data);
char 	prefix_check(char *filename);
char	dublicate_check(t_data *data);
char 	wall_height_check(t_data *data);
char 	map_witdh_check(t_data *data);
int		get_map_height(char **map);
char	map_validation(t_data *data);
char	map_char_check(t_data *data);
char 	map_down_check(t_data *data, size_t x, size_t y);
char 	map_right_check(t_data *data, size_t x, size_t y);
char 	map_left_check(t_data *data, size_t x, size_t y);
char 	map_up_check(t_data *data, size_t x, size_t y);
void    data_init(t_data *data);

// typedef	enum e_obj
// {
// 	WALL = 1,
// 	FLOOR = 0,
// 	PLAYER = 'P'
// }	t_obj;

#endif

