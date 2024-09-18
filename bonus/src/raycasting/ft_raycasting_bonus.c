/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 07:08:14 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/18 11:36:00 by mregrag          ###   ########.fr       */
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
	inter.y = cube->plyer->s.y + (inter.x - cube->plyer->s.x) * tan(cube->ray->angl);
	delta.x = TILE_SIZE;
	delta.y = TILE_SIZE * tan(cube->ray->angl);
	adjust_step(cube, &delta, 1);
	while(!hit_wall(inter.x - cube->ray->left, inter.y, cube))
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
	if(cube->ray->down)
		inter.y += TILE_SIZE;
	inter.x = cube->plyer->s.x + (inter.y - cube->plyer->s.y) / tan(cube->ray->angl);
	delta.y = TILE_SIZE;
	delta.x = TILE_SIZE / tan(cube->ray->angl);
	adjust_step(cube, &delta, 0);
	while(!hit_wall(inter.x, inter.y - cube->ray->up, cube))
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
	t_ray		*ray;

	ray = NULL;
	cube->ray->index = 0;
	cube->ray->angl = cube->plyer->derection - (cube->plyer->fov / 2);
	while (cube->ray->index < cube->window->width)
	{
		ray = &cube->ray[cube->ray->index];
		cube->ray->angl = normalize_angle(cube->ray->angl);
		check_rayfacing(cube, cube->ray->angl);
		distance.y = vertical_intersect(cube);
		distance.x = horizontal_intersect(cube);
		if (distance.y < distance.x)
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
		projected_wall(cube);
		cube->ray->index++;
		cube->ray->angl += (cube->plyer->fov / cube->window->width);
	}
}


