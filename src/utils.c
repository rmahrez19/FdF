/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:27:03 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/16 16:29:06 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	ft_count_colone(char *str)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i] != '\n' && str[i] != 0)
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] != ' ' && str[i] && str[i] != '\n')
			i++;
	}
	return (count);
}

int	ft_count_line(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void	ft_alloc(float ***res, t_all s_all)
{
	int	i;

	i = 0;
	*res = ft_malloc(sizeof(float *) * (s_all.point.y_line));
	if (!res)
		error();
	while (i < s_all.point.y_line)
	{
		(*res)[i] = ft_malloc(sizeof(float) * (s_all.point.x_line));
		i++;
	}
}

void ft_exit(t_all *s_all)
{
	ft_free();
	free(s_all->map.map);
	mlx_destroy_image(s_all->data.mlx_ptr, s_all->data.img_ptr);
	mlx_destroy_window(s_all->data.mlx_ptr, s_all->data.win_ptr);
    mlx_destroy_display(s_all->data.mlx_ptr);
	free(s_all->data.mlx_ptr);
	exit(0);
}