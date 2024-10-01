/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_all_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:32:36 by aait-bab          #+#    #+#             */
/*   Updated: 2024/10/01 16:54:51 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_destroy_all(t_cube *cube)
{
	int	i;

	i = 0;
	mlx_close_window(cube->window);
	mlx_delete_image(cube->window, cube->img);
	mlx_delete_image(cube->window, cube->img3);
	mlx_delete_texture(cube->textur->no);
	mlx_delete_texture(cube->textur->so);
	mlx_delete_texture(cube->textur->we);
	mlx_delete_texture(cube->textur->ea);
	mlx_delete_texture(cube->textur->door);
	while (cube->sprites[i])
	{
		mlx_delete_image(cube->window, cube->sprites[i]->img);
		i++;
	}
	ft_malloc(0, 0);
}
