/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:08:21 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/16 17:00:23 by ramahrez         ###   ########.fr       */
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

int	parse_color(char *str)
{
	int	result;

	result = 0;
	while (*str && (ft_strchr(HEXA_LOW, *str) || ft_strchr(HEXA_UP, *str)))
	{
		if (ft_strchr(HEXA_LOW, *str))
			result = result * 16 + (ft_strchr(HEXA_LOW, *str) - HEXA_LOW);
		else
			result = result * 16 + (ft_strchr(HEXA_UP, *str) - HEXA_UP);
		str++;
	}
	return (result);
}

void	ft_ordinate_hexa(t_map *s_map, t_pars s_pars)
{
	while (s_map->map[s_pars.i])
	{
		while (s_map->map[s_pars.i] != '\n' && s_map->map[s_pars.i] != 0)
		{
			while (s_map->map[s_pars.i] == ' ')
				s_pars.i++;
			s_map->position_z[s_pars.j][s_pars.count]
				= ft_atoi(s_map->map + s_pars.i);
			while (s_map->map[s_pars.i] != ',' && s_map->map[s_pars.i] != 0
				&& s_map->map[s_pars.i] != '\n')
				s_pars.i++;
			s_map->color[s_pars.j][s_pars.count] = DEFAULT_COLOR;
			if (s_map->map[s_pars.i] == ',')
			{
				s_pars.i++;
				s_map->color[s_pars.j][s_pars.count]
					= parse_color(s_map->map + s_pars.i + 2);
			}
			s_pars.count++;
			while (s_map->map[s_pars.i] != ' ' && s_map->map[s_pars.i] != 0
				&& s_map->map[s_pars.i] != '\n')
					s_pars.i++;
		}
		if (s_map->map[s_pars.i])
			s_pars.i++;
		s_pars.j++;
		s_pars.count = 0;
	}
}

void	ft_ordinate(t_map *s_map, t_pars s_pars)
{
	while (s_map->map[s_pars.i])
	{
		while (s_map->map[s_pars.i] != '\n' && s_map->map[s_pars.i] != 0)
		{
			while (s_map->map[s_pars.i] == ' ')
				s_pars.i++;
			s_map->position_z[s_pars.j][s_pars.count]
				= ft_atoi(s_map->map + s_pars.i);
			s_map->color[s_pars.j][s_pars.count] = DEFAULT_COLOR;
			s_pars.count++;
			while (s_map->map[s_pars.i] != ' ' && s_map->map[s_pars.i]
				!= 0 && s_map->map[s_pars.i] != '\n')
					s_pars.i++;
		}
		if (s_map->map[s_pars.i])
			s_pars.i++;
		s_pars.j++;
		s_pars.count = 0;
	}
}

void	ft_pars(t_map *s_map)
{
	t_pars	s_pars;

	s_pars.i = 0;
	s_pars.j = 0;
	s_pars.count = 0;
	if (pars_hexa(s_map->map))
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
