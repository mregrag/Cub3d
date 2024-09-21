/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 07:08:14 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/20 13:34:10 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static double	vertical_intersect(t_cube *cube)
{
	t_dpoint	intersect;
	t_dpoint	delta;

	intersect.x = floor(cube->plyer->s.x / TILE_SIZE) * TILE_SIZE;
	if (cube->ray->right)
		intersect.x += TILE_SIZE;
	intersect.y = cube->plyer->s.y
		+ (intersect.x - cube->plyer->s.x) * tan(cube->ray->angl);
	delta.x = TILE_SIZE;
	delta.y = TILE_SIZE * tan(cube->ray->angl);
	adjust_step(cube, &delta, 1);
	while (!is_wall(intersect.x - cube->ray->left, intersect.y, cube))
	{
		intersect.x += delta.x;
		intersect.y += delta.y;
	}
	cube->ray->vwall.x = intersect.x;
	cube->ray->vwall.y = intersect.y;
	return (calcul_distance(intersect, cube->plyer->s));
}

static double	horizontal_intersect(t_cube *cube)
{
	t_dpoint	intersect;
	t_dpoint	delta;

	intersect.y = floor(cube->plyer->s.y / TILE_SIZE) * TILE_SIZE;
	if (cube->ray->down)
		intersect.y += TILE_SIZE;
	intersect.x = cube->plyer->s.x
		+ (intersect.y - cube->plyer->s.y) / tan(cube->ray->angl);
	delta.y = TILE_SIZE;
	delta.x = TILE_SIZE / tan(cube->ray->angl);
	adjust_step(cube, &delta, 0);
	while (!is_wall(intersect.x, intersect.y - cube->ray->up, cube))
	{
		intersect.x += delta.x;
		intersect.y += delta.y;
	}
	cube->ray->hwall.x = intersect.x;
	cube->ray->hwall.y = intersect.y;
	return (calcul_distance(intersect, cube->plyer->s));
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
