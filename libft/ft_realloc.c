/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:55:08 by ramahrez          #+#    #+#             */
/*   Updated: 2024/11/29 13:56:56 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_realloc(void *old, int old_size, int new_size, int data_size)
{
    void *ptr;

    // Alloue le nouveau bloc de mémoire
    ptr = malloc(new_size * data_size);
    if (!ptr)
        return (NULL);

    // Copie les anciennes données (jusqu'à la taille minimale)
    if (old)
        ft_memcpy(ptr, old, (old_size < new_size ? old_size : new_size) * data_size);

    // Initialise le reste à 0 si le nouveau bloc est plus grand
    if (new_size > old_size)
        ft_bzero((char*)ptr + old_size * data_size, (new_size - old_size) * data_size);

    // Libère l'ancien bloc
    free(old);

    return (ptr);
}
