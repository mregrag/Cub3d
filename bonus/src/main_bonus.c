/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/16 17:44:44 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rendered(void *param)
{
	t_cube	*cube;

	cube = param;
	ft_clear_img(cube->img);
	mlx_resize_image(cube->img, cube->window->width, cube->window->height);
	cube->ray = ft_malloc(sizeof(t_ray) * cube->window->width, 1);
	movement(cube, 0, 0);
	raycasting(cube);
	minimap_debug(cube);
	draw_player(cube);
	draw_rays(cube);
	draw_grid(cube);
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	if (argc != 2)
		return (print_fd("Error\nmissing map file", 2), 1);
	ft_get_cube(&cube);
	ft_parse_cube(argv[1], &cube);
	ft_init_cube(&cube);
	mlx_loop_hook(cube.window, &rendered, &cube);
	mlx_key_hook(cube.window, &key_press, &cube);
	mlx_loop(cube.window);
	ft_destroy_all(&cube);
	return (EXIT_SUCCESS);
}
