/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:20:49 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/20 10:22:27 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "objects_bonus.h"

/* Core Functions */
t_cube			*ft_get_cube(t_cube *cube);
void			key_press(mlx_key_data_t keydata, void *ml);
void			movement(t_cube *cube, double move_x, double move_y);

/* Utils */
void			my_pixel_put(mlx_image_t *img, uint32_t x, \
	uint32_t y, uint32_t color);
double			calcul_distance(t_dpoint start, t_dpoint end);
uint32_t		ft_get_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
int				reverse_bytes(int c);

/* Parsing */
t_list			*ft_parse_clrs_textrs(t_list *head, t_cube *cube);
void			ft_check_dbl_keys(t_cube *cube);
void			ft_fill_map2d(char ***map2d, t_list *head, int max_rows);
void			ft_valid_caras_walls(char **map2d);
void			ft_parse_cube(char *file, t_cube *cube);

/* Parsing Helpers */
int				isnumbers(char **colors);
int				strslen(char **strs);
int				isranged(char **colors, int min, int max);
int				ft_isnumber(char *str);
int				empty_line(char *line);
int				ft_parse_map(t_list *head, t_cube *cube);

/* Texture */
double			calculate_texture_x(mlx_texture_t *texture, t_cube *cube);
mlx_texture_t	*get_texture(t_cube *cube);
void			ft_load_txtrs(t_cube *cube);

/* Raycasting */
int				parsing_map(char *path, t_map *map);
double			normalize_angle(float angle);
void			raycasting(t_cube *cube);
void			walk_player(t_cube *cube, double move_x, double move_y);

/* General Utils */
void			ft_error(char *msg);
void			print_fd(char *msg, int fd);
char			*ft_trim(char *str);
void			ft_clear_img(mlx_image_t *img);
void			ft_init_cube(t_cube *cube);
void			ft_destroy_all(t_cube *cube);

/* Sprites */
void			ft_load_sprites(t_cube *cube);
void			ft_sprites(t_cube *cube, int *i, int *j);

/* Drawing */
void			projected_wall(t_cube *cube);
void			draw_minimap(t_cube *cube);
void			draw_player(t_cube *cube);
void			adjust_step(t_cube *cube, t_dpoint *delta, int is_vertical);
void			check_rayfacing(t_cube *cube, double angle);
int				hit_wall(double x, double y, t_cube *cube);

#endif
