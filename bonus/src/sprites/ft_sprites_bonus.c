/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:42:24 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/17 22:23:50 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_sprites(t_cube *cube, int *i, int *j)
{
	if (cube->shoot)
	{
		if (++(*j) > 4)
		{
			cube->sprites[*i]->img->enabled = false;
			(*i)++;
			((*i % 5 == 0) && (*i = 0, cube->shoot = 0));
			cube->sprites[*i]->img->enabled = true;
		}
		*j = (*j % 5);
	}
}
