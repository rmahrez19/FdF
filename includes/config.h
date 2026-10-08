/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define WIN_WIDTH		1920
# define WIN_HEIGHT		1080
# define WIN_TITLE		"FdF"

# define DEFAULT_COLOR	0xFFFFFF
# define HEX_DIGITS		"0123456789abcdef"
# define HUD_COLOR		0xA0A0A0
# define FIT_RATIO		0.8

/* Vitesses appliquees a chaque image tant qu'une touche est maintenue */
# define ROT_STEP		0.02
# define MOVE_STEP		8
# define ZOOM_STEP		1.02
# define MIN_ZOOM		0.5
# define Z_STEP			1.02

#endif
