#ifndef CUB3D_H
# define CUB3D_H
#define RGB(r, g, b) ((r << 16) | (g << 8) | b)
#define MAX_MAP_LINES 1000
#define TITLE_SIZE 64
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
#include <math.h>
# include "MLX42/include/MLX42/MLX42.h"


typedef struct s_data
{
	mlx_t 		*mlx;
	mlx_image_t *img;
	mlx_texture_t	*wall[4]; // 0 = north, 1 = south, 2 = west, 3 = east
	mlx_image_t		*wall_img[4];
	char		**map;
	int			width;
	int			height;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor;
	int			ceiling;
	int			n_flag;
	int			we_found;
	int			wall_found;
}	t_data;
typedef struct t_player
{
	double	plain;
	double	dir;
	double	fov;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}	s_player;


char	color_set(char *filename, t_data *data);
char	**cordinates_check(char *filename, t_data *data);
char 	prefix_check(char *filename);
char	dublicate_check(t_data *data);
char 	wall_height_check(t_data *data);
char 	map_witdh_check(t_data *data);
char	map_validation(t_data *data);
char	map_char_check(t_data *data);

int		get_map_height(char **map);
int 	get_map_width(char  **str);

void    render_map(t_data *data);
void    data_init(t_data *data);
void   player_init(s_player *player);
void    raycast_and_draw(t_data *data, s_player *player);

bool    load_image(t_data*texture);
bool	map_down_check(t_data *data, size_t x, size_t y);
bool 	map_right_check(t_data *data, size_t x, size_t y);
bool	map_left_check(t_data *data, size_t x, size_t y);
bool	island_check(t_data *data, size_t y, size_t x);
bool	check_bottom_row(t_data *data);
bool 	map_up_check(t_data *data, size_t x, size_t y);
bool    map_init(t_data *data);
bool    game_init(t_data *data);
bool	texture_load(t_data *texture);
bool    load_map(t_data *data);
bool	walls_set(char *filename, t_data *data);
bool    set_we_ea_walls(t_data *data, char *ptr);
bool    set_no_so_walls(t_data *data, char *ptr);
#endif