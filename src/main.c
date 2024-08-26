/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/26 11:32:12 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_map(void *ml)
{
	t_cube	*cube;

	cube = ml;
	mlx_delete_image(cube->win, cube->img);
	cube->img = mlx_new_image(cube->win, WIDTH, HEIGHT);
	movement(cube, 0, 0);
	raycasting(cube);
	mlx_image_to_window(cube->win, cube->img, 0, 0);
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
	cube->plyer->plyr_x = (cube->map->p_x * TILE_SIZE) + TILE_SIZE / 2;
	cube->plyer->plyr_y = (cube->map->p_y * TILE_SIZE) + TILE_SIZE / 2;
	cube->plyer->fov = (FOV * M_PI / 180);
}

void	start_the_game(t_map *map)
{
	t_cube	cube;

	cube.map = map;

	cube.map->w_map = 12;
	cube.map->h_map = 7;
	cube.plyer = ft_calloc(sizeof(t_player), 1);
	cube.rays = ft_calloc(sizeof(t_ray), 1);
	cube.win = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	init_player(&cube);
	mlx_loop_hook(cube.win, &draw_map, &cube);
	mlx_key_hook(cube.win, &key_press, &cube);
	mlx_loop(cube.win);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc > 1)
		parsing_map(argv[1], &map);
	start_the_game(&map);
	return (EXIT_SUCCESS);
}
