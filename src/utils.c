#include "../includes/FdF.h"

int ft_count_colone(char *str)
{
	size_t count;
	size_t i;

	i = 0;
	count = 0;
	while (str[i] != '\n' && str[i] != 0)
	{
		while(str[i] == ' ')
			i++;
		if(str[i])
			count++;
		while(str[i] != ' ' && str[i] && str[i] != '\n')
			i++;
	}
	return (count);
}



int ft_count_line(char *str)
{
	int count;
	int i;

	i = 0;
	count = 1;
	while (str[i])
	{
		if(str[i] == '\n')
			count++;
		i++;		
	}
	return (count);
}

void ft_alloc(float ***res, char *str)
{
	int i;

	i = 0;
	*res = ft_malloc(sizeof(float *) * ft_count_line(str));
	while(i <= ft_count_line(str))
	{
		(*res)[i] = malloc(sizeof(float) * ft_count_colone(str));
		i++;
	}
}

void ft_read_map(char *av, t_map *s_map)
{
	int fd;
	int error;

	error = 0;
	fd = open(av, O_RDONLY);
	// fd = open("mountain_50x100.fdf", O_RDONLY);
	s_map->map = read_alloc_fd(fd, &error);
}
