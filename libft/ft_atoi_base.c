/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:15:16 by ramahrez          #+#    #+#             */
/*   Updated: 2025/01/29 19:01:45 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int ft_check(char c, char *base)
{
	int i;

	i = 0;
	while(base[i])
	{
		if(base[i] == c)
			return(i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int b;
	int base_lenght;
	long	result;

	i = 0;
	n = 1;
	result = 0;
	base_lenght = ft_strlen(base);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while(str[i] && (b = ft_check(str[i], base)) != -1)
	{
		result = result * base_lenght + b;
		i++;
	}
	return(result * n);
}

// int main(int ac, char **av)
// {
// 	printf("%d", ft_atoi_base(av[1], av[2]));
// }