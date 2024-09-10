/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:56:54 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/31 18:44:29 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_ceiling(t_cube *cube, int ray, int ceiling_end)
{
	int		i;
	int		color;

	color = ft_get_color(192, 192, 192, 255);
	i = 0;
	while (i < ceiling_end)
		my_mlx_pixel_put(cube, ray, i++, color);
}

void	draw_wall(t_cube *cube, int ray, int wall_start, int wall_end)
{
	int		i;
	int		color;

	color = ft_get_color(0, 0, 25, 255);
	i = wall_start;
	while (i < wall_end)
		my_mlx_pixel_put(cube, ray, i++, color);
}

void	draw_floor(t_cube *cube, int ray, int floor_start)
{
	int		i;
	int		color;

	color = ft_get_color(0, 204, 204, 255);
	i = floor_start;
	while (i < cube->window->height)
		my_mlx_pixel_put(cube, ray, i++, color);
}

void	projected_wall(t_cube *cube, t_ray *ray, int index)
{
	double	wall_height;
	double	disproplan;
	double	angle;
	int		wall_top;
	int		wall_bottom;

	angle = normalize_angle(ray->angl - cube->plyer->derection);
	ray->distance *= cos(normalize_angle(angle));
	disproplan = (cube->window->width / 2) / tan(cube->plyer->fov / 2);
	wall_height = (TILE_SIZE / ray->distance) * disproplan;
	wall_bottom = (cube->window->height / 2) + (wall_height / 2);
	wall_top = (cube->window->height / 2) - (wall_height / 2);
	if (wall_bottom > cube->window->height)
		wall_bottom = cube->window->height;
	if (wall_top < 0)
		wall_top = 0;
	draw_ceiling(cube, index, wall_top);
	draw_wall(cube, index, wall_top, wall_bottom);
	draw_floor(cube, index, wall_bottom);
}
