/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:49:25 by mregrag           #+#    #+#             */
/*   Updated: 2024/08/28 06:55:21 by mregrag          ###   ########.fr       */
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

typedef struct s_ray
{
	int		index;
	double		angl;
	double		horiz_x;
	double		horiz_y;
	double		vert_x;
	double		vert_y;
	double		distance;
	int		facingup;
	int		facingdown;
	int		facingright;
	int		facingleft;
	int		flag;
}	t_ray;

typedef struct s_cube
{
	mlx_image_t	*img;
	mlx_t		*window;
	t_map		*map;
	t_player	*plyer;
	t_ray			*ray;
}	t_cube;

#endif
