/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 03:43:59 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/30 22:48:35 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static void	toggle_mouse(t_cube *cube)
{
	cube->mouse_enabled = !cube->mouse_enabled;
	if (cube->mouse_enabled)
		mlx_set_cursor_mode(cube->window, MLX_MOUSE_DISABLED);
	else
		mlx_set_cursor_mode(cube->window, MLX_MOUSE_NORMAL);
}

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
	else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_RELEASE)
		cube->door->is_door_open = 0;
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
		cube->door->is_door_open = 1;
	else if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		toggle_mouse(cube);
	key_reles(keydata, cube);
}

void	mouse_event(void *param)
{
	t_cube	*cube;
	int		mouse_x;
	int		mouse_y;
	int		dx;

	cube = (t_cube *)param;
	if (!cube->mouse_enabled)
		return ;
	mlx_get_mouse_pos(cube->window, &mouse_x, &mouse_y);
	dx = mouse_x - cube->window->width / 2;
	cube->plyer->derection += dx * 0.002;
	cube->plyer->derection = normalize_angle(cube->plyer->derection);
	mlx_set_mouse_pos(cube->window, cube->window->width / 2, \
			cube->window->height / 2);
}
