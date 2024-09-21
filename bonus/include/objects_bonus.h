/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:49:25 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/21 11:56:33 by mregrag          ###   ########.fr       */
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
	t_ipoint	m;
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

typedef struct s_cube
{
	mlx_image_t		*img;
	mlx_image_t		*img2;
	mlx_image_t		*img3;
	int				shoot;
	mlx_texture_t	*red_p;
	mlx_t			*window;
	t_map			*map;
	t_player		*plyer;
	t_ray			*ray;
	t_textur		*textur;
	t_txtr			*txtrs[6];
	t_colors		*colors[6];
	t_sprite		*sprites[6];
}	t_cube;

#endif
