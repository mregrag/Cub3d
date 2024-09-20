/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:21:31 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/19 21:07:03 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_player(t_cube *cube)
{
	char	c;

	cube->plyer = ft_malloc(sizeof(t_player), 1);
	c = cube->map->map2d[cube->map->p.y][cube->map->p.x];
	if (c == 'E')
		cube->plyer->derection = 0;
	if (c == 'N')
		cube->plyer->derection = (3 * M_PI) / 2;
	if (c == 'W')
		cube->plyer->derection = M_PI;
	if (c == 'S')
		cube->plyer->derection = M_PI / 2;
	cube->plyer->s.x = (cube->map->p.x * TILE_SIZE) + TILE_SIZE / 2;
	cube->plyer->s.y = (cube->map->p.y * TILE_SIZE) + TILE_SIZE / 2;
	cube->plyer->fov = FOV * (M_PI / 180);
}

void	ft_init_cube(t_cube *cube)
{
	int32_t			w_wi;
	int32_t			w_he;

	cube->window = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!cube->window)
		ft_error("Error\nfailed to create window");
	(1 && (w_wi = cube->window->width, w_he = cube->window->height));
	cube->img = mlx_new_image(cube->window, w_wi, w_he);
	if (!cube->img)
		ft_error("Error\nfailed to create image");
	cube->ray = ft_malloc(sizeof(t_ray), 1);
	ft_load_txtrs(cube);
	if (mlx_image_to_window(cube->window, cube->img, 0, 0) == -1)
		ft_error("Error\nfailed to put image to window");
	init_player(cube);
}
