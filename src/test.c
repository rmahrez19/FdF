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

void ft_alloc(int size, int **res)
{
	size_t i;

	i = 0;
	res = malloc(sizeof(int *) * size);
	while(i < size)
	{
		res[i] = malloc(sizeof(int) * 3);
		i++;
	}
}

void ft_read_map(t_map *s_map)
{
	int fd;
	//int old_size;
	int new_size;
	int nread;

	//old_size = 1024;
	new_size = 0;
	nread = 0;
	fd = open("map/test.fdf", O_RDONLY);
	while(new_size == nread)
	{
		nread = read(fd, s_map->map, 1024);

	s_map->map[nread - 1] = 0;
		//s_map->map = ft_realloc(s_map->map, old_size, old_size + nread, 1);
	}
	s_map->size_map = ft_count(s_map->map);
	printf("%s\n", s_map->map);
}

// void project_isometric(int x, int y, int z, int *x_proj, int *y_proj) {
// float angle = M_PI / 6; // 30 degres
// *x_proj = (x - y) * cos(angle);
// *y_proj = (x + y) * sin(angle) - z;
// }