/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:44:37 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/15 15:59:49 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void project_isometric(int x, int y, int z, t_all *s_all)
 {
	 int offset_x = (WINDOW_WIDTH / 2);
    int offset_y = (WINDOW_HEIGHT / 2);

	// apply_rotation(&x, &y, &z, s_all);

	// offset_x += s_all->point.x;
	// offset_y += s_all->point.y;

	s_all->point.x_end = (x - y) * cos(s_all->point.angle) * s_all->point.zoom + offset_x;
    s_all->point.y_end = (x + y) * sin(s_all->point.angle) * s_all->point.zoom - z * s_all->point.zoom + offset_y;

    if (s_all->point.x_start != 0 || s_all->point.y_start != 0)
	{
        draw_line(s_all->data, &s_all->point);
		// draw_pixel(s_all->data, s_all->point.x_end, s_all->point.y_end);
	}
	s_all->point.x_start = s_all->point.x_end;
	s_all->point.y_start = s_all->point.y_end;
	s_all->point.x_end = 0;
	// s_all->point.y_end = 0;
}

void ft_project_isometric(int x, int y, int z, t_all *s_all)
{
	int offset_x = (WINDOW_WIDTH / 2);
    int offset_y = (WINDOW_HEIGHT / 2);
    // Calcul des coordonnées projetées

	// // apply_rotation(&x, &y, &z, s_all);
	// offset_x += s_all->point.x;
	// offset_y += s_all->point.y;

	s_all->point.x_end = (x - y) * cos(s_all->point.angle) * s_all->point.zoom + offset_x;
    s_all->point.y_end = (x + y) * sin(s_all->point.angle) * s_all->point.zoom - z * s_all->point.zoom + offset_y;

    if (s_all->point.x_start != 0 || s_all->point.y_start != 0)
	{
        draw_line(s_all->data, &s_all->point);
		// draw_pixel(s_all->data, s_all->point.x_end, s_all->point.y_end);
	}
	s_all->point.x_end = 0;
	s_all->point.y_end = 0;
}



void	project(int	i, int	j, t_all *s_all)
{
	s_all->data.color = 0xffffff;
	if (i + 1 <= s_all->point.x_line && !(i == 0))
	{
		project_isometric(i + 1, j + 1,
			s_all->map.position_z[j][i], s_all);
	}
	if (j + 1 < s_all->point.y_line)
	{
		ft_project_isometric(i + 1, j + 2,
			s_all->map.position_z[j + 1][i], s_all);
	}
}