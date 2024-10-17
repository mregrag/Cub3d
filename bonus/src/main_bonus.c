/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/04 15:13:03 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	rendered(void *param)
{
	t_cube		*cube;

	cube = param;
	mlx_resize_image(cube->img, cube->window->width, cube->window->height);
	raycasting(cube);
	movement(cube, 0, 0);
	ft_sprites(cube);
	draw_minimap(cube);
}

void	ft_init_all_null(t_cube *cube)
{
	cube->window = NULL;
	cube->img = NULL;
	cube->img3 = NULL;
	cube->textur = NULL;
	cube->sprites[0] = NULL;
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
	mlx_cursor_hook(cube.window, (void *)mouse_event, &cube);
	mlx_loop(cube.window);
	ft_destroy_all(&cube);
	return (EXIT_SUCCESS);
}
