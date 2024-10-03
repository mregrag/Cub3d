/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:01:25 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/01 21:33:25 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static double	vertical_intersect(t_cube *cube)
{
	t_dpoint	inter;
	t_dpoint	delta;

	inter.x = floor(cube->plyer->s.x / TILE_SIZE) * TILE_SIZE;
	if (cube->ray->right)
		inter.x += TILE_SIZE;
	inter.y = cube->plyer->s.y
		+ (inter.x - cube->plyer->s.x) * tan(cube->ray->angl);
	delta.x = TILE_SIZE;
	delta.y = TILE_SIZE * tan(cube->ray->angl);
	adjust_step(cube, &delta, 1);
	while (!is_wall(inter.x - cube->ray->left, inter.y, cube))
	{
		inter.x += delta.x;
		inter.y += delta.y;
	}
	cube->ray->vwall.x = inter.x;
	cube->ray->vwall.y = inter.y;
	return (calcul_distance(inter, cube->plyer->s));
}

static double	horizontal_intersect(t_cube *cube)
{
	t_dpoint	inter;
	t_dpoint	delta;

	inter.y = floor(cube->plyer->s.y / TILE_SIZE) * TILE_SIZE;
	if (cube->ray->down)
		inter.y += TILE_SIZE;
	inter.x = cube->plyer->s.x
		+ (inter.y - cube->plyer->s.y) / tan(cube->ray->angl);
	delta.y = TILE_SIZE;
	delta.x = TILE_SIZE / tan(cube->ray->angl);
	adjust_step(cube, &delta, 0);
	while (!is_wall(inter.x, inter.y - cube->ray->up, cube))
	{
		inter.x += delta.x;
		inter.y += delta.y;
	}
	cube->ray->hwall.x = inter.x;
	cube->ray->hwall.y = inter.y;
	return (calcul_distance(inter, cube->plyer->s));
}

void	raycasting(t_cube *cube)
{
	t_dpoint	distance;

	cube->ray->index = 0;
	cube->ray->angl = cube->plyer->derection - (cube->plyer->fov / 2);
	while (cube->ray->index < cube->window->width)
	{
		cube->ray->angl = normalize_angle(cube->ray->angl);
		check_rayfacing(cube, cube->ray->angl);
		distance.x = horizontal_intersect(cube);
		distance.y = vertical_intersect(cube);
		if (distance.y <= distance.x)
		{
			cube->ray->distance = distance.y;
			cube->ray->was_hit_vertical = 1;
		}
		else
		{
			cube->ray->distance = distance.x;
			cube->ray->was_hit_vertical = 0;
		}
		projected_wall(cube);
		cube->ray->index++;
		cube->ray->angl += (cube->plyer->fov / cube->window->width);
	}
}
