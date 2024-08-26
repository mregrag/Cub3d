/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 07:08:14 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/26 00:06:02 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	unit_circle(float angle, char c)
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

int	is_hit_wall(double x, double y, t_mlx *mlx)
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / TILE_SIZE);
	y_m = floor (y / TILE_SIZE);
	if ((y_m >= mlx->map->h_map || x_m >= mlx->map->w_map))
		return (0);
	if (mlx->map->map2d[y_m] && x_m <= (int)ft_strlen(mlx->map->map2d[y_m]))
		if (mlx->map->map2d[y_m][x_m] == '1')
			return (0);
	return (1);
}

int	check_intersection(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

void	draw_floor_ceiling(t_mlx *mlx, int ray, int t_pix, int b_pix)
{
	int		i;
	int		c;

	i = b_pix;
	c = ft_get_color(51, 255, 153, 255);
	while (i < HEIGHT)
		my_mlx_pixel_put(mlx, ray, i++, c);
	c = ft_get_color(204, 0, 0, 255);
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(mlx, ray, i++, c);
}

void	draw_wall(t_mlx *mlx, int ray, int t_pix, int b_pix)
{
	int color;

	color = ft_get_color(51, 0, 25, 255);
	while (t_pix < b_pix)
		my_mlx_pixel_put(mlx, ray, t_pix++, color);
}

void	render_wall(t_mlx *mlx, int ray)
{
	double wall_h;
	double b_pix;
	double t_pix;

	// mlx->rays->distance *= cos(reset_angle(mlx->rays->ray_angl - mlx->plyer->derection));
	wall_h = (TILE_SIZE / mlx->rays->distance) * ((WIDTH / 2) / tan(mlx->plyer->fov / 2));
	b_pix = (HEIGHT / 2) + (wall_h / 2);
	t_pix = (HEIGHT / 2) - (wall_h / 2);
	if (b_pix > HEIGHT)
		b_pix = HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	mlx->rays->index = ray;
	draw_wall(mlx, ray, t_pix, b_pix);
	draw_floor_ceiling(mlx, ray, t_pix, b_pix);
}

float	calcul_herizontal_inter(t_mlx *mlx, float angl)
{
	float	x;
	float	y;
	float	deltax;
	float	deltay;
	int		inter;

	deltay = TILE_SIZE;
	deltax = TILE_SIZE / tan(angl);
	y = floor(mlx->plyer->plyr_y / TILE_SIZE) * TILE_SIZE;
	inter = check_intersection(angl, &y, &deltay, 1);
	x = mlx->plyer->plyr_x + (y - mlx->plyer->plyr_y) / tan(angl);
	if ((unit_circle(angl, 'y') && deltax > 0) || (!unit_circle(angl, 'y') && deltax < 0))
		deltax *= -1;
	while (is_hit_wall(x, y - inter, mlx))
	{
		x += deltax;
		y += deltay;
	}
	return (sqrt(pow(x - mlx->plyer->plyr_x, 2) + pow(y - mlx->plyer->plyr_y, 2)));
}

float	calcul_vertical_inter(t_mlx *mlx, float angl)
{
	float	x;
	float	y;
	float	deltax;
	float	deltay;
	int		inter;

	deltax = TILE_SIZE;
	deltay = TILE_SIZE * tan(angl);
	x = floor(mlx->plyer->plyr_x / TILE_SIZE) * TILE_SIZE;
	inter = check_intersection(angl, &x, &deltax, 0);
	y = mlx->plyer->plyr_y + (x - mlx->plyer->plyr_x) * tan(angl);
	if ((unit_circle(angl, 'x') && deltay < 0) || (!unit_circle(angl, 'x') && deltay > 0))
		deltay *= -1;
	while (is_hit_wall(x - inter, y, mlx))
	{
		x += deltax;
		y += deltay;
	}
	return (sqrt(pow(x - mlx->plyer->plyr_x, 2) + pow(y - mlx->plyer->plyr_y, 2)));
}

void	raycasting(t_mlx *mlx)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	mlx->rays->ray_angl = mlx->plyer->derection - (mlx->plyer->fov / 2);
	while (ray < WIDTH)
	{
		mlx->rays->flag = 0;
		h_inter = calcul_herizontal_inter(mlx, reset_angle(mlx->rays->ray_angl));
		v_inter = calcul_vertical_inter(mlx, reset_angle(mlx->rays->ray_angl));
		if (v_inter <= h_inter)
			mlx->rays->distance = v_inter;
		else
			mlx->rays->distance = h_inter;
		render_wall(mlx, ray);
		ray++;
		mlx->rays->ray_angl += (mlx->plyer->fov / WIDTH);
	}
}

