/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:50:19 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/15 16:26:38 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	draw_pixel(t_data data, int x, int y)
{
	int	i;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		i = (y * data.size_line) + (x * (data.bpp / 8));
		*(unsigned int *)(data.img_data + i) = 0xffffff;
	}
}

void	ft_insigne(t_d *s_d, t_point *point, int *err)
{
	s_d->dx = abs(point->x_end - point->x_start);
	s_d->dy = abs(point->y_end - point->y_start);
	if (point->x_start < point->x_end)
		s_d->sx = 1;
	else
		s_d->sx = -1;
	if (point->y_start < point->y_end)
		s_d->sy = 1;
	else
		s_d->sy = -1;
	*err = s_d->dx - s_d->dy;
}

void	draw_line(t_data data, t_point *point)
{
	t_d	s_d;
	int	err;
	int	e2;
	int	tab[2];

	ft_insigne(&s_d, point, &err);
	tab[0] = point->x_start;
	tab[1] = point->y_start;
	while (1)
	{
		draw_pixel(data, tab[0], tab[1]);
		if (tab[0] == point->x_end && tab[1] == point->y_end)
			break ;
		e2 = 2 * err;
		if (e2 > -s_d.dy)
		{
			err -= s_d.dy;
			tab[0] += s_d.sx;
		}
		if (e2 < s_d.dx)
		{
			err += s_d.dx;
			tab[1] += s_d.sy;
		}
	}
}

void	ft_loop_project(t_all *s_all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < s_all->point.y_line)
	{
		while (i < s_all->point.x_line)
		{
			project(i, j, s_all);
			i++;
		}
		s_all->point.x_start = 0;
		s_all->point.y_start = 0;
		i = 0;
		j++;
	}
}

int	draw_map(t_all *s_all)
{
	init_window(s_all);
	s_all->data.img_ptr = mlx_new_image(s_all->data.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	s_all->data.img_data = mlx_get_data_addr(s_all->data.img_ptr,
			&s_all->data.bpp, &s_all->data.size_line, &s_all->data.endian);
	if (!s_all->data.img_data)
		error();
	ft_loop_project(s_all);
	mlx_put_image_to_window(s_all->data.mlx_ptr,
		s_all->data.win_ptr, s_all->data.img_ptr, 0, 0);
	ft_displaystr(*s_all);
	mlx_key_hook(s_all->data.win_ptr, key_press, s_all);
	mlx_loop(s_all->data.mlx_ptr);
	return (0);
}
