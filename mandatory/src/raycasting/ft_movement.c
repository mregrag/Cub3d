/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 06:30:06 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/20 21:07:26 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	turnright(t_cube *cube)
{
	cube->plyer->derection += ROTATION_SPEED;
	cube->plyer->derection = normalize_angle(cube->plyer->derection);
}

static void	turnleft(t_cube *cube)
{
	cube->plyer->derection -= ROTATION_SPEED;
	cube->plyer->derection = normalize_angle(cube->plyer->derection);
}

void	movement(t_cube *cube, double move_x, double move_y)
{
	if (cube->plyer->turn == TURN_RIGHT)
		turnright(cube);
	else if (cube->plyer->turn == TURN_LEFT)
		turnleft(cube);
	if (cube->plyer->walk == RIGHT)
	{
		move_x = -sin(cube->plyer->derection) * MOVE_SPEED;
		move_y = cos(cube->plyer->derection) * MOVE_SPEED;
	}
	else if (cube->plyer->walk == LEFT)
	{
		move_x = sin(cube->plyer->derection) * MOVE_SPEED;
		move_y = -cos(cube->plyer->derection) * MOVE_SPEED;
	}
	else if (cube->plyer->walk == DOWN)
	{
		move_x = -cos(cube->plyer->derection) * MOVE_SPEED;
		move_y = -sin(cube->plyer->derection) * MOVE_SPEED;
	}
	else if (cube->plyer->walk == UP)
	{
		move_x = cos(cube->plyer->derection) * MOVE_SPEED;
		move_y = sin(cube->plyer->derection) * MOVE_SPEED;
	}
	walk_player(cube, move_x, move_y);
}
