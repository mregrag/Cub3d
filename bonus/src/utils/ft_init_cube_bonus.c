/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cube_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:21:31 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/18 15:00:27 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_window_imgs(t_cube *cube)
{
	mlx_texture_t	*red_p;
	int32_t			w_wi;
	int32_t			w_he;

	cube->window = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!cube->window)
		ft_error("Error\nfailed to create window");
	(1 && (w_wi = cube->window->width, w_he = cube->window->height));
	cube->img = mlx_new_image(cube->window, w_wi, w_he);
	if (!cube->img)
		ft_error("Error\nfailed to create image");
	cube->img2 = mlx_new_image(cube->window, 120, 120);
	if (!cube->img2)
		ft_error("Error\nfailed to create image");
	red_p = mlx_load_png("assets/sprites/point.png");
	if (!red_p)
		ft_error("Error\nfailed to load image");
	cube->img3 = mlx_texture_to_image(cube->window, red_p);
	if (!cube->img3)
		ft_error("Error\nfailed to load image");
	mlx_delete_texture(red_p);
}

static void	set_up_imgs_pos(t_cube *cube)
{
	int	i;
	int	w_wi;
	int	w_he;
	int	img_w;
	int	img_h;

	(1 && (i = 0, w_wi = cube->window->width, w_he = cube->window->height));
	if (mlx_image_to_window(cube->window, cube->img, 0, 0) == -1)
		ft_error("Error\nfailed to put image to window");
	if (mlx_image_to_window(cube->window, cube->img2, 0, 0) == -1)
		ft_error("Error\nfailed to put image to window");
	if (mlx_image_to_window(cube->window, cube->img3, w_wi / 4, w_he / 2) == -1)
		ft_error("Error\nfailed to put image to window");
	while (i < 5)
	{
		cube->sprites[i]->img->enabled = false;
		img_w = (w_wi - cube->sprites[i]->img->width) / 2;
		img_h = w_he - cube->sprites[i]->img->height;
		mlx_image_to_window(cube->window, cube->sprites[i]->img, img_w, img_h);
		i++;
	}
	cube->sprites[0]->img->enabled = true;
}

static void	init_player(t_cube *cube)
{
	char	c;

	cube->plyer = ft_malloc(sizeof(t_player), 1);
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
	init_window_imgs(cube);
	ft_load_txtrs(cube);
	ft_load_sprites(cube);
	set_up_imgs_pos(cube);
	init_player(cube);
}
