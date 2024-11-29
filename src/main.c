#include "../includes/FdF.h"

void print(t_map s_map)
{
	int i = 0;

	while(i < ft_count(s_map.map))
	{
		printf("x%d = %d\n", i, s_map.position[i][0]);
		printf("y%d = %d\n", i, s_map.position[i][1]);
		printf("z%d = %d\n", i, s_map.position[i][2]);
		printf("\n-------%d------\n", i);
		i++;
	}
}

int main(void)
{
	t_map s_map;

	ft_read_map(&s_map);
	s_map.res = ft_split(s_map.map, '\n');
	ft_alloc(ft_count(s_map.map), &s_map.position, 3);
	ft_ordinate(&s_map);
	ft_alloc(ft_count(s_map.map), &s_map.derivate, 2);
	print(s_map);
	draw_map(s_map);
	// printf("\n%s", s_map.map);
	
}

