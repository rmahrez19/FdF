/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(unsigned int *)dst = color;
}

static void	project_all(t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	while (++y < fdf->map.height)
	{
		x = -1;
		while (++x < fdf->map.width)
			fdf->map.proj[y][x] = project_point(fdf, x, y);
	}
}

static void	link_points(t_img *img, t_pixel a, t_pixel b)
{
	if (a.hidden && b.hidden)
		return ;
	draw_line(img, a, b);
}

/* En mode sphere, la derniere colonne est reliee a la premiere. */
static void	draw_grid(t_fdf *fdf)
{
	t_pixel	**p;
	int		x;
	int		y;

	p = fdf->map.proj;
	y = -1;
	while (++y < fdf->map.height)
	{
		x = -1;
		while (++x < fdf->map.width)
		{
			if (x + 1 < fdf->map.width)
				link_points(&fdf->img, p[y][x], p[y][x + 1]);
			else if (fdf->view.sphere && fdf->map.width > 2)
				link_points(&fdf->img, p[y][x], p[y][0]);
			if (y + 1 < fdf->map.height)
				link_points(&fdf->img, p[y][x], p[y + 1][x]);
		}
	}
}

void	render(t_fdf *fdf)
{
	ft_bzero(fdf->img.addr, fdf->img.line_len * WIN_HEIGHT);
	project_all(fdf);
	draw_grid(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
	draw_hud(fdf);
}
