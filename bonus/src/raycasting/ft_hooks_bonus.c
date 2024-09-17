/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 03:43:59 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/17 12:02:15 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	key_reles(mlx_key_data_t keydata, t_cube *cube)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		cube->plyer->walk = STOP;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		cube->plyer->walk = STOP;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		cube->plyer->walk = STOP;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		cube->plyer->walk = STOP;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		cube->plyer->turn = STOP;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		cube->plyer->turn = STOP;
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_cube	*cube;

	cube = param;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS))
		ft_error("CLOSED");
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		cube->plyer->walk = LEFT;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		cube->plyer->walk = RIGHT;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		cube->plyer->walk = DOWN;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		cube->plyer->walk = UP;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		cube->plyer->turn = TURN_LEFT;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		cube->plyer->turn = TURN_RIGHT;
	else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		cube->shoot = 1;
	key_reles(keydata, cube);
}
