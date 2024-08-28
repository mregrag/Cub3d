/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:20:49 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/28 06:00:20 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "objects.h"

void	ft_reles(mlx_key_data_t keydata, t_cube *cube);
void	key_press(mlx_key_data_t keydata, void *ml);

void	turn_player(t_cube *cube, int turn);
void	walk_player(t_cube *cube, double move_x, double move_y);
void	movement(t_cube *cube, double move_x, double move_y);


//-------------------------------------ustils----------------------
double	deg2rad(double degrees);
int	ft_get_color(int r, int g, int b, int a);
void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color);

int	parsing_map(char *path, t_map *map);
double	normalize_angle(float angle);
void	raycasting(t_cube *cube);
void	render_wall(t_cube *cube, int ray);
double	calcul_distance(double x_inter, double y_inter, double p_x, double p_y);

//-----------------------debug-------------------------

void	draw_grid(mlx_image_t *img, uint32_t color, int tile_size);
void	draw_player(t_cube *cube);
void	draw_ray(t_cube *cube, double ray_angle);
void	draw_rays(t_cube *cube);

void	turnright(double *dererction);
void	turnleft(double *dererction);
#endif
