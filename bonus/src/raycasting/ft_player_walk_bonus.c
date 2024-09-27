/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_walk_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:15:24 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/22 20:57:00 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static int	check_collision(t_cube *cube, int x, int y)
{
	return (is_wall(x - COLLISION, y - COLLISION, cube)
		|| is_wall(x + COLLISION, y - COLLISION, cube)
		|| is_wall(x - COLLISION, y + COLLISION, cube)
		|| is_wall(x + COLLISION, y + COLLISION, cube));
}

void	walk_player(t_cube *cube, double move_x, double move_y)
{
	int	new_x;
	int	new_y;

	new_x = round(cube->plyer->s.x + move_x);
	new_y = round(cube->plyer->s.y + move_y);
	if (!check_collision(cube, new_x, cube->plyer->s.y))
		cube->plyer->s.x = new_x;
	if (!check_collision(cube, cube->plyer->s.x, new_y))
		cube->plyer->s.y = new_y;
}
