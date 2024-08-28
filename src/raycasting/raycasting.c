/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 07:08:14 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/28 07:37:46 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	hit_wall(double x, double y, t_cube *cube)
{
	int		m_x;
	int		m_y;

	if (x < 0 || y < 0)
		return (0);
	m_x = floor (x / TILE_SIZE);
	m_y = floor (y / TILE_SIZE);
	if ((m_y >= cube->map->h_map || m_x >= cube->map->w_map))
		return (0);
	if (cube->map->map2d[m_y][m_x] == '1')
			return (0);
	return (1);
}

void	draw_floor_ceiling(t_cube *cube, int ray, int t, int b)
{
	int		i;
	int		c;

	i = b;
	c = ft_get_color(0, 204, 204, 255);
	while (i < HEIGHT)
		my_mlx_pixel_put(cube, ray, i++, c);
	c = ft_get_color(192, 192, 192, 255);
	i = 0;
	while (i < t)
		my_mlx_pixel_put(cube, ray, i++, c);
}

void	draw_wall(t_cube *cube, int ray, int t, int b)
{
	int color;

	color = ft_get_color(0, 0, 0, 255);
	while (t < b)
		my_mlx_pixel_put(cube, ray, t++, color);
}

void	rendering(t_cube *cube, int ray)
{
	double wall_height;
	double b;
	double t;

	cube->ray->distance *= cos(normalize_angle(cube->ray->angl - cube->plyer->derection));
	wall_height = (TILE_SIZE / cube->ray->distance) * ((WIDTH / 2) / tan(cube->plyer->fov / 2));
	b = (HEIGHT / 2) + (wall_height / 2);
	t = (HEIGHT / 2) - (wall_height / 2);
	if (b > HEIGHT)
		b = HEIGHT;
	if (t < 0)
		t = 0;
	cube->ray->index = ray;
	draw_wall(cube, ray, t, b);
	draw_floor_ceiling(cube, ray, t, b);
}

double	vertical_intersect(t_cube *cube, double angl)
{
	double	xinter;
	double	yinter;
	double	deltax;
	double	deltay;

	cube->ray->facingdown = angl > 0 && angl < M_PI;
	cube->ray->facingup = !cube->ray->facingdown;
	cube->ray->facingright = angl < (M_PI / 2) || angl > (3 * M_PI / 2);
	cube->ray->facingleft = !cube->ray->facingright;
	xinter = floor(cube->plyer->x / TILE_SIZE) * TILE_SIZE;
	if (cube->ray->facingright)
		xinter += TILE_SIZE;
	yinter = cube->plyer->y + (xinter - cube->plyer->x) * tan(angl);
	deltax = TILE_SIZE;
	if (cube->ray->facingleft)
		deltax *= -1;
	deltay = TILE_SIZE * tan(angl);
	if (cube->ray->facingup && deltay > 0)
		deltay *= -1;
	if (cube->ray->facingdown && deltay < 0)
		deltay *= -1;
	if (cube->ray->facingleft)
		xinter--;
	while (hit_wall(xinter, yinter, cube))
	{
		xinter += deltax;
		yinter += deltay;
	}
	return (calcul_distance(xinter, yinter, cube->plyer->x, cube->plyer->y));
}
double	herizontal_intersect(t_cube *cube, double angl)
{
	double	xinter;
	double	yinter;
	double	deltax;
	double	deltay;

	cube->ray->facingdown = angl > 0 && angl < M_PI;
	cube->ray->facingup = !cube->ray->facingdown;
	cube->ray->facingright = angl < (M_PI / 2) || angl > (3 * M_PI / 2);
	cube->ray->facingleft = !cube->ray->facingright;
	yinter = floor(cube->plyer->y / TILE_SIZE) * TILE_SIZE;
	if (cube->ray->facingdown)
		yinter += TILE_SIZE;
	xinter = cube->plyer->x + (yinter - cube->plyer->y) / tan(angl);
	deltay = TILE_SIZE;
	if (cube->ray->facingup)
		deltay *= -1;
	deltax = TILE_SIZE / tan(angl);
	if (cube->ray->facingleft && deltax > 0)
		deltax *= -1;
	if (cube->ray->facingright && deltax < 0)
		deltax *= -1;
	if (cube->ray->facingup)
		yinter--;
	while (hit_wall(xinter, yinter, cube))
	{
		xinter += deltax;
		yinter += deltay;
	}
	return (calcul_distance(xinter, yinter, cube->plyer->x, cube->plyer->y));
}

void	raycasting(t_cube *cube)
{
	double	h_distance;
	double	v_distance;
	int		ray;

	ray = 0;
	cube->ray->angl = cube->plyer->derection - (cube->plyer->fov / 2);
	while (ray < WIDTH)
	{
		h_distance = herizontal_intersect(cube, normalize_angle(cube->ray->angl));
		v_distance = vertical_intersect(cube, normalize_angle(cube->ray->angl));
		if (v_distance <= h_distance)
			cube->ray->distance = v_distance;
		else
			cube->ray->distance = h_distance;
		rendering(cube, ray);
		cube->ray->angl += (cube->plyer->fov / WIDTH);
		ray++;
	}
}

