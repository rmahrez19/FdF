/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:54:33 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/11 19:03:55 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	key_press(int keycode, void *param)
{
	t_all *s_all = (t_all *)param;

    if(keycode == ESC_KEY)
    {
        ft_free();
		free(s_all->map.map);
		mlx_destroy_image(s_all->data.mlx_ptr, s_all->data.img_ptr);
		mlx_destroy_window(s_all->data.mlx_ptr, s_all->data.win_ptr);
        mlx_destroy_display(s_all->data.mlx_ptr);
		free(s_all->data.mlx_ptr);
		exit(0);
    }
    return(1);
}