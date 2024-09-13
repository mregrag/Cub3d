/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 07:08:14 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/13 06:15:27 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static double	vertical_intersect(t_cube *cube)
{
	t_dpoint	inter;
	t_dpoint	delta;

	cube->ray->angl = normalize_angle(cube->ray->angl);
	inter.x = floor(cube->plyer->s.x / TILE_SIZE) * TILE_SIZE;
	inter.x += TILE_SIZE * cube->ray->right;
	inter.y = cube->plyer->s.y + (inter.x - cube->plyer->s.x) * tan(cube->ray->angl);
	delta.x = TILE_SIZE;
	delta.y = TILE_SIZE * tan(cube->ray->angl);
	adjust_step(cube, &delta.x, &delta.y, 1);
	while(inter.x >= 0 && inter.x <= cube->window->width && inter.y >= 0 && inter.y <= cube->window->height)
	{
		if (hit_wall(inter.x - cube->ray->left, inter.y, cube))
		{
			cube->ray->vwall.x = inter.x;
			cube->ray->vwall.y = inter.y;
			break;
		}
		else
		{
			inter.x += delta.x;
			inter.y += delta.y;
		}
	}
	return (calcul_distance(inter.x, inter.y, cube->plyer->s.x, cube->plyer->s.y));
}

static double	horizontal_intersect(t_cube *cube)
{
	t_dpoint	inter;
	t_dpoint	delta;

	cube->ray->angl = normalize_angle(cube->ray->angl);
	inter.y = floor(cube->plyer->s.y / TILE_SIZE) * TILE_SIZE;
	inter.y += TILE_SIZE * cube->ray->down;
	inter.x = cube->plyer->s.x + (inter.y - cube->plyer->s.y) / tan(cube->ray->angl);
	delta.y = TILE_SIZE;
	delta.x = delta.y / tan(cube->ray->angl);
	adjust_step(cube, &delta.x, &delta.y, 0);
	while(inter.x >= 0 && inter.x <= cube->window->width && inter.y >= 0 && inter.y <= cube->window->height)
	{
		if (hit_wall(inter.x, inter.y - cube->ray->up, cube))
		{
			cube->ray->hwall.x = inter.x;
			cube->ray->hwall.y = inter.y;
			break;
		}
		else
		{
			inter.x += delta.x;
			inter.y += delta.y;
		}
	}
	return (calcul_distance(inter.x, inter.y, cube->plyer->s.x, cube->plyer->s.y));
}

void	raycasting(t_cube *cube)
{
	t_dpoint	distance;
	double		ray_angle;
	t_ray		*ray;
	int			column;

	ray = NULL;
	column = 0;
	ray_angle = cube->plyer->derection - (cube->plyer->fov / 2);
	while (column < cube->window->width)
	{
		ray = &cube->ray[column];
		check_rayfacing(cube, normalize_angle(ray_angle));
		distance.x = horizontal_intersect(cube);
		distance.y = vertical_intersect(cube);
		if (distance.y <= distance.x)
		{
			cube->ray->distance = distance.y;
			ray->hit.x = cube->ray->vwall.x;
			ray->hit.y = cube->ray->vwall.y;
			cube->ray->flag = 1;
		}
		else
		{
			cube->ray->distance = distance.x;
			ray->hit.x = cube->ray->hwall.x;
			ray->hit.y = cube->ray-> hwall.y;
			cube->ray->flag = 0;
		}
		projected_wall(cube, cube->ray, column++);
		ray_angle += (cube->plyer->fov / cube->window->width);
	}
}
