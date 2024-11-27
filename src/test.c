#include "../includes/FdF.h"

int ft_count(char *str)
{
	size_t count;

	count = 0;
	while(str)
	{
		if(*str == '\n' || *str ==' ')
			count++;
		str++;
	}
	return(count);
}	


void ft_read_map(t_map *s_var)
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
		nread = read(fd, s_var->map, 1024);

	s_var->map[nread - 1] = 0;
		//s_var->map = ft_realloc(s_var->map, old_size, old_size + nread, 1);
	}

	printf("%s\n", s_var->map);
	printf("compte = %d", ft_count(s_var->map));	
}
