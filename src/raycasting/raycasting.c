/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 07:08:14 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/26 23:34:40 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_direction(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

int	is_hit_wall(double x, double y, t_cube *cube)
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / TILE_SIZE);
	y_m = floor (y / TILE_SIZE);
	if ((y_m >= cube->map->h_map || x_m >= cube->map->w_map))
		return (0);
	if (cube->map->map2d[y_m][x_m] == '1')
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

	wall_height = (TILE_SIZE / cube->rays->distance) * ((WIDTH / 2) / tan(cube->plyer->fov / 2));
	b = (HEIGHT / 2) + (wall_height / 2);
	t = (HEIGHT / 2) - (wall_height / 2);
	if (b > HEIGHT)
		b = HEIGHT;
	if (t < 0)
		t = 0;
	cube->rays->index = ray;
	draw_wall(cube, ray, t, b);
	draw_floor_ceiling(cube, ray, t, b);
}


float	calcul_vertical_inter(t_cube *cube, float angl)
{
	float	x;
	float	y;
	float	deltax;
	float	deltay;

	deltax = TILE_SIZE;
	deltay = TILE_SIZE * tan(angl);
	x = floor(cube->plyer->plyr_x / TILE_SIZE) * TILE_SIZE;
	if (!(angl > M_PI / 2 && angl < 3 * M_PI / 2))
	{
		x += TILE_SIZE;
		x += 1;
	}
	else
	{
		deltax *= -1;
		x -= 1;
	}
	y = cube->plyer->plyr_y + (x - cube->plyer->plyr_x) * tan(angl);
	if ((check_direction(angl, 'x') && deltay < 0) || (!check_direction(angl, 'x') && deltay > 0))
		deltay *= -1;
	while (is_hit_wall(x , y, cube))
	{
		x += deltax;
		y += deltay;
	}
	return (sqrt(pow(x - cube->plyer->plyr_x, 2) + pow(y - cube->plyer->plyr_y, 2)));
}

float	calcul_herizontal_inter(t_cube *cube, float angl)
{
	float	x;
	float	y;
	float	deltax;
	float	deltay;

	deltay = TILE_SIZE;
	deltax = TILE_SIZE / tan(angl);
	y = floor(cube->plyer->plyr_y / TILE_SIZE) * TILE_SIZE;
	if (angl > 0 && angl < M_PI)
	{
		y += TILE_SIZE;
		y += 1;
	}
	else
	{
		deltay *= -1;
		y -= 1;
	}
	x = cube->plyer->plyr_x + (y - cube->plyer->plyr_y) / tan(angl);
	if ((check_direction(angl, 'y') && deltax > 0) || (!check_direction(angl, 'y') && deltax < 0))
		deltax *= -1;
	while (is_hit_wall(x, y, cube))
	{
		x += deltax;
		y += deltay;
	}
	return (sqrt(pow(x - cube->plyer->plyr_x, 2) + pow(y - cube->plyer->plyr_y, 2)));
}

void	raycasting(t_cube *cube)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	cube->rays->ray_angl = cube->plyer->derection - (cube->plyer->fov / 2);
	while (ray < WIDTH)
	{
		h_inter = calcul_herizontal_inter(cube, reset_angle(cube->rays->ray_angl));
		v_inter = calcul_vertical_inter(cube, reset_angle(cube->rays->ray_angl));
		if (v_inter <= h_inter)
			cube->rays->distance = v_inter;
		else
			cube->rays->distance = h_inter;
		rendering(cube, ray);
		ray++;
		cube->rays->ray_angl += (cube->plyer->fov / WIDTH);
	}
}

