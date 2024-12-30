#ifndef FDF_H
#define FDF_H
#include "../libft/libft.h"
#include <math.h>
#include "mlx.h"
#include "includes.h"

// #define x 0
// #define y 1
// #define z 2

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define ESC_KEY 65307 //touche clavier
#define n = 10

#ifndef M_PI
#define M_PI
#endif



void draw_line(void *mlx_ptr, void *win_ptr, t_point *point);
void project_isometric(int x, int y, int z, t_point *point, void *mlx_ptr, void *win_ptr);
void ft_project_isometric(int x, int y, int z, t_point *point, void *mlx_ptr, void *win_ptr);
int ft_count_line(char *str);
int ft_count_colone(char *str);
void	ft_ordinate(t_map *s_map);
void	ft_alloc(float ***res, char *str);
void	ft_read_map(char *av, t_map *s_map);
char	*read_alloc_fd(int fd, int *error);
int draw_map(t_map s_map);
int key_press(int keycode, void *param);
void ft_normalise(t_map *s_map);

#endif