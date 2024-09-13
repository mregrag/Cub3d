/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:49:25 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/11 20:44:00 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef OBJECTS_H
#define OBJECTS_H

# include "macros.h"

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
	int		x;
	int		y;
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

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;


typedef struct s_txtr
{
	char			*key;
	char			*path;
}	t_txtr;

typedef struct s_colors
{
	char			*key;
	int				r;
	int				g;
	int				b;
}	t_colors;
typedef struct s_ray
{
	int		index;
	double		angl;
	double		hwallhit_x;
	double		hwallhit_y;
	double		vwallhit_x;
	double		vwallhit_y;
	double		hit_x;
	double		hit_y;
	double		distance;
	int		up;
	int		down;
	int		right;
	int		left;
	int		flag;
}	t_ray;

typedef struct s_cube
{
	mlx_image_t	*img;
	mlx_t		*window;
	t_map		*map;
	t_player	*plyer;
	t_ray		*rays;
	t_txtr		*txtrs[4];
	t_colors	*colors[2];
}	t_cube;

#endif
