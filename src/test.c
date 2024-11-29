#include "../includes/FdF.h"

int ft_count(char *str)
{
	size_t count;

	count = 1;
	while(*str)
	{
		if(*str == '\n')
			count++;
		if(*str == ' ')
		{
			count++;
			str++;
		}

		str++;
	}
	return(count);
}

void ft_alloc(size_t size, int ***res, int len)
{
	size_t i;

	i = 0;
	*res = malloc(sizeof(int *) * (size + 1));
	while(i < size)
	{
		(*res)[i] = malloc(sizeof(int) * len);
		i++;
	}
}

void ft_read_map(t_map *s_map)
{
	int fd;
	int error;
	
	error = 0;
	fd = open("map/test.fdf", O_RDONLY);
	s_map->map = read_alloc_fd(fd, &error);
}

