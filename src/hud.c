/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_hud(t_fdf *fdf)
{
	static const char	*lines[] = {
		"Fleches / I K : rotation",
		"W A S D       : deplacer",
		"P / O         : zoom",
		"T / G         : relief",
		"TAB           : plat / sphere",
		"R             : reinitialiser",
		"ESC           : quitter",
		NULL
	};
	int					i;

	i = 0;
	while (lines[i])
	{
		mlx_string_put(fdf->mlx, fdf->win, 20, 30 + i * 20, HUD_COLOR,
			(char *)lines[i]);
		i++;
	}
}
