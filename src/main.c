#include "../includes/FdF.h"

int main(void)
{
	t_map s_map;

	ft_read_map(&s_map);
	s_map.res = ft_split(s_map.map, '\n');
	printf("%lf", M_PI);
}