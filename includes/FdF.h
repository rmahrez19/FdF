#ifndef FDF_H
#define FDF_H
#include "../libft/libft.h"

typedef struct s_var
{
	char *map;
	int size_map;
}t_var;

void ft_read_map(t_var *s_var);

#endif