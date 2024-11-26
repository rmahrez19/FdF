/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_aloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:55:08 by ramahrez          #+#    #+#             */
/*   Updated: 2024/11/26 22:04:55 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_realloc(void *old, int old_size, int new_size, int data_size)
{
	void *ptr;
	
	ptr = malloc(new_size * data_size);
	if(!ptr)
		return (NULL);
	ft_memcpy(ptr, old, old_size);
	ft_bzero(ptr + old_size, new_size - old_size);
	free(old);
	return (ptr);
}
