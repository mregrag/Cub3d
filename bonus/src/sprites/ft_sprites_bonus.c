/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:42:24 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/19 19:33:22 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_sprites(t_cube *cube, int *i, int *j)
{
	if (cube->shoot)
	{
		if (++(*j) > 3)
		{
			cube->sprites[*i]->img->enabled = false;
			(*i)++;
			((*i % 5 == 0) && (*i = 0, cube->shoot = 0));
			cube->sprites[*i]->img->enabled = true;
		}
		*j = (*j % 4);
	}
}
