/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:20:49 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/16 13:39:24 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "objects.h"

t_cube	*ft_get_cube(t_cube *cube);
void	key_press(mlx_key_data_t keydata, void *ml);
void	movement(t_cube *cube, double move_x, double move_y);

//-------------------------------------ustils----------------------
int		ft_get_color(int r, int g, int b, int a);
void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color);
int		reverse_bytes(int c);

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
double          calculate_texture_x(mlx_texture_t *texture, t_cube *cube);
void	        ft_load_txtrs(t_cube *cube);

//-------------------------------raycasting----------------------
int		parsing_map(char *path, t_map *map);
double	normalize_angle(float angle);
void	raycasting(t_cube *cube);
double	calcul_distance(double x_inter, double y_inter, double p_x, double p_y);
void    walk_player(t_cube *cube, double move_x, double move_y);
// helper functions
int		ft_get_color(int r, int g, int b, int a);
void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color);

//-------------------------------General utils--------------------
void	ft_error(char *msg);
void	print_fd(char *msg, int fd);
char	*ft_trim(char *str);
void	ft_clear_img(mlx_image_t *img);
void	ft_init_cube(t_cube *cube);
t_cube	*ft_get_cube(t_cube *cube);
void	ft_destroy_all(t_cube *cube);

//-----------------------drawing-------------------------
void	projected_wall(t_cube *cube);

//-----------------------drawing-------------------------
void	adjust_step(t_cube *cube, double *dx, double *dy, int is_vertical);
void	check_rayfacing(t_cube *cube, double angle);
int		hit_wall(double x, double y, t_cube *cube);
#endif
