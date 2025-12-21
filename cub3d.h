#ifndef CUB3D_H
# define CUB3D_H
#define RGB(r, g, b) ((0xFF << 24) | ((r) << 16) | ((g) << 8) | (b))
#define MAX_MAP_LINES 1000
#define TITLE_SIZE 64
#define MINIMAP_SIZE 10
#define OFFSET_X -8
#define OFFSET_Y -10
#define MAP_WITDH 1600
#define MAP_HEIGHT 900
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
	mlx_image_t *img;
	mlx_texture_t	*wall[4]; // 0 = north, 1 = south, 2 = west, 3 = east
	mlx_image_t		*wall_img[4];
	mlx_image_t		*minimap_i;
	char		**map;
	int			witdh;
	int			height;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor;
	int			ceiling;
	int			n_flag;
	int			wall_found;
	char		**tmp_floor;
	char		**tmp_ceiling;
	int			we_flag;
	int			no_flag;
	int			ea_flag;
	int			so_flag;
	
}	t_data;
typedef struct t_player
{
	double	plain;
	double	dir;
	double	fov;
}	s_player;


char	color_set(char *filename, t_data *data);
char	**map_reader(char *filename, t_data *data);
char 	prefix_check(char *filename);
char	dublicate_check(t_data *data);
char	map_validation(t_data *data);
char	map_char_check(t_data *data);
char	**trim_floor(char **floor);
char    **trim_celing(char **ceiling);

int		get_map_height(char **map);
int 	get_map_width(char  **str);


void    data_init(t_data *data);

bool	collums_check(t_data *data);
bool    load_image(t_data*texture);
bool	map_down_check(t_data *data, size_t x, size_t y);
bool 	map_right_check(t_data *data, size_t x, size_t y);
bool	map_left_check(t_data *data, size_t x, size_t y);
bool	island_check(t_data *data, size_t y, size_t x);
bool 	map_up_check(t_data *data, size_t x, size_t y);
bool    map_init(t_data *data);
bool    game_init(t_data *data);
bool	texture_load(t_data *texture);
bool    load_map(t_data *data);
bool    set_walls_texture(t_data *data, char *ptr);
bool	ceiling_error_check(char ** ceiling);
bool	floor_error_check(char **floor);
bool	additional_check(char *line, t_data *data);
bool 	parse_floor(char *path, t_data *data, char **tmp_floor);
bool 	parse_ceiling(char *path, t_data *data, char **tmp_ceiling);
bool	window_witdh(t_data *data);
bool	window_hight(t_data *data);
bool    set_minimap_img(t_data *data);
bool    draw_minimap(t_data *data);
bool    put_pixel(t_data *data, int x, int y, int color);

#endif
