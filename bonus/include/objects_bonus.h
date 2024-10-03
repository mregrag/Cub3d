/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:49:25 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/03 15:40:53 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_BONUS_H
# define OBJECTS_BONUS_H

# include "macros_bonus.h"

typedef enum e_walk
{
	STOP,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	TURN_RIGHT,
	TURN_LEFT,
}	t_walk;

typedef struct s_dpoint
{
	double	x;
	double	y;
}	t_dpoint;

typedef struct s_ipoint
{
	int	x;
	int	y;
}	t_ipoint;

typedef struct s_player
{
	t_dpoint	s;
	t_dpoint	m;
	double		derection;
	double		fov;
	t_walk		turn;
	t_walk		walk;

}	t_player;

typedef struct s_map
{
	char		**map2d;
	char		**textur2d;
	t_ipoint	m;
	t_ipoint	p;
	int			width;
	int			height;
	int			fd;
	char		*line;
	char		*map;
	char		*tex;
}	t_map;

typedef struct s_textur
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	mlx_texture_t	*door;
}	t_textur;

typedef struct s_txtr
{
	char			*key;
	char			*path;
}	t_txtr;

typedef struct s_colors
{
	char	*key;
	int		r;
	int		g;
	int		b;
}	t_colors;

typedef struct s_ray
{
	double		angl;
	t_dpoint	hwall;
	t_dpoint	vwall;
	double		distance;
	double		angle;
	int			index;
	int			up;
	int			down;
	int			right;
	int			left;
	int			was_hit_vertical;
	int			hit_door;
}	t_ray;

typedef struct s_sprite
{
	int			x;
	int			y;
	int			visible;
	int			width;
	int			height;
	mlx_image_t	*img;
}	t_sprite;

typedef struct s_door
{
	t_ipoint	pos;
	int			hit_door_h;
	int			hit_door_v;
	int			hit_door;
	int			is_door_open;
	int			is_door_closed;

}	t_door;
typedef struct s_cube
{
	mlx_image_t		*img;
	mlx_image_t		*img3;
	int				shoot;
	mlx_t			*window;
	t_map			*map;
	t_player		*plyer;
	t_ray			*ray;
	t_textur		*textur;
	t_txtr			*txtrs[6];
	t_colors		*colors[6];
	t_sprite		*sprites[6];
	t_door			*door;
	int				mouse_enabled;

}	t_cube;

#endif
