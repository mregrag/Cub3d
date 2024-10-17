/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:20:28 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/04 15:12:46 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rendered(void *param)
{
	t_cube	*cube;

	cube = param;
	ft_clear_img(cube->img);
	mlx_resize_image(cube->img, cube->window->width, cube->window->height);
	movement(cube, 0, 0);
	raycasting(cube);
}

static void	ft_init_all_null(t_cube *cube)
{
	cube->window = NULL;
	cube->img = NULL;
	cube->textur = NULL;
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	if (argc != 2)
		return (ft_putendl_fd("Error\nmissing map file", 2), 1);
	ft_get_cube(&cube);
	ft_init_all_null(&cube);
	ft_parse_cube(argv[1], &cube);
	ft_init_cube(&cube);
	mlx_loop_hook(cube.window, &rendered, &cube);
	mlx_key_hook(cube.window, &key_press, &cube);
	mlx_loop(cube.window);
	ft_destroy_all(&cube);
	return (EXIT_SUCCESS);
}
