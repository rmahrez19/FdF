#ifndef FDF_H
#define FDF_H
#include "../libft/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "includes.h"
#define hexa "0123456789abcdef"


void ft_read_map(char *av, t_map *s_map);
void	ft_init(t_all *s_all);
void ft_alloc(float ***res, t_all s_all);
void error(void);
void ft_pars(t_map *s_map);
void	project(int	i, int	j, t_all *s_all);

int	init_window(t_all *s_all);
int	key_press(int keycode, void *param);
int pars_hexa(char *map);
int draw_map(t_all *s_all);
void	ft_init(t_all *s_all);
int ft_count_line(char *str);
int ft_count_colone(char *str);
void ft_init_read(char **str, char **buffer, int *size, int *line_len);

void	draw_pixel(t_data data, int x, int y);
void draw_line(t_data data, t_point *point);
void ft_exit(t_all *s_all);
void test(t_all *s_all);

#endif