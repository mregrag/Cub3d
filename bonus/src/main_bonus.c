/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/20 10:06:05 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	mouse_rotate(void *param)
{
	t_cube	*cube;
	int		mouse_x;
	int		mouse_y;
	int		dx;

	cube = (t_cube *)param;
	mlx_get_mouse_pos(cube->window, &mouse_x, &mouse_y);
	dx = mouse_x - WIDTH / 2;
	cube->plyer->derection += dx * 0.002;
	cube->plyer->derection = normalize_angle(cube->plyer->derection);
	mlx_set_mouse_pos(cube->window, cube->window->width / 2, cube->window->height / 2);
}

void	rendered(void *param)
{
	static int	i = 0;
	static int	j = 0;
	t_cube		*cube;

	cube = param;
	ft_clear_img(cube->img2);
	ft_clear_img(cube->img);
	mlx_resize_image(cube->img, cube->window->width, cube->window->height);
	mlx_resize_image(cube->img2, cube->window->width, cube->window->height);
	cube->ray = ft_malloc(sizeof(t_ray) * cube->window->width, 1);
	movement(cube, 0, 0);
	raycasting(cube);
	draw_minimap(cube);
	draw_player(cube);
	ft_sprites(cube, &i, &j);
}

void	ft_init_all_null(t_cube *cube)
{
	cube->window = NULL;
	cube->img = NULL;
	cube->img2 = NULL;
	cube->img3 = NULL;
	cube->textur = NULL;
	cube->sprites[0] = NULL;
}

void	foo(void)
{
	system("leaks cub3D_bonus");
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	// atexit(foo);
	if (argc != 2)
		return (print_fd("Error\nmissing map file", 2), 1);
	ft_get_cube(&cube);
	ft_init_all_null(&cube);
	ft_parse_cube(argv[1], &cube);
	ft_init_cube(&cube);
	mlx_loop_hook(cube.window, &rendered, &cube);
	mlx_key_hook(cube.window, &key_press, &cube);
	mlx_set_mouse_pos(cube.window, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor_mode(cube.window, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(cube.window, (void *)mouse_rotate, &cube);
	mlx_loop(cube.window);
	ft_destroy_all(&cube);
	return (EXIT_SUCCESS);
}
