/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:57:20 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/20 10:19:51 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	destroy_textrs(t_cube *cube)
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

void	destory_sprites(t_cube *cube)
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
	print_fd(msg, 2);
	cube = ft_get_cube(NULL);
	if (cube->window)
		mlx_close_window(cube->window);
	if (cube->img)
		mlx_delete_image(cube->window, cube->img);
	if (cube->img2)
		mlx_delete_image(cube->window, cube->img2);
	if (cube->img3)
		mlx_delete_image(cube->window, cube->img3);
	destroy_textrs(cube);
	destory_sprites(cube);
	ft_malloc(0, 0);
	exit(1);
}
