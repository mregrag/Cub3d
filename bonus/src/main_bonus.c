/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/18 16:27:33 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mouse_rotate(void *param)
{
	t_cube	*cube;

	cube = param;
	mlx_get_mouse_pos(cube->window, &cube->plyer->m.x, &cube->plyer->m.y);
	cube->plyer->derection += (float)(cube->plyer->m.x - (WIDTH / 2)) / (HEIGHT / 2);
	mlx_set_mouse_pos(cube->window, (WIDTH / 2), (HEIGHT / 2));
}

void	rendered(void *param)
{
	static int	i=0;
	static int	j=0;
	t_cube		*cube;

	cube = param;
	ft_clear_img(cube->img);
	ft_clear_img(cube->img2);
	mlx_resize_image(cube->img, cube->window->width, cube->window->height);
	mlx_resize_image(cube->img2, cube->window->width / 4 , cube->window->height / 2);
	cube->ray = ft_malloc(sizeof(t_ray) * cube->window->width, 1);
	movement(cube, 0, 0);
	raycasting(cube);
	draw_minimap(cube);
	draw_player(cube);
	ft_sprites(cube, &i, &j);
	// minimap_debug(cube);
	// draw_player_dg(cube);
	// draw_rays_dg(cube);
	// draw_grid_dg(cube);
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
	mlx_set_mouse_pos(cube.window, WIDTH / 2, HEIGHT / 2);
	// mlx_set_cursor_mode(cube.window, MLX_MOUSE_DISABLED);
	// mlx_cursor_hook(cube.window, (void *)mouse_rotate, &cube);
	mlx_loop(cube.window);
	ft_destroy_all(&cube);
	return (EXIT_SUCCESS);
}
