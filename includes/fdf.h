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
# include "config.h"
# include "keys.h"
# include "types.h"

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
