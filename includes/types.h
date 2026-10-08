/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>

/* Actions continues : actives tant que leur touche est enfoncee */
typedef enum e_action
{
	ROT_X_POS,
	ROT_X_NEG,
	ROT_Y_POS,
	ROT_Y_NEG,
	ROT_Z_POS,
	ROT_Z_NEG,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	ZOOM_IN,
	ZOOM_OUT,
	Z_UP,
	Z_DOWN,
	ACTION_COUNT
}	t_action;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_pixel
{
	int		x;
	int		y;
	int		color;
	bool	hidden;
}	t_pixel;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	len;
}	t_line;

typedef struct s_map
{
	int		width;
	int		height;
	int		**alt;
	int		**color;
	t_pixel	**proj;
	int		alt_min;
	int		alt_max;
}	t_map;

typedef struct s_view
{
	bool	sphere;
	float	zoom;
	float	alt_scale;
	float	radius;
	float	rot_x;
	float	rot_y;
	float	rot_z;
	float	offset_x;
	float	offset_y;
	bool	held[ACTION_COUNT];
}	t_view;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
	t_view	view;
}	t_fdf;

#endif
