/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:20:49 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/13 08:50:02 by mregrag          ###   ########.fr       */
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
int	reverse_bytes(int c);

int	parsing_map(char *path, t_map *map);
double	normalize_angle(float angle);
void	raycasting(t_cube *cube);
void	render_wall(t_cube *cube, int ray);
double	calcul_distance(double x_inter, double y_inter, double p_x, double p_y);

//-----------------------debug-------------------------

// void	draw_ray(t_cube *cube, double ray_angle);
// void	draw_rays(t_cube *cube);
void	render(t_cube *cube, double ray);
void	draw_rays(t_cube *cube);
// void	render(t_cube *mlx);

void	turnright(double *dererction);
void	turnleft(double *dererction);
//-----------------------drawing-------------------------

void	draw_ceiling(t_cube *cube, int ray, int ceiling_end);
void	draw_wall(t_cube *cube, int wall_t, int wall_b, double wall_h);
void	draw_floor(t_cube *cube, int ray, int floor_start);
void	projected_wall(t_cube *cube, t_ray *ray, int index);

//-----------------------drawing-------------------------
void	adjust_step(t_cube *cube, double *dx, double *dy, int is_vertical);
void	check_rayfacing(t_cube *cube,  double angle);
int	hit_wall(double x, double y, t_cube *cube);

// void	draw_player(t_cube *cube);
// void    draw_player(t_cube *cube, int offset_x, int offset_y);
void    draw_player(t_cube *cube);
void	draw_minimap(t_cube *cube);
// void draw_line(t_cube *cube, int x0, int y0, int x1, int y1, uint32_t color);
void draw_line(t_cube *cube, int x0, int y0, int x1, int y1, uint32_t color);
void draw_grid(t_cube *cube);
void	draw_player_direction(t_cube *cube);
#endif
