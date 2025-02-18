/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:44:37 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/16 19:41:11 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	apply_rotation(float *x, float *y, float *z, t_all *s_all)
{
	t_rot	s_rot;
	if (!x || !y || !z || !s_all)
		return ;
	s_rot.angle_x = s_all->point.x_rot;
	s_rot.angle_y = s_all->point.y_rot;
	s_rot.angle_z = s_all->point.z_rot;
	// Convertir les coordonnées en float pour éviter la perte de précision
	s_rot.x_tmp = *x;
	s_rot.y_tmp = *y;
	s_rot.z_tmp = *z;

    // Rotation autour de l'axe Z
    s_rot.x_rot = s_rot.x_tmp * cos(s_rot.angle_z) - s_rot.y_tmp * sin(s_rot.angle_z);
    s_rot.y_rot = s_rot.x_tmp * sin(s_rot.angle_z) + s_rot.y_tmp * cos(s_rot.angle_z);
    s_rot.z_rot = s_rot.z_tmp;

    // Rotation autour de l'axe X
    s_rot.y_tmp = s_rot.y_rot * cos(s_rot.angle_x) - s_rot.z_rot * sin(s_rot.angle_x);
    s_rot.z_tmp = s_rot.y_rot * sin(s_rot.angle_x) + s_rot.z_rot * cos(s_rot.angle_x);
    s_rot.x_tmp = s_rot.x_rot;

    // Rotation autour de l'axe Y
    s_rot.x_rot = s_rot.x_tmp * cos(s_rot.angle_y) + s_rot.z_tmp * sin(s_rot.angle_y);
    s_rot.z_rot = -s_rot.x_tmp * sin(s_rot.angle_y) + s_rot.z_tmp * cos(s_rot.angle_y);
    s_rot.y_rot = s_rot.y_tmp;

    // Reconversion en int pour affectation
    *x = (int)roundf(s_rot.x_rot);
    *y = (int)roundf(s_rot.y_rot);
    *z = (int)roundf(s_rot.z_rot);
}

void	project_isometric(float x, float y, float z, t_all *s_all)
 {
	 int offset_x = (WINDOW_WIDTH / 2);
    int offset_y = (WINDOW_HEIGHT / 2);

    z += s_all->point.up;
	apply_rotation(&x, &y, &z, s_all);

	offset_x += s_all->point.x;
	offset_y += s_all->point.y;

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

void ft_project_isometric(float x, float y, float z, t_all *s_all)
{
	int offset_x = (WINDOW_WIDTH / 2);
    int offset_y = (WINDOW_HEIGHT / 2);
    // Calcul des coordonnées projetées

    z += s_all->point.up;
	apply_rotation(&x, &y, &z, s_all);
	offset_x += s_all->point.x;
	offset_y += s_all->point.y;

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
		project_isometric((float)i + 1, (float)j + 1,
			s_all->map.position_z[j][i], s_all);
	}
	if (j + 1 < s_all->point.y_line)
	{
		ft_project_isometric((float) i + 1,(float) j + 2,
		s_all->map.position_z[j + 1][i], s_all);
	}
}