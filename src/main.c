#include "../includes/FdF.h"

void print(t_map s_map)
{
	int i = 0;
	int j = 0;

	while(i < ft_count_line(s_map.map))
	{
		while(j < ft_count_colone(s_map.map))
		{
			printf("x = %d || y = %d || z = %d\n", j + 1, i + 1 , s_map.position[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

int main(void)
{
	t_map s_map;
	int i = 0;

	printf("log%d\n", i++);
	ft_read_map(&s_map);
	printf("log%d\n", i++);
	s_map.res = ft_split(s_map.map, '\n');
	ft_alloc(&s_map.position, s_map.map);
	printf("logtew%d\n", i++);
	printf("allocation ok\n");
	ft_ordinate(&s_map);
	printf("placement reussi");
	// print(s_map);
	// print(s_map);
	draw_map(s_map);
	 printf("\ntest");
	
}

