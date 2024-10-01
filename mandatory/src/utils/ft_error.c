/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:57:20 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/29 21:01:03 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	destroy_textrs(t_cube *cube)
{
	if (cube->textur)
	{
		if (cube->textur->no)
			mlx_delete_texture(cube->textur->no);
		if (cube->textur->so)
			mlx_delete_texture(cube->textur->so);
		if (cube->textur->we)
			mlx_delete_texture(cube->textur->we);
		if (cube->textur->ea)
			mlx_delete_texture(cube->textur->ea);
	}
}

void	ft_error(char *msg)
{
	t_cube	*cube;

	ft_putendl_fd(msg, 2);
	cube = ft_get_cube(NULL);
	if (cube->window)
		mlx_close_window(cube->window);
	if (cube->img)
		mlx_delete_image(cube->window, cube->img);
	if (cube->map->fd > -1)
		close(cube->map->fd);
	destroy_textrs(cube);
	ft_malloc(0, 0);
	exit(1);
}
