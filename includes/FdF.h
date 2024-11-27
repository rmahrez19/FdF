#ifndef FDF_H
#define FDF_H
#include "../libft/libft.h"
#include <math.h>
typedef struct s_map
{
	char	map[1024];
	int		size_map;
	int		**position;
	char 	**res;
}t_map;

#ifndef M_PI
#define M_PI
#endif

void	ft_alloc(int size, int **res);
void	ft_read_map(t_map *s_map);

#endif