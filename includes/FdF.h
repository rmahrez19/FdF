#ifndef FDF_H
#define FDF_H
#include "../libft/libft.h"
#include <math.h>

// #define x 0
// #define y 1
// #define z 2

typedef struct s_map
{
	char	*map;
	int		**derivate;
	int		**position;
	char 	**res;
}t_map;

#ifndef M_PI
#define M_PI
#endif

int ft_count(char *str);
void	ft_ordinate(t_map *s_map);
void	ft_alloc(size_t size, int ***res, int len);
void	ft_read_map(t_map *s_map);
char	*read_alloc_fd(int fd, int *error);

#endif