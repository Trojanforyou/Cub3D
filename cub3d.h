# ifndef CUB3D_H
# define CUB3D_H
#define RGB(r, g, b) ((0xFF << 24) | ((r) << 16) | ((g) << 8) | (b))
#define MAX_MAP_LINES 1000
#define TITLE_SIZE 64
#define MINIMAP_SIZE 10
#define OFFSET_X 0
#define OFFSET_Y 0
#define MAP_WIDTH 1920
#define MAP_HEIGHT 1080
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_data s_data;

typedef struct t_point
{
    double x;
    double y;
} s_point;

typedef struct t_ipoint
{
    int x;
    int y;
} s_ipoint;

typedef struct t_player
{
	s_point	pos;   // Player's position in the map
	double	speed; // Player's speed
	s_point	dir;   // Player's direction vector
	s_point	plane; // Camera plane (perpendicular to direction)
	s_data  *data;
} s_player;

typedef struct s_data
{
	mlx_t 		*mlx;
	mlx_image_t *img;
	mlx_texture_t	*wall[5]; // 0 = north, 1 = south, 2 = west, 3 = east
	mlx_image_t		*wall_img[5];
	mlx_image_t		*minimap_i;
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
	char		**tmp_floor;
	char		**tmp_ceiling;
	int			we_flag;
	int			no_flag;
	int			ea_flag;
	int			so_flag;
	int			wall_found;
	int			door_flag;
	s_player	*player;
}	t_data;

typedef struct Ray
{
    s_point rayDir;       // component of ray direction
    s_point sideDist;     // Distance to next side
    s_point deltaDist;    // Distance between sides
    double perpWallDist;  // Perpendicular distance to wall
    s_ipoint map;         // Current map square
    s_point step;         // Step direction
    int side;             // 0 = vertical wall, 1 = horizontal wall
    int hit;              // 0 = no wall, 1 = wall hit
} s_Ray;

typedef struct s_stripe
{
    int	drawStart;
    int	drawEnd;
    int	lineHeight;
    int	texX;
    int	x;
} s_stripe;

/* ===================== PARSING / MAP ===================== */

char	color_set(char *filename, t_data *data);
char	**map_reader(char *filename, t_data *data);
char	**cordinates_check(char *filename, t_data *data);
char	prefix_check(char *filename);
char	dublicate_check(t_data *data);
char	map_validation(t_data *data);
char	map_char_check(t_data *data);
char	wall_height_check(t_data *data);
char	map_witdh_check(t_data *data);

char	**trim_floor(char **floor);
char	**trim_celing(char **ceiling);
char	**set_map(char *line, int fd, t_data *data, char **temp, int *i);

bool	load_map(t_data *data);
bool	map_init(t_data *data);
bool	additional_check(char *line, t_data *data);
bool	collums_check(t_data *data);
bool	island_check(t_data *data, size_t y, size_t x);

bool	map_up_check(t_data *data, size_t x, size_t y);
bool	map_down_check(t_data *data, size_t x, size_t y);
bool	map_left_check(t_data *data, size_t x, size_t y);
bool	map_right_check(t_data *data, size_t x, size_t y);
bool	check_bottom_row(t_data *data);

int		get_map_height(char **map);
int		get_map_width(char **str);

/* ===================== TEXTURES / COLORS ===================== */

bool	set_walls_texture(t_data *data, char *ptr);
bool	walls_set(char *filename, t_data *data);

bool	parse_floor(char *path, t_data *data, char **tmp_floor);
bool	parse_ceiling(char *path, t_data *data, char **tmp_ceiling);
bool	floor_error_check(char **floor);
bool	ceiling_error_check(char **ceiling);
bool	set_collor(t_data *data, int y, int x);

bool	texture_load(t_data *texture);
bool	load_image(t_data *texture);

/* ===================== INIT / CLEAN ===================== */

void	data_init(t_data *data);
void	clean_data(t_data *data);
void	clean_ceiling(t_data *data);
void	clean_floor(char **data);
void    change_perspective(t_data *data);
bool	game_init(t_data *data, s_player *player);
void	game_loop(void *param);

/* ===================== WINDOW / RENDER ===================== */

bool	window_witdh(t_data *data);
bool	window_hight(t_data *data);

void	render_map(t_data *data);
bool	put_pixel(t_data *data, int x, int y, int color);

/* ===================== MINIMAP ===================== */

bool	set_minimap_img(t_data *data);
bool	draw_minimap(t_data *data);

/* ===================== PLAYER ===================== */

int		player_init(s_player *player, t_data *data);
void	clear_screen(t_data *data);
void	move_player(t_data *data);
void	mouse_look(t_data *data);
void	arrow_look(t_data *data);
void	open_the_door(t_data *data, s_player *player);

/* ===================== RAYCASTING ===================== */

void	raycast_and_draw(t_data *data, s_player *player);

/* ray init */
void	init_ray(s_Ray *ray, s_player *player, int x, int width);
void	calculate_step_and_side_dist(s_Ray *ray, s_player *player);

/* ray calc */
void	DDA_loop(s_Ray *ray, t_data *data);
void	calculate_perp_wall_dist(s_Ray *ray, s_player *player);

#endif
