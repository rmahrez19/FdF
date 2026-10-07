/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(char **words)
{
	int	count;

	count = 0;
	while (words[count])
		count++;
	return (count);
}

int	parse_hex(const char *str)
{
	int	result;

	result = 0;
	while (*str && ft_strchr(HEX_DIGITS, ft_tolower(*str)))
	{
		result = result * 16 + (ft_strchr(HEX_DIGITS, ft_tolower(*str))
				- HEX_DIGITS);
		str++;
	}
	return (result);
}

static bool	is_valid_color(const char *str)
{
	if (str[0] != ',' || str[1] != '0' || (str[2] != 'x' && str[2] != 'X'))
		return (false);
	str += 3;
	if (!*str)
		return (false);
	while (*str && ft_strchr(HEX_DIGITS, ft_tolower(*str)))
		str++;
	return (*str == '\0');
}

bool	is_valid_point(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (false);
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (true);
	return (is_valid_color(str));
}
