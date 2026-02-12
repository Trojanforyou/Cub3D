/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhan <orhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:49:17 by otanovic          #+#    #+#             */
/*   Updated: 2026/02/12 13:53:55 by orhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_vertical_stripe(mlx_image_t *img, mlx_image_t *tex, t_stripe strip)
{
	int		y;
	int		texy;
	uint8_t	*pixel;
	float	step;
	float	tex_pos;

	step = (float)tex->height / strip.lineheight;
	tex_pos = (strip.drawstart - SCREEN_HEIGHT / 2
			+ strip.lineheight / 2) * step;
	y = strip.drawstart;
	while (y < strip.drawend)
	{
		texy = (int)tex_pos;
		if (texy < 0)
			texy = 0;
		if (texy >= (int)tex->height)
			texy = (int)tex->height - 1;
		pixel = &tex->pixels[4 * (texy * (int)tex->width + strip.texx)];
		mlx_put_pixel(img, strip.x, y,
			((pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3]));
		tex_pos += step;
		y++;
	}
}

void	draw_textured_wall(t_player *pl, mlx_image_t *img, t_ray *ray, int x)
{
	t_stripe	stripe;
	double		wallx;

	stripe.x = x;
	stripe.lineheight = (int)(SCREEN_HEIGHT / ray->perpwalldist);
	stripe.drawstart = -stripe.lineheight / 2 + SCREEN_HEIGHT / 2;
	stripe.drawend = stripe.lineheight / 2 + SCREEN_HEIGHT / 2;
	if (stripe.drawstart < 0)
		stripe.drawstart = 0;
	if (stripe.drawend >= SCREEN_HEIGHT)
		stripe.drawend = SCREEN_HEIGHT - 1;
	if (ray->side == 0)
		wallx = pl->pos.y + ray->perpwalldist * ray->raydir.y;
	else
		wallx = pl->pos.x + ray->perpwalldist * ray->raydir.x;
	wallx -= floor(wallx);
	stripe.texx = (int)(wallx * pl->data->wall_img[ray->hit]->width);
	if ((ray->side == 0 && ray->raydir.x > 0)
		|| (ray->side == 1 && ray->raydir.y < 0))
		stripe.texx = pl->data->wall_img[ray->hit]->width - stripe.texx - 1;
	draw_vertical_stripe(img, pl->data->wall_img[ray->hit], stripe);
}

void	raycast_and_draw(t_data *data, t_player *player)
{
	mlx_image_t	*img;
	t_ray		ray;
	int			x;

	img = data->img;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray(&ray, player, x, SCREEN_WIDTH);
		calculate_step_and_side_dist(&ray, player);
		dda_loop(&ray, data);
		if (ray.hit >= 0 && ray.hit <= 4 && player->data->wall_img[ray.hit])
		{
			calculate_perp_wall_dist(&ray, player);
			draw_textured_wall(player, img, &ray, x);
		}
		x++;
	}
}
