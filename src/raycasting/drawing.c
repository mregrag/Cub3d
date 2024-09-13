/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:56:54 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/13 11:12:44 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdio.h>

void	draw_ceiling(t_cube *cube, int ray, int ceiling_end)
{
	int		i;
	int		color;

	color = ft_get_color(192, 192, 192, 255);
	i = 0;
	while (i < ceiling_end)
		my_mlx_pixel_put(cube, ray, i++, color);
}


// double	calculate_texture_x(mlx_texture_t *texture, t_cube *cube)
// {
// 	double	x;
//
// 	if (cube->ray->flag == 0) // Horizontal wall hit
// 		x = (int)fmodf((cube->ray->hwall.x * \
// 		(texture->width / TILE_SIZE)), texture->width);
// 	else
// 		x = (int)fmodf((cube->ray->vwall.y * \
// 		(texture->width / TILE_SIZE)), texture->width);
// 	return (x);
// }

double	calculate_texture_x(mlx_texture_t *texture, t_cube *cube)
{
	double x;

	if (cube->ray->flag == 0)  // Horizontal wall hit
	{
		x = cube->ray->hwall.x;
		if (cube->ray->right)
			x = TILE_SIZE - fmod(x, TILE_SIZE);
		else
			x = fmod(x, TILE_SIZE);
	}
	else  // Vertical wall hit
	{
		x = cube->ray->vwall.y;
		if (cube->ray->up)
			x = TILE_SIZE - fmod(x, TILE_SIZE);
		else
			x = fmod(x, TILE_SIZE);
	}

	// Scale to texture size
	x = (x * texture->width) / TILE_SIZE;

	return x;
}

void	draw_wall(t_cube *cube, int wall_t, int wall_b, double wall_h)
{
	t_dpoint	textoffset;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

	texture = cube->textur->no;
	arr = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	textoffset.x = calculate_texture_x(texture, cube);
	textoffset.y = (wall_t - (cube->window->height / 2) + (wall_h / 2)) * factor;
	if (textoffset.y < 0)
		textoffset.y = 0;
	while (wall_t < wall_b)
	{
		my_mlx_pixel_put(cube, cube->ray->index, wall_t, reverse_bytes \
		(arr[(int)textoffset.y * texture->width + (int)textoffset.x]));
		textoffset.y += factor;
		wall_t++;
	}
}

void	draw_floor(t_cube *cube, int ray, int floor_start)
{
	int		color;

	color = ft_get_color(0, 0, 0, 255);
	while (floor_start < cube->window->height)
		my_mlx_pixel_put(cube, ray, floor_start++, color);
}

void	projected_wall(t_cube *cube, t_ray *ray, int index)
{
	double	wall_h;
	double	disproplan;
	int		wall_t;
	int		wall_b;

	ray->distance *= cos(normalize_angle(ray->angl - cube->plyer->derection));

	disproplan = (cube->window->width / 2) / tan(cube->plyer->fov / 2);
	wall_h = (TILE_SIZE / ray->distance) * disproplan;
	wall_b = (cube->window->height / 2) + (wall_h / 2);
	wall_t = (cube->window->height / 2) - (wall_h / 2);
	if (wall_b > cube->window->height)
		wall_b = cube->window->height;
	if (wall_t < 0)
		wall_t = 0;
	draw_ceiling(cube, index, wall_t);
	cube->ray->index = index;
	draw_wall(cube, wall_t, wall_b, wall_h);
	draw_floor(cube, index, wall_b);
}

