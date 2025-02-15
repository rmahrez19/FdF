/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:08:21 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/11 18:41:17 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	pars_hexa(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

void	ft_ordinate_hexa(t_map *s_map, t_pars s_pars)
{	
	while (s_map->map[s_pars.i])
	{
		while (s_map->map[s_pars.i] != '\n' && s_map->map[s_pars.i] != 0)
		{
			while (s_map->map[s_pars.i] == ' ')
				s_pars.i++;
			s_map->position_z[s_pars.j][s_pars.count] = ft_atoi(s_map->map + s_pars.i);
			while (s_map->map[s_pars.i] != ',' && s_map->map[s_pars.i] != 0
				&& s_map->map[s_pars.i] != '\n')
				s_pars.i++;
			if (s_map->map[s_pars.i] == ',')
			{
				s_pars.i++;
				s_map->color[s_pars.j][s_pars.count] = ft_atoi_base(s_map->map + s_pars.i + 3, hexa);
			}	
			s_pars.count++;
			while (s_map->map[s_pars.i] != ' ' && s_map->map[s_pars.i] != 0
				&& s_map->map[s_pars.i] != '\n')
					s_pars.i++;
		}
		if(s_map->map[s_pars.i])
			s_pars.i++;
		s_pars.j++;
		s_pars.count = 0;
	}
}

void	ft_ordinate(t_map *s_map, t_pars s_pars)
{		
		while(s_map->map[s_pars.i])
		{
			while(s_map->map[s_pars.i] != '\n' && s_map->map[s_pars.i] != 0)
			{
				while(s_map->map[s_pars.i] == ' ')
					s_pars.i++;
				s_map->position_z[s_pars.j][s_pars.count] = ft_atoi(s_map->map + s_pars.i);
				s_pars.count++;
				while(s_map->map[s_pars.i] != ' ' && s_map->map[s_pars.i] != 0 && s_map->map[s_pars.i] != '\n')
						s_pars.i++;
			}
			if(s_map->map[s_pars.i])
				s_pars.i++;
			s_pars.j++;
			s_pars.count = 0;
		}
}


void ft_pars(t_map *s_map)
{
	t_pars s_pars;

	s_pars.i = 0;
	s_pars.j = 0;
	s_pars.count = 0;
	if(pars_hexa(s_map->map))
	{
		printf("hexa\n");
		ft_ordinate_hexa(s_map, s_pars);
	}
	else
	{
		printf("non hexa\n");
		ft_ordinate(s_map, s_pars);
	}
}
