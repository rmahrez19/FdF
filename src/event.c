/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:54:33 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/16 18:38:41 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	ft_event(int keycode, t_all *s_all)
{
	if (keycode == UP_KEY)
		s_all->point.x_rot += 0.05;
	if (keycode == DOWN_KEY)
		s_all->point.x_rot -= 0.05;
	if (keycode == I_KEY)
		s_all->point.z_rot += 0.05;
	if (keycode == K_KEY)
		s_all->point.z_rot -= 0.05;
	if (keycode == R_KEY)
		ft_init(s_all);
	if (keycode == A_KEY)
		s_all->point.x -= 20;
	if (keycode == D_KEY)
		s_all->point.x += 20;
	if (keycode == W_KEY)
		s_all->point.y -= 20;
	if (keycode == S_KEY)
		s_all->point.y += 20;
	if (keycode == T_KEY)
		s_all->point.up += 1;
	if (keycode == G_KEY)
		s_all->point.up -= 1;
}

int	key_press(int keycode, void *param)
{
	t_all	*s_all;

	s_all = (t_all *)param;
	if (keycode == ESC_KEY)
		ft_exit(s_all);
	if (keycode == P_KEY)
		s_all->point.zoom = s_all->point.zoom + 2;
	if (keycode == O_KEY)
		s_all->point.zoom = s_all->point.zoom - 2;
	if (keycode == RIGHT_KEY)
	{
		s_all->point.y_rot += 0.05;
	}
	if (keycode == LEFT_KEY)
		s_all->point.y_rot -= 0.05;
	else
	{
		ft_event(keycode, s_all);
	}
	mlx_destroy_image(s_all->data.mlx_ptr, s_all->data.img_ptr);
	test(s_all);
	return (1);
}
