/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Renvoie l'action liee a la touche, ou ACTION_COUNT si aucune. */
static int	key_to_action(int keycode)
{
	static const int	keys[ACTION_COUNT] = {KEY_UP, KEY_DOWN, KEY_RIGHT,
		KEY_LEFT, KEY_I, KEY_K, KEY_A, KEY_D, KEY_W, KEY_S, KEY_P, KEY_O,
		KEY_T, KEY_G};
	int					i;

	i = 0;
	while (i < ACTION_COUNT && keys[i] != keycode)
		i++;
	return (i);
}

int	on_key_press(int keycode, t_fdf *fdf)
{
	int	action;

	if (keycode == KEY_ESC)
		fdf_exit(fdf, EXIT_SUCCESS);
	if (keycode == KEY_TAB)
		fdf->view.sphere = !fdf->view.sphere;
	if (keycode == KEY_TAB || keycode == KEY_R)
	{
		reset_view(fdf);
		render(fdf);
	}
	action = key_to_action(keycode);
	if (action < ACTION_COUNT)
		fdf->view.held[action] = true;
	return (0);
}

int	on_key_release(int keycode, t_fdf *fdf)
{
	int	action;

	action = key_to_action(keycode);
	if (action < ACTION_COUNT)
		fdf->view.held[action] = false;
	return (0);
}

int	on_close(t_fdf *fdf)
{
	fdf_exit(fdf, EXIT_SUCCESS);
	return (0);
}

int	on_loop(t_fdf *fdf)
{
	if (apply_held_actions(fdf))
		render(fdf);
	return (0);
}
