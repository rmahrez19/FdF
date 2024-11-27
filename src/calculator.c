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

void	ft_test(char **res, t_map *s_map)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count = 0;
	i = 0;
	j = 0;
	while(j < s_map->size_map)
	{
		
	}
}



void project_isometric(int x, int y, int z, int *x_proj, int *y_proj) {
float angle = M_PI / 6; // 30 degres
*x_proj = (x - y) * cos(angle);
*y_proj = (x + y) * sin(angle) - z;
}