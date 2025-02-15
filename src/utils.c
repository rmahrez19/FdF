/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:27:03 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/15 16:21:39 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int ft_count_colone(char *str)
{
	size_t count;
	size_t i;

	i = 0;
	count = 0;
	while (str[i] != '\n' && str[i] != 0)
	{
		while(str[i] == ' ')
			i++;
		if(str[i])
			count++;
		while(str[i] != ' ' && str[i] && str[i] != '\n')
			i++;
	}
	return (count);
}

int ft_count_line(char *str)
{
	int count;
	int i;

	i = 0;
	count = 1;
	while (str[i])
	{
		if(str[i] == '\n')
			count++;
		i++;		
	}
	return (count);
}

void ft_alloc(float ***res, t_all s_all)
{
	int i;

	i = 0;
	*res = 	ft_malloc(sizeof(float *) * (s_all.point.y_line));
	if(!res)
		error();
	while(i < s_all.point.y_line)
	{
		(*res)[i] = ft_malloc(sizeof(float) * (s_all.point.x_line));
		i++;
	}
}



void ft_displaystr(t_all s_all)
{
    mlx_string_put(s_all.data.mlx_ptr, s_all.data.win_ptr, 20, 50,  0xFFFFFF, rules_a);
    mlx_string_put(s_all.data.mlx_ptr, s_all.data.win_ptr, 20, 65,  0xFFFFFF, rules_b);
    mlx_string_put(s_all.data.mlx_ptr, s_all.data.win_ptr, 20, 80,  0xFFFFFF, rules_c);
    mlx_string_put(s_all.data.mlx_ptr, s_all.data.win_ptr, 20, 95,  0xFFFFFF, rules_d);
}
