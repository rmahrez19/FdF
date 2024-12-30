/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:11:21 by ramahrez          #+#    #+#             */
/*   Updated: 2024/12/29 18:34:30 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	main(int ac, char **av)
{
	t_map	s_map;

	(void)ac;
	ft_read_map(av[1], &s_map);
	s_map.res = ft_split(s_map.map, '\n');
	int fd = open("map/test.fdf", O_RDONLY);
	printf("%s", get_next_line(fd));
	ft_alloc(&s_map.position, s_map.map);
	ft_ordinate(&s_map);
	// ft_normalise(&s_map);
	draw_map(s_map);
	ft_free();
}
