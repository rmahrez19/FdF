#ifndef FDF_H
#define FDF_H
#include "../libft/libft.h"
#include <math.h>

#define x 0
#define y 1
#define z 2

typedef struct s_map
{
	char	map[1024];
	size_t		size_map;
	int		**position;
	char 	**res;
}t_map;

#ifndef M_PI
#define M_PI
#endif

void	ft_test(char **res, t_map *s_map);
void	ft_alloc(size_t size, int **res);
void	ft_read_map(t_map *s_map);

#endif