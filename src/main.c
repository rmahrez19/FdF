/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:14:38 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/15 16:55:26 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	main(int ac, char **av)
{
	t_all	s_all;

	(void)ac;
	ft_read_map(av[1], &s_all.map);
	s_all.map.res = ft_split(s_all.map.map, '\n');
	ft_init(&s_all);
	ft_alloc(&s_all.map.position_z, s_all);
	if (s_all.map.map)
		ft_alloc((float ***)&s_all.map.color, s_all);
	ft_pars(&s_all.map);
	draw_map(&s_all);
	ft_free();
	return (0);
}
