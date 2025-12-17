
#include "../cub3d.h"

void    move_forward(s_player *player)
{
    double newX;
    double newY;
    double buffer;

    newX = player->posX + player->dirX * player->speed;
    newY = player->posY + player->dirY * player->speed;
    buffer = 0.2;

    if (player->data->map[(int)(newY + buffer)][(int)(player->posX)] == '0')
        player->posY = newY;
    if (player->data->map[(int)(player->posY)][(int)(newX + buffer)] == '0')
        player->posX = newX;
}

int key_press(int keycode, void *param)
{
    t_data *data = (t_data *)param;

    if (keycode == KEY_W)
        data->keys.w = 1;
    if (keycode == KEY_ESC)
        exit(0);

    return (0);
}
int key_release(int keycode, void *param)
{
    t_data *data = (t_data *)param;

    if (keycode == KEY_W)
        data->keys.w = 0;

    return (0);
}