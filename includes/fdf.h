/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"

# define WIN_WIDTH		1920
# define WIN_HEIGHT		1080
# define WIN_TITLE		"FdF"

# define DEFAULT_COLOR	0xFFFFFF
# define HEX_DIGITS		"0123456789abcdef"
# define HUD_COLOR		0xA0A0A0
# define FIT_RATIO		0.8

/* Vitesses appliquees a chaque image tant qu'une touche est maintenue */
# define ROT_STEP		0.02
# define MOVE_STEP		8
# define ZOOM_STEP		1.02
# define MIN_ZOOM		0.5
# define Z_STEP			1.02

# define KEY_ESC		65307
# define KEY_TAB		65289
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_I			105
# define KEY_K			107
# define KEY_P			112
# define KEY_O			111
# define KEY_T			116
# define KEY_G			103
# define KEY_R			114

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

/* map_read.c / map_parse.c / map_utils.c */
char	*read_file(const char *path);
void	load_map(const char *path, t_map *map);
int		count_words(char **words);
int		parse_hex(const char *str);
bool	is_valid_point(const char *str);

/* view.c */
void	reset_view(t_fdf *fdf);

/* transform.c */
t_vec3	transform_point(t_fdf *fdf, int x, int y);
t_pixel	project_point(t_fdf *fdf, int x, int y);

/* draw.c / hud.c */
void	put_pixel(t_img *img, int x, int y, int color);
void	draw_line(t_img *img, t_pixel a, t_pixel b);
void	render(t_fdf *fdf);
void	draw_hud(t_fdf *fdf);

/* events.c / actions.c */
int		on_key_press(int keycode, t_fdf *fdf);
int		on_key_release(int keycode, t_fdf *fdf);
int		on_close(t_fdf *fdf);
int		on_loop(t_fdf *fdf);
bool	apply_held_actions(t_fdf *fdf);

/* exit.c */
void	fatal(const char *msg);
void	fdf_exit(t_fdf *fdf, int status);

#endif
