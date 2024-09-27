/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:42:24 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/27 19:33:41 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_sprites(t_cube *cube)
{
	static int	i = 0;
	static int	j = 0;

	if (mlx_is_mouse_down(cube->window, MLX_MOUSE_BUTTON_LEFT))
		cube->shoot = 1;
	if (cube->shoot)
	{
		if (++(j) > 3)
		{
			cube->sprites[i]->img->enabled = false;
			(i)++;
			((i % 5 == 0) && (i = 0, cube->shoot = 0));
			cube->sprites[i]->img->enabled = true;
		}
		j = (j % 4);
	}
}
