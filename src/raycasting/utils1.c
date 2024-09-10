/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:18:06 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/31 22:32:05 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	adjust_step(t_ray *ray, double *dx, double *dy, int is_vertical)
{
	if (is_vertical)
	{
		if (ray->left)
			*dx *= -1;
		if (ray->up && *dy > 0)
			*dy *= -1;
		if (ray->down && *dy < 0)
			*dy *= -1;
	}
	else
	{
		if (ray->up)
			*dy *= -1;
		if (ray->left && *dx > 0)
			*dx *= -1;
		if (ray->right && *dx < 0)
			*dx *= -1;
	}
}

void	init_ray(t_ray *ray, double angle)
{
	ray->angl = angle;
	ray->down = angle > 0 && angle < M_PI;
	ray->up = !ray->down;
	ray->right = angle < (M_PI / 2) || angle > (3 * M_PI / 2);
	ray->left = !ray->right;
}

int	hit_wall(double x, double y, t_cube *cube)
{
	int	m_x;
	int	m_y;

	if (x < 0 || y < 0)
		return (1);
	m_x = floor(x / TILE_SIZE);
	m_y = floor(y / TILE_SIZE);
	if (m_y >= cube->map->rows || m_x >= cube->map->cols)
		return (1);
	if (cube->map->map2d[m_y] && m_x < (int)ft_strlen(cube->map->map2d[m_y]))
		if (cube->map->map2d[m_y][m_x] == '1')
			return (1);
	return (0);
}
