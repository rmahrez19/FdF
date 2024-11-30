#ifndef FDF_H
#define FDF_H
#include "../libft/libft.h"
#include <math.h>

// #define x 0
// #define y 1
// #define z 2

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct s_data {
    void    *mlx_ptr;
    void    *win_ptr;
} t_data;

typedef struct s_map
{
	char	*map;
	int		**derivate;
	int		**position;
	char 	**res;
}t_map;

typedef struct s_point
{
	int temp_x_proj;
	int temp_y_proj;
	int temp_x;
	int temp_y;
	
}t_point;

#ifndef M_PI
#define M_PI
#endif

int ft_count(char *str);
void	ft_ordinate(t_map *s_map);
void	ft_alloc(size_t size, int ***res, int len);
void	ft_read_map(t_map *s_map);
char	*read_alloc_fd(int fd, int *error);
int draw_map(t_map s_map);
void    draw_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int color);

#endif