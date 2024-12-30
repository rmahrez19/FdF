/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:19:44 by ramahrez          #+#    #+#             */
/*   Updated: 2024/12/21 04:51:21 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	draw_pixel(void *mlx_ptr, void *win_ptr, int x, int y)
{
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00ff00);
}

void ft_insigne(t_d *s_d, t_point *point, int *err)
{
	s_d->dx = abs(point->x_end - point->x_start);
	s_d->dy = abs(point->y_end - point->y_start);
	if(point->x_start < point->x_end)
		s_d->sx = 1;
	else
		s_d->sx = -1;
	if(point->y_start < point->y_end)
		s_d->sy = 1;
	else
		s_d->sy = -1; 
    *err = s_d->dx - s_d->dy;
}

void draw_line(void *mlx_ptr, void *win_ptr, t_point *point)
{
	t_d	s_d;
	int err;
	int e2;
	int tab[2];

	ft_insigne(&s_d, point, &err);
	tab[0] = point->x_start;
	tab[1] = point->y_start;
    while (1)
	{
        draw_pixel(mlx_ptr, win_ptr, tab[0], tab[1]);
        if (tab[0] == point->x_end && tab[1] == point->y_end)
            break;
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

void ft_loop_project(t_map s_map, t_data data, t_point s_point)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(j < ft_count_line(s_map.map))
	{
		while(i < ft_count_colone(s_map.map))
		{
			if(i + 1<= ft_count_colone(s_map.map) && !(i == 0))
				project_isometric(((i + 1) * 1), ((j + 1) * 1), s_map.position[j][i], &s_point, data.mlx_ptr, data.win_ptr);
			if(j + 1 < ft_count_line(s_map.map))
				ft_project_isometric(((i + 1) * 1), ((j + 2) * 1), s_map.position[j + 1][i], &s_point, data.mlx_ptr, data.win_ptr);
			i++;
		}
		s_point.x_start = 0;
    	s_point.y_start = 0;
		i = 0;
		j++;
	}
}



int draw_map(t_map s_map)
{
    t_data  data;
	t_point s_point;
	int i;
	int j;

	i = 0;
	j = 0;
	s_point.x_end = 0;
    s_point.y_end = 0;
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Tracer une ligne");
    if (!data.win_ptr)
    {
        free(data.mlx_ptr);
        return (1);
    }
	ft_loop_project(s_map, data, s_point);
	mlx_key_hook(data.win_ptr, key_press, NULL);
    mlx_loop(data.mlx_ptr);
    return (0);
}
