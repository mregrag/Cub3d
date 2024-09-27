/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:57:46 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/27 22:44:52 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_texture_t	*get_texture(t_cube *cube)
{
	if (cube->ray->was_hit_vertical)
	{
		if (cube->ray->angl > M_PI / 2 && cube->ray->angl < 3 * (M_PI / 2))
			return (cube->textur->ea);
		else
			return (cube->textur->we);
	}
	else
	{
		if (cube->ray->angl > 0 && cube->ray->angl < M_PI)
			return (cube->textur->no);
		else
			return (cube->textur->so);
	}
}

int	get_texture_x(mlx_texture_t *texture, t_cube *cube)
{
	double	offset_x;

	if (cube->ray->was_hit_vertical)
		offset_x = fmod(cube->ray->vwall.y, TILE_SIZE);
	else
		offset_x = fmod(cube->ray->hwall.x, TILE_SIZE);
	offset_x = (offset_x * texture->width) / TILE_SIZE;
	return (offset_x);
}

int	get_texture_y(mlx_texture_t *texture, t_cube *cube, int y, int wall_h)
{
	double	step;
	double	offset_y;
	int		wall_t;

	wall_t = (cube->window->height / 2) - (wall_h / 2);
	step = (double)texture->height / wall_h;
	offset_y = ((y - wall_t) * step);
	if (offset_y >= texture->height)
		offset_y = texture->height - 1;
	if (offset_y < 0)
		offset_y = 0;
	return (offset_y);
}
