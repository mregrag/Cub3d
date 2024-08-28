/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/28 05:50:33 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mouse_rotate(void *param)
{
	t_cube		*cube;

	cube = param;
	mlx_get_mouse_pos(cube->window, &cube->plyer->m_x, &cube->plyer->m_y);
	cube->plyer->derection += (float)(cube->plyer->m_x - (WIDTH/ 2)) / (HEIGHT / 2);
	mlx_set_mouse_pos(cube->window, (WIDTH / 2), (HEIGHT / 2));
}

void	draw_map(void *ml)
{
	t_cube	*cube;

	cube = ml;
	mlx_delete_image(cube->window, cube->img);
	cube->img = mlx_new_image(cube->window, WIDTH, HEIGHT);
	movement(cube, 0, 0);
	raycasting(cube);
	mlx_image_to_window(cube->window, cube->img, 0, 0);
}

void	init_player(t_cube *cube)
{
	char	c;

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

void	start_the_game(t_map *map)
{
	t_cube	cube;

	cube.map = map;

	cube.map->w_map = 12;
	cube.map->h_map = 7;
	cube.plyer = ft_calloc(sizeof(t_player), 1);
	cube.ray = ft_calloc(sizeof(t_ray), 1);
	cube.window = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	init_player(&cube);
	mlx_loop_hook(cube.window, &draw_map, &cube);
	mlx_key_hook(cube.window, &key_press, &cube);
	mlx_set_cursor_mode(cube.window, MLX_MOUSE_DISABLED);
	// mlx_cursor_hook(cube.window, (void *)mouse_rotate, &cube);
	mlx_loop(cube.window);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc > 1)
		parsing_map(argv[1], &map);
	start_the_game(&map);
	return (EXIT_SUCCESS);
}
