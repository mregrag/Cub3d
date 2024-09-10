/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:20:49 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/30 18:38:11 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "objects.h"

t_cube	*get_cube(t_cube *cube);

void	ft_reles(mlx_key_data_t keydata, t_cube *cube);
void	key_press(mlx_key_data_t keydata, void *ml);

void	turn_player(t_cube *cube, int turn);
void	walk_player(t_cube *cube, double move_x, double move_y);
void	movement(t_cube *cube, double move_x, double move_y);


//-------------------------------parsing-------------------------

int	    parsing_map(char *path, t_map *map);

void	ft_parse_cube(char *file, t_cube *cube);
t_list	*ft_parse_clrs_textrs(t_list *head, t_cube *cube);
int		ft_parse_map(t_list *head, t_cube *cube);
// helpers functions
int		isnumbers(char **colors);
int		strslen(char **strs);
int		isranged(char **colors, int min, int max);
int		in_txtrs_set(char *txtr);
int     ft_isnumber(char *str);
int     empty_line(char *line);





//-------------------------------raycasting----------------------

double	reset_angle(float angle);
void	raycasting(t_cube *cube);
void	render_wall(t_cube *cube, int ray);

// helper functions
double	deg2rad(double degrees);
int	    ft_get_color(int r, int g, int b, int a);
void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color);

//-------------------------------General utils--------------------
void	ft_error(char *msg);
void	print_fd(char *msg, int fd);
char	*ft_trim(char *str);


//-----------------------debug-------------------------

void	draw_grid(mlx_image_t *img, uint32_t color, int tile_size);
void	draw_player(t_cube *cube);
void	draw_ray(t_cube *cube, double ray_angle);
void	draw_rays(t_cube *cube);

#endif
