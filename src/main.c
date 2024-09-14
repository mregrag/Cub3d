/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/14 12:21:13 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mouse_rotate(void *param)
{
	t_cube *cube;

	cube = param;
	mlx_get_mouse_pos(cube->window, &cube->plyer->m.x, &cube->plyer->m.y);
	cube->plyer->derection += (float)(cube->plyer->m.x - (WIDTH / 2)) / (HEIGHT / 2);
	mlx_set_mouse_pos(cube->window, (WIDTH / 2), (HEIGHT / 2));
	// mlx_set_cursor_mode(cube.window, MLX_MOUSE_DISABLED);
	// mlx_cursor_hook(cube.window, (void *)mouse_rotate, &cube);
}

void	rendered(void *param)
{
	t_cube	*cube;

	cube = param;
	mlx_resize_image(cube->img, cube->window->width, cube->window->height);
	cube->ray = ft_calloc(sizeof(t_ray), cube->window->width);
	movement(cube, 0, 0);
	raycasting(cube);
	draw_minimap(cube);
	draw_rays(cube);
	draw_player(cube);
	draw_grid(cube);
	// free(cube->ray);
}

int	load_texture(t_cube *cube)
{
	int i = 0;

	while (i < 4 && cube->txtrs[i] && cube->txtrs[i]->key)
	{
		if (!ft_strncmp(cube->txtrs[i]->key, "NO", 2))
			cube->textur->no = mlx_load_png(cube->txtrs[i]->path);
		else if (!ft_strncmp(cube->txtrs[i]->key, "SO", 2))
			cube->textur->so = mlx_load_png(cube->txtrs[i]->path);
		else if (!ft_strncmp(cube->txtrs[i]->key, "WE", 2))
			cube->textur->we = mlx_load_png(cube->txtrs[i]->path);
		else if (!ft_strncmp(cube->txtrs[i]->key, "EA", 2))
			cube->textur->ea = mlx_load_png(cube->txtrs[i]->path);
		i++;
	}
	if (!cube->textur->no || !cube->textur->so || !cube->textur->we || !cube->textur->ea)
	{
		fprintf(stderr, "Not all required textures were loaded\n");
		return 0;
	}
	return 1;
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
	cube->plyer->s.x = (cube->map->p_x * TILE_SIZE) + TILE_SIZE / 2;
	cube->plyer->s.y = (cube->map->p_y * TILE_SIZE) + TILE_SIZE / 2;
	cube->plyer->fov = deg2rad(FOV);
}

t_cube	*get_cube(t_cube *cube)
{
	static t_cube	*s_cube;

	if (cube)
		s_cube = cube;
	return (s_cube);
}


int	main(int argc, char **argv)
{
	t_cube	cube;

	if (argc != 2)
		return (print_fd("Error\nmissing map file", 2), 1);
	get_cube(&cube);
	ft_parse_cube(argv[1], &cube);
	cube.plyer = malloc(sizeof(t_player));
	cube.window = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	cube.textur = malloc(sizeof(t_textur));
	cube.img = mlx_new_image(cube.window, cube.window->width, cube.window->height);
	if(!load_texture(&cube))
		exit(1);
	mlx_image_to_window(cube.window, cube.img, 0, 0);
	init_player(&cube);
	mlx_loop_hook(cube.window, &rendered, &cube);
	mlx_key_hook(cube.window, &key_press, &cube);
	mlx_loop(cube.window);
	ft_malloc(0, 0);
	return (EXIT_SUCCESS);
}
