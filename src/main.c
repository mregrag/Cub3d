/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/31 23:15:40 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mouse_rotate(void *param) {
	t_cube *cube;

	cube = param;
	mlx_get_mouse_pos(cube->window, &cube->plyer->m_x, &cube->plyer->m_y);
	cube->plyer->derection += (float)(cube->plyer->m_x - (WIDTH / 2)) / (HEIGHT / 2);
	mlx_set_mouse_pos(cube->window, (WIDTH / 2), (HEIGHT / 2));
}

void render_walls(t_cube *cube)
{
	t_ray	*ray;
	int	i;

	int	color;


	color = ft_get_color(255, 0, 0, 255);

	i = 0;
	while (i < cube->window->width)
	{
		ray = &cube->rays[i];
		projected_wall(cube, ray, i++);
	}
}

void rendered(void *ml) {
	t_cube *cube;

	cube = ml;
	mlx_delete_image(cube->window, cube->img);
	cube->img = mlx_new_image(cube->window, cube->window->width, cube->window->height);
	cube->rays = ft_calloc(sizeof(t_ray), cube->window->width);
	movement(cube, 0, 0);
	raycasting(cube);
	render_walls(cube);
	draw_minimap(cube);
	draw_player(cube);
	draw_rays(cube);
	draw_grid(cube);

	mlx_image_to_window(cube->window, cube->img, 0, 0);
}

void	init_player(t_cube *cube)
{
	char c;

	c = cube->map->map2d[cube->map->p_y][cube->map->p_x];
	if (c == 'E')
		cube->plyer->derection = 0;
	if (c == 'N')
		cube->plyer->derection = (3 * M_PI) / 2;
	if (c == 'W')
		cube->plyer->derection = M_PI;
	if (c == 'S')
		cube->plyer->derection = M_PI / 2;
	cube->plyer->x = (cube->map->p_x * TILE_SIZE) + TILE_SIZE / 2;
	cube->plyer->y = (cube->map->p_y * TILE_SIZE) + TILE_SIZE / 2;
	cube->plyer->fov = deg2rad(FOV);
}

void	setup_the_game(t_map *map)
{
	t_cube cube;

	cube.map = map;

	cube.plyer = malloc(sizeof(t_player));
	cube.window = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	init_player(&cube);
	mlx_loop_hook(cube.window, &rendered, &cube);
	mlx_key_hook(cube.window, &key_press, &cube);
	mlx_loop(cube.window);
}

int main(int argc, char **argv) {
	t_map map;

	if (argc > 1)
		parsing_map(argv[1], &map);
	setup_the_game(&map);
	return (EXIT_SUCCESS);
}
