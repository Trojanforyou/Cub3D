
#include "../cub3d.h"

static int is_free_tile(t_data *data, int x, int y)
{
    if (x < 0 || y < 0 || x >= data->width || y >= data->height)
        return 0;
    return data->map[y][x] == '0';
}

void    rotate_camera(s_player *p, double rot)
{
    double  old_dir_x;
    double  old_plane_x;

    old_dir_x = p->dir.x;
    old_plane_x = p->plane.x;

    p->dir.x = p->dir.x * cos(rot) - p->dir.y * sin(rot);
    p->dir.y = old_dir_x * sin(rot) + p->dir.y * cos(rot);

    p->plane.x = p->plane.x * cos(rot) - p->plane.y * sin(rot);
    p->plane.y = old_plane_x * sin(rot) + p->plane.y * cos(rot);
}

void    arrow_look(t_data *data)
{
    if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
        rotate_camera(data->player, 0.1);
    if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
        rotate_camera(data->player, -0.1);
}

void move_player(t_data *data)
{
    double moveX;
    double moveY;
    double speed;

    moveX = 0.0;
    moveY = 0.0;
    speed = data->player->speed;
    if (mlx_is_key_down(data->mlx, MLX_KEY_W))
    {
        moveX += data->player->dir.x * speed;
        moveY += data->player->dir.y * speed;
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_S))
    {
        moveX -= data->player->dir.x * speed;
        moveY -= data->player->dir.y * speed;
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_A))
    {
        moveX -= data->player->dir.y * speed;
        moveY += data->player->dir.x * speed;
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_D))
    {
        moveX += data->player->dir.y * speed;
        moveY -= data->player->dir.x * speed;
    }
    if (is_free_tile(data, (int)(data->player->pos.x + moveX), (int)data->player->pos.y))
        data->player->pos.x += moveX;
    if (is_free_tile(data, (int)data->player->pos.x, (int)(data->player->pos.y + moveY)))
        data->player->pos.y += moveY;
}

void mouse_look(t_data *data)
{
    int     x;
    int     y;
    int     cx;
    int     cy;
    double  dx;

    cx = data->width / 2;
    cy = data->height / 2;
    mlx_get_mouse_pos(data->mlx, &x, &y);
    dx = x - cx;
    if (dx > 1 || dx < -1)
        rotate_camera(data->player, dx * 0.002);
    mlx_set_mouse_pos(data->mlx, cx, cy);
}
