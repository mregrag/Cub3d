/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:17:36 by aait-bab          #+#    #+#             */
/*   Updated: 2024/09/27 00:31:36 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_cube	*ft_get_cube(t_cube *cube)
{
	static t_cube	*s_cube;

	if (cube)
		s_cube = cube;
	return (s_cube);
}
