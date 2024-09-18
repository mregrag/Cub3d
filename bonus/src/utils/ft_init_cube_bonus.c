/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cube_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:21:31 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/18 13:41:23 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_player(t_cube *cube)
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
	cube->plyer->fov = FOV * (M_PI / 180);
}

void	ft_init_cube(t_cube *cube)
{
	cube->window = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!cube->window)
		ft_error("Error\nfailed to create window");
	cube->img = mlx_new_image(cube->window, cube->window->width, cube->window->height);
	if (!cube->img)
		ft_error("Error\nfailed to create image");
	cube->img2 = mlx_new_image(cube->window,  120, 120);
	cube->plyer = ft_malloc(sizeof(t_player), 1);
	cube->textur = ft_malloc(sizeof(t_textur), 1);
	cube->shoot = 0;
	// cube->ray = ft_malloc(sizeof(t_ray), 1);
	ft_load_txtrs(cube);
	ft_load_sprites(cube);
	if (mlx_image_to_window(cube->window, cube->img, 0, 0) == -1)
		ft_error("Error\nfailed to put image to window");
	if (mlx_image_to_window(cube->window, cube->img2, 0, 0) == -1)
		ft_error("Error\nfailed to put image to window");
	if (mlx_image_to_window(cube->window, cube->img3, cube->window->width/4,cube->window->height /2) == -1)
		ft_error("Error\nfailed to put image to window");
	int i = 0;
	while (i < 5)
	{
		cube->sprites[i]->img->enabled = false;
		mlx_image_to_window(cube->window, cube->sprites[i]->img,( cube->window->width - cube->sprites[i]->img->width)/2, cube->window->height - cube->sprites[i]->img->height);
		i++;
	}
	cube->sprites[0]->img->enabled = true;
	init_player(cube);
}
