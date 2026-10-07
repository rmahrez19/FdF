/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	axis(t_view *v, t_action pos, t_action neg)
{
	return ((float)v->held[pos] - (float)v->held[neg]);
}

/*
** Zoom multiplicatif centre sur l'ecran : le decalage suit le zoom pour que
** la map ne glisse pas, et le zoom ne descend jamais sous MIN_ZOOM.
*/
static void	apply_zoom(t_view *v)
{
	float	factor;

	factor = powf(ZOOM_STEP, axis(v, ZOOM_IN, ZOOM_OUT));
	if (v->zoom * factor < MIN_ZOOM)
		factor = MIN_ZOOM / v->zoom;
	v->zoom *= factor;
	v->offset_x *= factor;
	v->offset_y *= factor;
}

/* Applique les touches maintenues ; renvoie false si aucune ne l'est. */
bool	apply_held_actions(t_fdf *fdf)
{
	t_view	*v;
	int		i;

	v = &fdf->view;
	i = 0;
	while (i < ACTION_COUNT && !v->held[i])
		i++;
	if (i == ACTION_COUNT)
		return (false);
	v->rot_x += ROT_STEP * axis(v, ROT_X_POS, ROT_X_NEG);
	v->rot_y += ROT_STEP * axis(v, ROT_Y_POS, ROT_Y_NEG);
	v->rot_z += ROT_STEP * axis(v, ROT_Z_POS, ROT_Z_NEG);
	v->offset_x += MOVE_STEP * axis(v, MOVE_RIGHT, MOVE_LEFT);
	v->offset_y += MOVE_STEP * axis(v, MOVE_DOWN, MOVE_UP);
	apply_zoom(v);
	v->alt_scale *= powf(Z_STEP, axis(v, Z_UP, Z_DOWN));
	return (true);
}
