/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:14:38 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/12 15:29:35 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"


void ft_print_tab(int **tab, t_all s_all)
{
	int i = 0;
	int j = 0;
	
	while(i < s_all.point.y_line)
	{
		while(j < s_all.point.x_line)
		{
			printf("%d", tab[i][j]);
			j++;		
		}
		// printf("")	
		j = 0;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_all	s_all;

	(void)ac;
	ft_read_map(av[1], &s_all.map);
	s_all.map.res = ft_split(s_all.map.map, '\n');
	ft_init(&s_all);
	ft_alloc(&s_all.map.position_z, s_all);
	if (s_all.map.map)
		ft_alloc((float ***)&s_all.map.color, s_all);
	ft_pars(&s_all.map);
	printf("%s", s_all.map.map);
	// ft_print_tab((int **)s_all.map.position_z, s_all);
	write(1, "ok", 3);
	draw_map(&s_all);
	ft_free();
}
 