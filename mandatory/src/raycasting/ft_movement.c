/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 06:30:06 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/16 13:38:36 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	turnright(t_cube *cube)
{
	cube->plyer->derection += ROTATION_SPEED;
	if (cube->plyer->derection > 2 * M_PI)
		cube->plyer->derection -= 2 * M_PI;
}

static void	turnleft(t_cube *cube)
{
	cube->plyer->derection -= ROTATION_SPEED;
	if (cube->plyer->derection < 0)
		cube->plyer->derection += 2 * M_PI;
}

void	movement(t_cube *cube, double move_x, double move_y)
{
	if (cube->plyer->turn == TURN_RIGHT)
		turnright(cube);
	if (cube->plyer->turn == TURN_LEFT)
		turnleft(cube);
	if (cube->plyer->walk == RIGHT)
	{
		move_x = -sin(cube->plyer->derection) * MOVE_SPEED;
		move_y = cos(cube->plyer->derection) * MOVE_SPEED;
	}
	if (cube->plyer->walk == LEFT)
	{
		move_x = sin(cube->plyer->derection) * MOVE_SPEED;
		move_y = -cos(cube->plyer->derection) * MOVE_SPEED;
	}
	if (cube->plyer->walk == UP)
	{
		move_x = cos(cube->plyer->derection) * MOVE_SPEED;
		move_y = sin(cube->plyer->derection) * MOVE_SPEED;
	}
	if (cube->plyer->walk == DOWN)
	{
		move_x = -cos(cube->plyer->derection) * MOVE_SPEED;
		move_y = -sin(cube->plyer->derection) * MOVE_SPEED;
	}
	walk_player(cube, move_x, move_y);
}
