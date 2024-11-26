#include "../includes/FdF.h"

void ft_read_map(t_var *s_var)
{
	int fd;
	int old_size;
	int new_size;
	int nread;

	old_size = 0;
	new_size = 0;
	fd = open("map/test.fdf", O_RDONLY);
	while(s_var->size_map == nread && buffer[new_size] != 0)
	{
		read(fd, str, 5000);
		str[nread] = 0;
	}
	printf("%s", str);
}