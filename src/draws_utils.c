/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:08:26 by ramahrez          #+#    #+#             */
/*   Updated: 2024/12/30 01:08:51 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"


void project_isometric(int x, int y, int z, t_point *point, void *mlx_ptr, void *win_ptr)
 {
    float angle = M_PI  / 4; // 30 degrés
    int offset_x = WINDOW_WIDTH / 2;
    int offset_y = WINDOW_HEIGHT / 2;
	float zoom = 4;

    // Calcul des coordonnées projetées
	point->x_end = (x - y) * cos(angle) * zoom + offset_x;
    point->y_end = (x + y) * sin(angle) * zoom - z * zoom + offset_y;

    // Tracer une ligne entre le dernier point projeté et le nouveau
    if (point->x_start != 0 || point->y_start != 0)
	{
        draw_line(mlx_ptr, win_ptr, point);
	}
	point->x_start = point->x_end;
	point->y_start = point->y_end;
	point->x_end = 0;
	point->y_end = 0;
}

void ft_project_isometric(int x, int y, int z, t_point *point, void *mlx_ptr, void *win_ptr)
{
    float angle = M_PI  / 4; // 30 degrés
    int offset_x = WINDOW_WIDTH / 2;
    int offset_y = WINDOW_HEIGHT / 2;
	float zoom = 4;
    // Calcul des coordonnées projetées
	point->x_end = (x - y) * cos(angle) * zoom + offset_x;
    point->y_end = (x + y) * sin(angle) * zoom - z * zoom + offset_y;

    // Tracer une ligne entre le dernier point projeté et le nouveau
    

    if (point->x_start != 0 || point->y_start != 0)
	{   
	    draw_line(mlx_ptr, win_ptr, point);
	}
	point->x_end = 0;
	point->y_end = 0;
}