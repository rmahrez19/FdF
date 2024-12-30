/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:26:10 by ramahrez          #+#    #+#             */
/*   Updated: 2024/12/29 18:27:34 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

char	*read_alloc_fd(int fd, int *error)
{
	char *str;
	char buffer[1024];
	int size;
	int nread;
	int i;

	str = NULL;
	size = 0;
	nread = 1024;
	while (nread != 0)
	{
		i = size;
		nread = read(fd, buffer, 1024);
		if (nread < 0)
		{
			free(str);
			*error = 1;
			return (NULL);
		}
		size += nread;
		str = ft_realloc(str, i, size + 1, 1);
		if (!str)
		{
			*error = 2;
			return (NULL);
		}
		if(nread != 0)
		{
			while (i < size)
			{
				str[i] = buffer[i % nread];
				i++;
			}
		}
	}
	str[i] = 0;
	return (str);
}
