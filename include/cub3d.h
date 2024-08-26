/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:20:49 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/26 00:05:43 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/MLX42.h"
# include "../lib/Libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>

# define WIDTH 1200
# define HEIGHT 800
# define MINI_W 200
# define MINI_H 200
# define TILE_SIZE 42
# define FOV 60
# define ROTATION_SPEED 0.042
# define MOVE_SPEED 2

typedef enum e_walk
{
	STOP,
	LEFT,
	RIGHT,
	UP,
	DOWN,
}	t_walk;

typedef struct s_player
{
	int		plyr_x;
	int		plyr_y;
	double	derection;
	float	fov;
	int		turn;
	int		walk;
	int		m_x;
	int		m_y;

}	t_player;

typedef struct s_map
{
	char	**map2d;
	int		p_x;
	int		p_y;
	int		w_map;
	int		h_map;
	int		cols;
	int		rows;
	int		fd;
	char	*line;
	char	*map;
}	t_map;

typedef struct s_ray
{
	int		index;
	double	ray_angl;
	double	horiz_x;
	double	horiz_y;
	double	vert_x;
	double	vert_y;
	double	distance;
	int		flag;
}	t_ray;

typedef struct s_mlx
{
	mlx_image_t	*img;
	mlx_t		*win;
	t_map		*map;
	t_player	*plyer;
	t_ray			*rays;
}	t_mlx;


void	ft_reles(mlx_key_data_t keydata, t_mlx *mlx);
void	key_press(mlx_key_data_t keydata, void *ml);

void	turn_player(t_mlx *mlx, int turn);
void	walk_player(t_mlx *mlx, double move_x, double move_y);
void	movement(t_mlx *mlx, double move_x, double move_y);


//-------------------------------------ustils----------------------
double	deg2rad(double degrees);
int	ft_get_color(int r, int g, int b, int a);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

int	parsing_map(char *path, t_map *map);
double	reset_angle(float angle);
void	raycasting(t_mlx *mlx);
void	render_wall(t_mlx *mlx, int ray);

//-----------------------debug-------------------------

void	draw_grid(mlx_image_t *img, uint32_t color, int tile_size);
void	draw_player(t_mlx *mlx);
void	draw_ray(t_mlx *mlx, double ray_angle);
void	draw_rays(t_mlx *mlx);

#endif
