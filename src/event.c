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

static int	rot_bit(int keycode)
{
	if (keycode == UP_KEY)
		return (1);
	if (keycode == DOWN_KEY)
		return (2);
	if (keycode == RIGHT_KEY)
		return (4);
	if (keycode == LEFT_KEY)
		return (8);
	if (keycode == I_KEY)
		return (16);
	if (keycode == K_KEY)
		return (32);
	return (0);
}

void	ft_event(int keycode, t_all *s_all)
{
	if (keycode == R_KEY)
		ft_init(s_all);
	if (keycode == P_KEY)
		s_all->point.zoom = s_all->point.zoom + 2;
	if (keycode == O_KEY)
		s_all->point.zoom = s_all->point.zoom - 2;
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
	if (rot_bit(keycode))
	{
		s_all->point.rot_keys |= rot_bit(keycode);
		return (0);
	}
	ft_event(keycode, s_all);
	render(s_all);
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_all	*s_all;

	s_all = (t_all *)param;
	s_all->point.rot_keys &= ~rot_bit(keycode);
	return (0);
}

int	loop_hook(void *param)
{
	t_all	*s_all;
	int		keys;

	s_all = (t_all *)param;
	keys = s_all->point.rot_keys;
	if (!keys)
		return (0);
	s_all->point.x_rot += ROT_SPEED * (!!(keys & 1) - !!(keys & 2));
	s_all->point.y_rot += ROT_SPEED * (!!(keys & 4) - !!(keys & 8));
	s_all->point.z_rot += ROT_SPEED * (!!(keys & 16) - !!(keys & 32));
	render(s_all);
	return (0);
}
