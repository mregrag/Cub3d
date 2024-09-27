/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:18:06 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/22 21:28:25 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	adjust_step(t_cube *cube, t_dpoint *delta, int is_vertical)
{
	if (is_vertical)
	{
		if (cube->ray->left)
			delta->x *= -1;
		if (cube->ray->up && delta->y > 0)
			delta->y *= -1;
		if (cube->ray->down && delta->y < 0)
			delta->y *= -1;
	}
	else
	{
		if (cube->ray->up)
			delta->y *= -1;
		if (cube->ray->left && delta->x > 0)
			delta->x *= -1;
		if (cube->ray->right && delta->x < 0)
			delta->x *= -1;
	}
}

void	check_rayfacing(t_cube *cube, double angle)
{
	cube->ray->down = angle > 0 && angle < M_PI;
	cube->ray->up = !cube->ray->down;
	cube->ray->right = angle < (M_PI / 2) || angle > (3 * M_PI / 2);
	cube->ray->left = !cube->ray->right;
}

int	is_wall(double x, double y, t_cube *cube)
{
	t_ipoint	m;

	if (x < 0 || y < 0)
		return (1);
	m.x = floor(x / TILE_SIZE);
	m.y = floor(y / TILE_SIZE);
	if (m.y < 0 || m.y >= cube->map->width
		|| m.x < 0 || m.x >= cube->map->height)
		return (1);
	if (cube->map->map2d[m.y][m.x] == '1')
		return (1);
	return (0);
}
