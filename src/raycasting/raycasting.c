/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 07:08:14 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/31 23:25:11 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static double	vertical_intersect(t_cube *cube, t_ray *ray)
{
	double	x;
	double	y;
	double	dx;
	double	dy;

	x = floor(cube->plyer->x / TILE_SIZE) * TILE_SIZE;
	if (ray->right)
		x += TILE_SIZE;
	y = cube->plyer->y + (x - cube->plyer->x) * tan(ray->angl);
	dx = TILE_SIZE;
	dy = TILE_SIZE * tan(ray->angl);
	adjust_step(ray, &dx, &dy, 1);
	if (ray->left)
		x--;
	while (!hit_wall(x, y, cube))
	{
		x += dx;
		y += dy;
	}
	ray->vwallhit_x = x;
	ray->vwallhit_y = y;
	return (calcul_distance(x, y, cube->plyer->x, cube->plyer->y));
}

static double	horizontal_intersect(t_cube *cube, t_ray *ray)
{
	double	x;
	double	y;
	double	dx;
	double	dy;

	y = floor(cube->plyer->y / TILE_SIZE) * TILE_SIZE;
	if (ray->down)
		y += TILE_SIZE;
	x = cube->plyer->x + (y - cube->plyer->y) / tan(ray->angl);
	dy = TILE_SIZE;
	dx = dy / tan(ray->angl);
	adjust_step(ray, &dx, &dy, 0);
	if (ray->up)
		y--;
	while (!hit_wall(x, y, cube))
	{
		x += dx;
		y += dy;
	}
	ray->hwallhit_x = x;
	ray->hwallhit_y = y;
	return (calcul_distance(x, y, cube->plyer->x, cube->plyer->y));
}

void raycasting(t_cube *cube)
{
    double	h_distance;
    double 	v_distance;
    double	ray_angle;
    t_ray	*ray;
    int		column;

    column = 0;
    ray_angle = cube->plyer->derection - (cube->plyer->fov / 2);
    while (column < cube->window->width)
    {
        ray = &cube->rays[column];
        init_ray(ray, normalize_angle(ray_angle));
        h_distance = horizontal_intersect(cube, ray);
        v_distance = vertical_intersect(cube, ray);
        if (v_distance <= h_distance)
        {
            ray->distance = v_distance;
            ray->flag = 1;  // Flag to indicate vertical hit
        }
        else
        {
            ray->distance = h_distance;
            ray->flag = 0;  // Flag to indicate horizontal hit
        }
	if (h_distance < v_distance)
		ray->hit_x = ray->hwallhit_x;
	else
		ray->hit_x = ray->vwallhit_x;
	if (h_distance < v_distance)
		ray->hit_y = ray-> hwallhit_y;
	else
		ray->hit_y = ray->vwallhit_y;
        ray_angle += (cube->plyer->fov / cube->window->width);
        column++;
    }
}
