
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

    old_dir_x = p->dirX;
    old_plane_x = p->planeX;

    p->dirX = p->dirX * cos(rot) - p->dirY * sin(rot);
    p->dirY = old_dir_x * sin(rot) + p->dirY * cos(rot);

    p->planeX = p->planeX * cos(rot) - p->planeY * sin(rot);
    p->planeY = old_plane_x * sin(rot) + p->planeY * cos(rot);
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
        moveX += data->player->dirX * speed;
        moveY += data->player->dirY * speed;
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_S))
    {
        moveX -= data->player->dirX * speed;
        moveY -= data->player->dirY * speed;
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_A))
    {
        moveX -= data->player->dirY * speed;
        moveY += data->player->dirX * speed;
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_D))
    {
        moveX += data->player->dirY * speed;
        moveY -= data->player->dirX * speed;
    }
    if (is_free_tile(data, (int)(data->player->posX + moveX), (int)data->player->posY))
        data->player->posX += moveX;
    if (is_free_tile(data, (int)data->player->posX, (int)(data->player->posY + moveY)))
        data->player->posY += moveY;
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
