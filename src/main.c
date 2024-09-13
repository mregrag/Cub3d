/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/13 12:08:26 by aait-bab         ###   ########.fr       */
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

t_cube	*get_cube(t_cube *cube)
{
	static t_cube	*s_cube;

	if (cube)
		s_cube = cube;
	return (s_cube);
}


void leak(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_cube	cube;
	int i = 0;

	atexit(leak);
	if (argc != 2)
		return (print_fd("Error\nmissing map file", 2), 1);
	get_cube(&cube);
	ft_parse_cube(argv[1], &cube);

	printf("textures\n");
	for (i = 0; i < 4; i++)
	{
		printf("%s   %s\n",cube.txtrs[i]->key, cube.txtrs[i]->path);
	}

	printf("colors\n");
	for (i = 0; i < 2; i++)
	{
		printf("%s   %d %d %d\n",cube.colors[i]->key, cube.colors[i]->r, cube.colors[i]->g, cube.colors[i]->b);
	}

	printf("map\n");
	for (i = 0; i < cube.map->rows; i++)
	{
		printf("%s\n", cube.map->map2d[i]);
	}

	// cube.plyer = malloc(sizeof(t_player));
	// cube.window = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	// init_player(&cube);
	// mlx_loop_hook(cube.window, &rendered, &cube);
	// mlx_key_hook(cube.window, &key_press, &cube);
	// mlx_loop(cube.window);
	ft_malloc(0, 0);
	return (EXIT_SUCCESS);
}
