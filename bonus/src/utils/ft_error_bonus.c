/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:57:20 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/30 22:53:51 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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
		if (cube->textur->door)
			mlx_delete_texture(cube->textur->door);
	}
}

static void	destory_sprites(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->sprites[i])
	{
		if (cube->sprites[i]->img)
			mlx_delete_image(cube->window, cube->sprites[i]->img);
		i++;
	}
}

void	ft_error(char *msg)
{
	t_cube	*cube;
	int		i;

	i = 0;
	ft_putendl_fd(msg, 2);
	cube = ft_get_cube(NULL);
	if (cube->window)
		mlx_close_window(cube->window);
	if (cube->img)
		mlx_delete_image(cube->window, cube->img);
	if (cube->img3)
		mlx_delete_image(cube->window, cube->img3);
	if (cube->map->fd > -1)
		close(cube->map->fd);
	destroy_textrs(cube);
	destory_sprites(cube);
	ft_malloc(0, 0);
	exit(1);
}
