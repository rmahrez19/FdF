#include "../includes/FdF.h"

int main(void)
{
	t_map s_map;

	ft_read_map(&s_map);
	s_map.res = ft_split(s_map.map, '\n');
	ft_alloc(s_map.size_map, s_map.position);
	ft_test(s_map.res, &s_map);
	printf("%lf", M_PI);
}