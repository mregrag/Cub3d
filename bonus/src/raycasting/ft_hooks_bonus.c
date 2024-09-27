/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 03:43:59 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/27 19:25:56 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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
	key_reles(keydata, cube);
}

void	mouse_event(void *param)
{
	t_cube	*cube;
	int		mouse_x;
	int		mouse_y;
	int		dx;

	cube = (t_cube *)param;
	mlx_get_mouse_pos(cube->window, &mouse_x, &mouse_y);
	dx = mouse_x - cube->window->width / 2;
	cube->plyer->derection += dx * 0.002;
	cube->plyer->derection = normalize_angle(cube->plyer->derection);
	mlx_set_mouse_pos(cube->window, cube->window->width / 2, \
			cube->window->height / 2);
}
