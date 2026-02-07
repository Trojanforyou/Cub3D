/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:49:17 by otanovic          #+#    #+#             */
/*   Updated: 2026/02/03 14:26:23 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//raycast_and_draw
//│
//├─ init_ray                // math setup
//├── calculate_step_and_side // grid stepping setup
//├── DDA_loop                // map collision
//├── calculate_perp_dist     // camera correction
//└── draw_textured_wall      // rendering only

// seg faultin here for
// whenever I go past the last walls so its due to reading
// from the map past a valid place
// DDA loop: marches ray through the map until a wall is hit

void	draw_vertical_stripe(mlx_image_t *img, mlx_image_t *tex, t_stripe strip)
{
	int			y;
	int			texy;
	uint8_t		*pixel;
	uint32_t	color;

	y = strip.drawstart;
	while (y < strip.drawend)
	{
		texy = ((y - strip.drawstart) * (int)tex->height) / strip.lineheight;
		if (texy < 0)
			texy = 0;
		if (texy >= (int)tex->height)
			texy = (int)tex->height - 1;
		pixel = &tex->pixels[4 * (texy * (int)tex->width + strip.texx)];
		color = (pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8)
			| pixel[3];
		mlx_put_pixel(img, strip.x, y++, color);
	}
}

void	draw_textured_wall(t_player *pl, mlx_image_t *img, t_ray *ray, int x)
{
	t_stripe	stripe;
	double		wallx;

	stripe.x = x;
	stripe.lineheight = (int)(MAP_HEIGHT / ray->perpWallDist);
	stripe.drawstart = -stripe.lineheight / 2 + MAP_HEIGHT / 2;
	stripe.drawend = stripe.lineheight / 2 + MAP_HEIGHT / 2;
	if (stripe.drawstart < 0)
		stripe.drawstart = 0;
	if (stripe.drawend >= MAP_HEIGHT)
		stripe.drawend = MAP_HEIGHT - 1;
	if (ray->side == 0)
		wallx = pl->pos.y + ray->perpWallDist * ray->rayDir.y;
	else
		wallx = pl->pos.x + ray->perpWallDist * ray->rayDir.x;
	wallx -= floor(wallx);
	stripe.texx = (int)(wallx * pl->data->wall_img[ray->hit]->width);
	if ((ray->side == 0 && ray->rayDir.x > 0)
		|| (ray->side == 1 && ray->rayDir.y < 0))
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
	while (x < MAP_WIDTH)
	{
		init_ray(&ray, player, x, MAP_WIDTH);
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
