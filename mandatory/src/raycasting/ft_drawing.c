/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:56:54 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/01 23:54:35 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_ceiling(t_cube *cube, int wall_t)
{
	int		i;
	int		color;

	i = 0;
	while (cube->colors[i] != NULL)
	{
		if (!ft_strncmp(cube->colors[i]->key, "C", 1))
			color = ft_get_color(cube->colors[i]->r, \
				cube->colors[i]->g, \
				cube->colors[i]->b, 255);
		else if (!ft_strncmp(cube->colors[i]->key, "C", 1))
			color = ft_get_color(cube->colors[i]->r, \
				cube->colors[i]->g, \
				cube->colors[i]->b, 255);
		i++;
	}
	i = 0;
	while (i < wall_t)
		my_pixel_put(cube->img, cube->ray->index, i++, color);
}

static void	draw_floor(t_cube *cube, int wall_b)
{
	int		color;
	int		i;

	i = 0;
	while (cube->colors[i] != NULL)
	{
		if (!ft_strncmp(cube->colors[i]->key, "F", 1))
			color = ft_get_color(cube->colors[i]->r, \
				cube->colors[i]->g, \
				cube->colors[i]->b, 255);
		else if (!ft_strncmp(cube->colors[i]->key, "F", 1))
			color = ft_get_color(cube->colors[i]->r, \
				cube->colors[i]->g, \
				cube->colors[i]->b, 255);
		i++;
	}
	while (wall_b < cube->window->height)
		my_pixel_put(cube->img, cube->ray->index, wall_b++, color);
}

static void	draw_wall(t_cube *cube, int wall_t, int wall_b, double wall_h)
{
	t_ipoint		offset;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	uint32_t		color;
	int				y;

	texture = get_texture(cube);
	arr = (uint32_t *)texture->pixels;
	offset.x = get_texture_x(texture, cube);
	if (cube->textur->we == texture || cube->textur->so == texture)
		offset.x = texture->width - offset.x - 1;
	y = wall_t;
	while (y < wall_b)
	{
		offset.y = get_texture_y(texture, cube, y, wall_h);
		color = reverse_bytes(arr[offset.y * texture->width + offset.x]);
		my_pixel_put(cube->img, cube->ray->index, y, color);
		y++;
	}
}

void	projected_wall(t_cube *cube)
{
	double	wall_h;
	double	disproplan;
	int		wall_t;
	int		wall_b;

	cube->ray->distance *= cos(cube->ray->angl - cube->plyer->derection);
	disproplan = (cube->window->width / 2) / tan(cube->plyer->fov / 2);
	wall_h = (TILE_SIZE / cube->ray->distance) * disproplan;
	wall_b = (cube->window->height / 2) + (wall_h / 2);
	wall_t = (cube->window->height / 2) - (wall_h / 2);
	if (wall_b > cube->window->height)
		wall_b = cube->window->height;
	if (wall_t < 0)
		wall_t = 0;
	draw_ceiling(cube, wall_t);
	draw_wall(cube, wall_t, wall_b, wall_h);
	draw_floor(cube, wall_b);
}
