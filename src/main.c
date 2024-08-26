/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/26 10:19:12 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_map(void *ml)
{
	t_mlx	*mlx;

	mlx = ml;
	mlx_delete_image(mlx->win, mlx->img);
	mlx->img = mlx_new_image(mlx->win, WIDTH, HEIGHT);
	movement(mlx, 0, 0);
	raycasting(mlx);
	mlx_image_to_window(mlx->win, mlx->img, 0, 0);
}

void	init_player(t_mlx *mlx)
{
	char	c;

	c = mlx->map->map2d[mlx->map->p_y][mlx->map->p_x];
	if (c == 'E')
		mlx->plyer->derection = 0;
	if (c == 'N')
		mlx->plyer->derection = (3 * M_PI) / 2;
	if (c == 'W')
		mlx->plyer->derection = M_PI;
	if (c == 'S')
		mlx->plyer->derection = M_PI / 2;
	mlx->plyer->plyr_x = (mlx->map->p_x * TILE_SIZE) + TILE_SIZE / 2;
	mlx->plyer->plyr_y = (mlx->map->p_y * TILE_SIZE) + TILE_SIZE / 2;
	mlx->plyer->fov = (FOV * M_PI / 180);
}

void	start_the_game(t_map *map)
{
	t_mlx	mlx;

	mlx.map = map;

	mlx.map->w_map = 12;
	mlx.map->h_map = 7;
	mlx.plyer = ft_calloc(sizeof(t_player), 1);
	mlx.rays = ft_calloc(sizeof(t_ray), 1);
	mlx.win = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	init_player(&mlx);
	mlx_loop_hook(mlx.win, &draw_map, &mlx);
	mlx_key_hook(mlx.win, &key_press, &mlx);
	mlx_loop(mlx.win);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc > 1)
		parsing_map(argv[1], &map);
	start_the_game(&map);
	return (EXIT_SUCCESS);
}
