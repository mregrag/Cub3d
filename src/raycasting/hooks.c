/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 03:43:59 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/25 23:41:52 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	key_reles(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		mlx->plyer->walk = STOP;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		mlx->plyer->walk = STOP;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		mlx->plyer->walk = STOP;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		mlx->plyer->walk = STOP;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		mlx->plyer->turn = STOP;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		mlx->plyer->turn = STOP;
}

void	key_press(mlx_key_data_t keydata, void *ml)
{
	t_mlx	*mlx;

	mlx = ml;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS))
		exit(EXIT_SUCCESS);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		mlx->plyer->walk = LEFT;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		mlx->plyer->walk = RIGHT;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		mlx->plyer->walk = DOWN;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		mlx->plyer->walk = UP;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		mlx->plyer->turn = LEFT;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		mlx->plyer->turn = RIGHT;
	key_reles(keydata, mlx);
}
