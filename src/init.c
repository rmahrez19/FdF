/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:19:32 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/15 16:22:23 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	init_window(t_all *s_all)
{
	s_all->data.mlx_ptr = mlx_init();
	if (!s_all->data.mlx_ptr)
		return (1);
	s_all->data.win_ptr = mlx_new_window(s_all->data.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	if (!s_all->data.win_ptr)
	{
		free(s_all->data.mlx_ptr);
		return (1);
	}
	return (0);
}

void	ft_init(t_all *s_all)
{
	s_all->point.x_end = 0;
    s_all->point.y_end = 0;
	s_all->point.zoom = 10;
	s_all->point.angle = 3.14159 / 6;
	s_all->point.x = 2;
	s_all->point.y = 2;
	s_all->point.x_line = ft_count_colone(s_all->map.map);
	s_all->point.y_line = ft_count_line(s_all->map.map);
	s_all->point.x_rot = 0;
	s_all->point.y_rot = 0;
	s_all->point.z_rot = 0;
	s_all->point.x_start = 0;
	s_all->point.y_start = 0;
}