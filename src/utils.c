#include "../includes/FdF.h"

int ft_count_colone(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
	{
		i++;
	}
	return (i);
}



int ft_count_line(char *str)
{
	int count;

	count = 1;
	while (*str)
	{
		if(*str == '\n')
			count++;
		str++;		
	}
	return (count);
}

void ft_alloc(int ***res, char *str)
{
	int i;

	i = 0;
	*res = malloc(sizeof(int *) * ft_count_line(str));
	while(i <= ft_count_line(str))
	{
		(*res)[i] = malloc(sizeof(int) * ft_count_colone(str));
		i++;
	}
}

void ft_read_map(t_map *s_map)
{
	int fd;
	int error;

	error = 0;
	fd = open("map/elem.fdf", O_RDONLY);
	// fd = open("mountain_50x100.fdf", O_RDONLY);
	s_map->map = read_alloc_fd(fd, &error);
}
