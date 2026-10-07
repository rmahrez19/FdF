/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec3	to_plane(t_fdf *fdf, int x, int y)
{
	t_vec3	p;

	p.x = x - (fdf->map.width - 1) / 2.0f;
	p.y = y - (fdf->map.height - 1) / 2.0f;
	p.z = -fdf->map.alt[y][x] * fdf->view.alt_scale;
	return (p);
}

/*
** Enroule la grille sur une sphere : x devient la longitude, y la latitude,
** et l'altitude s'ajoute au rayon. Le +PI/2 place le centre de la map face
** a la camera.
*/
static t_vec3	to_sphere(t_fdf *fdf, int x, int y)
{
	t_vec3	p;
	float	lon;
	float	lat;
	float	r;

	lon = (float)x / fdf->map.width * 2 * M_PI + M_PI / 2;
	lat = M_PI / 2;
	if (fdf->map.height > 1)
		lat = (float)y / (fdf->map.height - 1) * M_PI;
	r = fdf->view.radius + fdf->map.alt[y][x] * fdf->view.alt_scale;
	p.x = r * sinf(lat) * cosf(lon);
	p.y = -r * cosf(lat);
	p.z = r * sinf(lat) * sinf(lon);
	return (p);
}

static t_vec3	rotate(t_vec3 p, t_view *v)
{
	t_vec3	t;

	t.x = p.x * cosf(v->rot_z) - p.y * sinf(v->rot_z);
	t.y = p.x * sinf(v->rot_z) + p.y * cosf(v->rot_z);
	p.x = t.x;
	p.y = t.y * cosf(v->rot_x) - p.z * sinf(v->rot_x);
	p.z = t.y * sinf(v->rot_x) + p.z * cosf(v->rot_x);
	t.x = p.x * cosf(v->rot_y) + p.z * sinf(v->rot_y);
	t.z = -p.x * sinf(v->rot_y) + p.z * cosf(v->rot_y);
	p.x = t.x;
	p.z = t.z;
	return (p);
}

/* Position 3D du point apres rotation, avant zoom et decalage. */
t_vec3	transform_point(t_fdf *fdf, int x, int y)
{
	if (fdf->view.sphere)
		return (rotate(to_sphere(fdf, x, y), &fdf->view));
	return (rotate(to_plane(fdf, x, y), &fdf->view));
}

/* Projection orthographique : la camera regarde vers +z. */
t_pixel	project_point(t_fdf *fdf, int x, int y)
{
	t_vec3	p;
	t_pixel	px;

	p = transform_point(fdf, x, y);
	px.x = roundf(p.x * fdf->view.zoom + WIN_WIDTH / 2 + fdf->view.offset_x);
	px.y = roundf(p.y * fdf->view.zoom + WIN_HEIGHT / 2 + fdf->view.offset_y);
	px.color = fdf->map.color[y][x];
	px.hidden = fdf->view.sphere && p.z > 0;
	return (px);
}
