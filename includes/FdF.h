#ifndef FDF_H
#define FDF_H
#include "../libft/libft.h"

typedef struct s_map
{
	char map[1024];
	int size_map;
	int *postion[3];
}t_map;

void ft_read_map(t_map *s_var);

#endif