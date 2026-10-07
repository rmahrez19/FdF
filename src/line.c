/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	lerp_color(int c1, int c2, float t)
{
	int	r;
	int	g;
	int	b;

	r = ((c1 >> 16) & 0xFF) + (((c2 >> 16) & 0xFF) - ((c1 >> 16) & 0xFF)) * t;
	g = ((c1 >> 8) & 0xFF) + (((c2 >> 8) & 0xFF) - ((c1 >> 8) & 0xFF)) * t;
	b = (c1 & 0xFF) + ((c2 & 0xFF) - (c1 & 0xFF)) * t;
	return ((r << 16) | (g << 8) | b);
}

static bool	is_offscreen(t_pixel a, t_pixel b)
{
	return ((a.x < 0 && b.x < 0) || (a.y < 0 && b.y < 0)
		|| (a.x >= WIN_WIDTH && b.x >= WIN_WIDTH)
		|| (a.y >= WIN_HEIGHT && b.y >= WIN_HEIGHT));
}

static void	init_line(t_line *l, t_pixel a, t_pixel b)
{
	l->dx = abs(b.x - a.x);
	l->dy = -abs(b.y - a.y);
	l->sx = 1;
	if (a.x > b.x)
		l->sx = -1;
	l->sy = 1;
	if (a.y > b.y)
		l->sy = -1;
	l->err = l->dx + l->dy;
	l->len = l->dx;
	if (-l->dy > l->len)
		l->len = -l->dy;
}

/* Bresenham, avec un degrade entre la couleur de a et celle de b. */
void	draw_line(t_img *img, t_pixel a, t_pixel b)
{
	t_line	l;
	t_pixel	cur;
	int		step;
	int		e2;

	if (is_offscreen(a, b))
		return ;
	init_line(&l, a, b);
	cur = a;
	step = 0;
	while (step <= l.len)
	{
		put_pixel(img, cur.x, cur.y,
			lerp_color(a.color, b.color, (float)step / fmaxf(l.len, 1)));
		e2 = 2 * l.err;
		if (e2 >= l.dy)
		{
			l.err += l.dy;
			cur.x += l.sx;
		}
		if (e2 <= l.dx)
		{
			l.err += l.dx;
			cur.y += l.sy;
		}
		step++;
	}
}
