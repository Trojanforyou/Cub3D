/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:17:09 by msokolov          #+#    #+#             */
/*   Updated: 2026/01/17 13:14:55 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	clear_screen(t_data *data)
{
	size_t	size;

	if (!data || !data->img || !data->img->pixels)
		return ;
	size = (size_t)data->img->width * (size_t)data->img->height * 4;
	memset(data->img->pixels, 0, size);
}

void	game_loop(void *param)
{
	t_data	*data;

	data = param;
	move_player(data);
	mouse_look(data);
	arrow_look(data);
	clear_screen(data);
	raycast_and_draw(data, data->player);
	draw_minimap(data);
}
void	find_player(t_data *data, s_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				player->pos.x = x;
				player->pos.y = y;
			}
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	s_player	player;

	if (ac < 2)
		return (printf("Program requires MORE than 2 arguments\n"), 1);
	if (prefix_check(av[1]))
		return (-1);
	data_init(&data);
	if (!map_reader(av[1], &data))
		return (clean_data(&data), -1);
	if (!map_init(&data))
		return (clean_data(&data), -1);
	find_player(&data, &player);
	if (!player_init(&player, &data))
		return (clean_data(&data), -1);
	if (!game_init(&data, &player))
		return (printf("Game init failed\n"), -1);
	clean_data(&data);
	return 0;
}

/*

Summary — Statement of Facts (concise, formal)

Whereas the file main.c constitutes the program’s entry point and orchestration logic, it performs the following actions in sequence:

Procures a heap-allocated s_player (player = malloc(...)). On allocation failure, logs and exits with code 1.
Validates invocation arguments (if (ac < 2)) and returns with a printed message on failure (returns 1).
Performs filename/extension check via prefix_check(av[1]); nonzero result produces an immediate return -1.
Initializes stack t_data data with data_init(&data).
Attempts to read (map_reader) and validate (map_init) the map; on failure frees player, calls clean_data(&data), and returns -1.
Locates the player marker 'P' in find_player and assigns player->pos (the scan does not stop on first match; last occurrence wins).
Calls player_init(player, &data) and on failure frees player and returns -1 (no clean_data in this branch).
Calls game_init(&data, player); on failure prints error and returns -1 (no cleanup performed here).
On successful initialization, calls clean_data(&data), frees player, and exits with status 0.
Findings and Legal Observations

The file fairly and clearly delegates responsibilities: clear_screen zeroes the framebuffer; game_loop performs per-frame updates (movement, view, raycasting, minimap).
Error handling is inconsistent: some failure branches free both player and data (map_reader, map_init), other branches free only player (player_init), and some branches perform no cleanup (prefix_check, game_init), creating a risk of resource leaks.
The argument-check message is misleading: code checks ac < 2 but prints "Program requires MORE than 2 arguments" (logical mismatch).
find_player may leave player->pos unset if no 'P' exists; it does not guard against multiple 'P' markers (last occurrence dominates).
Return codes are used, but not uniformly documented; some branches return 1, some return -1 on error—this could confuse callers or test harnesses.

Recommendations (remedial directives)

Normalize cleanup on all error paths (ensure clean_data(&data) and free(player) are invoked where appropriate).
Correct the argument-check message and/or the conditional to reflect intended usage.
Make find_player stop on first match or explicitly validate exactly one 'P' and fail with a clear error if the map is invalid.
Consider consistent and documented exit codes for different error classes.
Conclusion

The file performs initialization, validation, player discovery, and game startup competently but exhibits uneven error handling and minor correctness/robustness issues that should be remedied to avoid resource leaks and ambiguous behavior.



Collecting workspace information

Summary: each screen column is traced as a ray through the map (DDA), the first wall hit is found, perpendicular distance is computed, a vertical slice is textured and drawn.

Step-by-step (with code links)

Per-column loop: raycast_and_draw iterates x and starts a ray for each column.
Build ray: init_ray computes cameraX and the ray direction from s_player->dir and ->plane.
Setup steps: calculate_step_and_side_dist computes ray->step and initial sideDist using the delta() helper.
Grid traversal: DDA_loop advances the ray cell-by-cell until it hits a non-'0' tile (map read from data->map) and sets ray->side and ray->hit.
Distance correction: calculate_perp_wall_dist computes perpWallDist (avoids fish-eye).
Slice & texture: draw_textured_wall / draw_vertical_stripe compute stripe.lineHeight, drawStart/drawEnd, fractional wallX → tex X (stripe.texX); decide_ray_hit_texture selects N/S/W/E texture stored in t_data.
Frame: game_loop calls the raycaster each frame after inputs and clear_screen.
Notes

Ray struct: see s_Ray and stripe: s_stripe.
Texturing is done per-pixel with mlx_put_pixel (commented “slow should replace with direct change”) — for performance write directly into data->img->pixels.
Want a line-by-line trace of one column’s ray through the above functions?
*/