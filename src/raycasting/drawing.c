/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:56:54 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/14 11:54:01 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_ceiling(t_cube *cube, int ray, int ceiling_end)
{
	int		i;
	int		color;

	i = 0;
	while (i < 2 && cube->colors[i])
	{
		if (!ft_strncmp(cube->colors[i]->key, "C", 1))
			color = ft_get_color(cube->colors[i]->r, cube->colors[i]->g, cube->colors[i]->b, 255);
		else if (!ft_strncmp(cube->colors[i]->key, "C", 1))
			color = ft_get_color(cube->colors[i]->r, cube->colors[i]->g, cube->colors[i]->b, 255);
		i++;
	}
	i = 0;
	while (i < ceiling_end)
		my_mlx_pixel_put(cube, ray, i++, color);
}


void	draw_wall(t_cube *cube, int wall_t, int wall_b, double wall_h)
{
	t_dpoint	textoffset;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

	texture = get_texture(cube, cube->ray->flag);
	arr = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	textoffset.x = calculate_texture_x(texture, cube);
	textoffset.y = (wall_t - (cube->window->height / 2) + (wall_h / 2)) * factor;
	if (textoffset.y < 0)
		textoffset.y = 0;
	while (wall_t < wall_b)
	{
		my_mlx_pixel_put(cube, cube->ray->index, wall_t, reverse_bytes \
		(arr[(int)textoffset.y * texture->width + (int)textoffset.x]));
		textoffset.y += factor;
		wall_t++;
	}
}

void	draw_floor(t_cube *cube, int ray, int floor_start)
{
	int		color;
	int		i;

	i = 0;
	while (i < 2 && cube->colors[i])
	{
		if (!ft_strncmp(cube->colors[i]->key, "F", 1))
			color = ft_get_color(cube->colors[i]->r, cube->colors[i]->g, cube->colors[i]->b, 255);
		else if (!ft_strncmp(cube->colors[i]->key, "F", 1))
			color = ft_get_color(cube->colors[i]->r, cube->colors[i]->g, cube->colors[i]->b, 255);
		i++;
	}
	while (floor_start < cube->window->height)
		my_mlx_pixel_put(cube, ray, floor_start++, color);
}

void	projected_wall(t_cube *cube, t_ray *ray)
{
	double	wall_h;
	double	disproplan;
	int		wall_t;
	int		wall_b;

	ray->distance *= cos(normalize_angle(ray->angl - cube->plyer->derection));

	disproplan = (cube->window->width / 2) / tan(cube->plyer->fov / 2);
	wall_h = (TILE_SIZE / ray->distance) * disproplan;
	wall_b = (cube->window->height / 2) + (wall_h / 2);
	wall_t = (cube->window->height / 2) - (wall_h / 2);
	if (wall_b > cube->window->height)
		wall_b = cube->window->height;
	if (wall_t < 0)
		wall_t = 0;
	draw_ceiling(cube, cube->ray->index, wall_t);
	draw_wall(cube, wall_t, wall_b, wall_h);
	draw_floor(cube, cube->ray->index, wall_b);
}

