/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:32:49 by ramahrez          #+#    #+#             */
/*   Updated: 2024/11/27 22:45:54 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void ft_place(char **res, int x, int y, int z)
{
	static int i = 0;
	res[i][x] = x;
	res[i][y] = y;
	res[i][z] = z;
	i++;
}

void	ft_test(char **res, t_map *s_map)
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
			count++;
			ft_place(res, count, (j + 1), ft_atoi(s_map + i));
			while(s_map->map[i] != ' ' && s_map->map[i] != 0)
				i++;
		}
		count = 0;
		j++;
	}
}



void project_isometric(int x, int y, int z, int *x_proj, int *y_proj) 
{
float angle = M_PI / 6; // 30 degres
*x_proj = (x - y) * cos(angle);
*y_proj = (x + y) * sin(angle) - z;
}