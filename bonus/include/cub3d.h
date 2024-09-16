/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:20:49 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/15 22:30:38 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "objects.h"

t_cube	*get_cube(t_cube *cube);

void	ft_reles(mlx_key_data_t keydata, t_cube *cube);
void	key_press(mlx_key_data_t keydata, void *ml);

void	turn_player(t_cube *cube, int turn);
void	movement(t_cube *cube, double move_x, double move_y);


//-------------------------------------ustils----------------------
double	deg2rad(double degrees);
int	ft_get_color(int r, int g, int b, int a);
void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color);
int	reverse_bytes(int c);
//-------------------------------parsing-------------------------

void	ft_parse_cube(char *file, t_cube *cube);
t_list	*ft_parse_clrs_textrs(t_list *head, t_cube *cube);
int		ft_parse_map(t_list *head, t_cube *cube);
void	ft_check_dbl_keys(t_cube *cube);
void	ft_fill_map2d(char ***map2d, t_list *head, int max_rows);
void	ft_valid_caras_walls(char **map2d);

// helpers functions
int		isnumbers(char **colors);
int		strslen(char **strs);
int		isranged(char **colors, int min, int max);
int		ft_isnumber(char *str);
int		empty_line(char *line);


//-------------------------------texture----------------------


mlx_texture_t	*get_texture(t_cube *cube, int flag);
double	calculate_texture_x(mlx_texture_t *texture, t_cube *cube);

//-------------------------------raycasting----------------------

double	reset_angle(float angle);
int		parsing_map(char *path, t_map *map);
double	normalize_angle(float angle);
void	raycasting(t_cube *cube);
void	render_wall(t_cube *cube, int ray);
double	calcul_distance(double x_inter, double y_inter, double p_x, double p_y);

// helper functions
double	deg2rad(double degrees);
int		ft_get_color(int r, int g, int b, int a);
void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color);
void	my_mlx_pixel_put2(t_cube *cube, int x, int y, int color);


//-------------------------------General utils--------------------
void	ft_error(char *msg);
void	print_fd(char *msg, int fd);
char	*ft_trim(char *str);

//-----------------------debug-------------------------

// void	draw_ray(t_cube *cube, double ray_angle);
// void	draw_rays(t_cube *cube);
void	render(t_cube *cube, double ray);
void	draw_rays(t_cube *cube);
// void	render(t_cube *mlx);

//-----------------------drawing-------------------------

void	draw_ceiling(t_cube *cube, int ray, int ceiling_end);
void	draw_wall(t_cube *cube, int wall_t, int wall_b, double wall_h);
void	draw_floor(t_cube *cube, int ray, int floor_start);
void	projected_wall(t_cube *cube, t_ray *ray);

//-----------------------drawing-------------------------
void	adjust_step(t_cube *cube, double *dx, double *dy, int is_vertical);
void	check_rayfacing(t_cube *cube,  double angle);
int	hit_wall(double x, double y, t_cube *cube);
void clear_image(mlx_image_t *img);

// void	draw_player(t_cube *cube);
// void    draw_player(t_cube *cube, int offset_x, int offset_y);
void    draw_player(t_cube *cube);
void	draw_minimap(t_cube *cube);
// void draw_line(t_cube *cube, int x0, int y0, int x1, int y1, uint32_t color);
void draw_line(t_cube *cube, int x0, int y0, int x1, int y1, uint32_t color);
void draw_grid(t_cube *cube);
void	init_ray(t_ray *ray, double angle);
int		hit_wall(double x, double y, t_cube *cube);

void	draw_player(t_cube *cube);
void	draw_minimap(t_cube *cube);
void	draw_line(t_cube *cube, int x0, int y0, int x1, int y1, uint32_t color);
void	draw_grid(t_cube *cube);
void	draw_player_direction(t_cube *cube);
#endif
