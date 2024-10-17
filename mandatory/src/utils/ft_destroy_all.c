/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:32:36 by aait-bab          #+#    #+#             */
/*   Updated: 2024/10/04 15:30:35 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_destroy_all(t_cube *cube)
{
	mlx_close_window(cube->window);
	mlx_delete_image(cube->window, cube->img);
	mlx_delete_texture(cube->textur->no);
	mlx_delete_texture(cube->textur->so);
	mlx_delete_texture(cube->textur->we);
	mlx_delete_texture(cube->textur->ea);
	ft_malloc(0, 0);
}
