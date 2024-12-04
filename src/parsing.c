/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:32:49 by ramahrez          #+#    #+#             */
/*   Updated: 2024/12/04 06:00:51 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void ft_place(int **res, int x_a, int y_a, int z_a)
{
	static int i = 0;
	// printf("x_a %d\n", x_a);
	
	res[i][0] = x_a;
	res[i][1] = y_a;
	res[i][2] = z_a;
	i++;
}



int ft_count_axe(void)
{
	return(0);
}

void	ft_ordinate(t_map *s_map)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	count;

	k = 0;
	count = 0;
	i = 0;
	j = 0;
	while(s_map->map[i])
	{
		while(s_map->map[i] != '\n' && s_map->map[i] != 0)
		{
			while(s_map->map[i] == ' ')
				i++;	
			s_map->position[j][count] = ft_atoi(s_map->map + i);
			count++;
			while(s_map->map[i] != ' ' && s_map->map[i] != 0 && s_map->map[i] != '\n')
					i++;
		}
		if(s_map->map[i])
			i++;
		j++;
		count = 0;
	}
}




