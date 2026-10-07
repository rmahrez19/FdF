/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	compute_bounds(t_fdf *fdf, t_vec3 *min, t_vec3 *max)
{
	t_vec3	p;
	int		x;
	int		y;

	*min = transform_point(fdf, 0, 0);
	*max = *min;
	y = -1;
	while (++y < fdf->map.height)
	{
		x = -1;
		while (++x < fdf->map.width)
		{
			p = transform_point(fdf, x, y);
			min->x = fminf(min->x, p.x);
			min->y = fminf(min->y, p.y);
			max->x = fmaxf(max->x, p.x);
			max->y = fmaxf(max->y, p.y);
		}
	}
}

/* Choisit le zoom et le decalage pour que toute la map tienne a l'ecran. */
static void	fit_to_window(t_fdf *fdf)
{
	t_vec3	min;
	t_vec3	max;
	float	zoom_x;
	float	zoom_y;

	compute_bounds(fdf, &min, &max);
	zoom_x = WIN_WIDTH / fmaxf(max.x - min.x, 1);
	zoom_y = WIN_HEIGHT / fmaxf(max.y - min.y, 1);
	fdf->view.zoom = FIT_RATIO * fminf(zoom_x, zoom_y);
	fdf->view.offset_x = -(min.x + max.x) / 2 * fdf->view.zoom;
	fdf->view.offset_y = -(min.y + max.y) / 2 * fdf->view.zoom;
}

/* Remet la vue par defaut du mode courant (plat ou sphere). */
void	reset_view(t_fdf *fdf)
{
	t_view	*v;
	float	alt_range;

	v = &fdf->view;
	alt_range = fmaxf(abs(fdf->map.alt_min), abs(fdf->map.alt_max));
	v->rot_x = 0;
	v->rot_y = 0;
	v->rot_z = 0;
	v->alt_scale = 1;
	v->radius = fdf->map.width / (2 * M_PI);
	if (v->sphere && alt_range > 0)
		v->alt_scale = v->radius * 0.2 / alt_range;
	if (!v->sphere)
	{
		v->rot_x = -atanf(sqrtf(2));
		v->rot_z = M_PI / 4;
	}
	fit_to_window(fdf);
}
