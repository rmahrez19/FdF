/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	normalize_spaces(char *str)
{
	while (*str)
	{
		if (*str == '\t' || *str == '\r')
			*str = ' ';
		str++;
	}
}

/* Lit tout le fichier d'un coup, en doublant le buffer quand il est plein. */
static char	*read_all(int fd, size_t *size)
{
	char	*buf;
	size_t	cap;
	ssize_t	ret;

	cap = 4096;
	*size = 0;
	buf = ft_realloc(NULL, 0, cap + 1, 1);
	ret = 1;
	while (buf && ret > 0)
	{
		if (*size == cap)
		{
			buf = ft_realloc(buf, cap + 1, cap * 2 + 1, 1);
			cap *= 2;
		}
		if (buf)
			ret = read(fd, buf + *size, cap - *size);
		if (ret > 0)
			*size += ret;
	}
	if (!buf || ret < 0)
		fatal("cannot read the map file");
	buf[*size] = '\0';
	return (buf);
}

char	*read_file(const char *path)
{
	int		fd;
	char	*content;
	size_t	size;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		fatal("cannot open the map file");
	content = read_all(fd, &size);
	close(fd);
	if (size == 0)
		fatal("the map is empty");
	normalize_spaces(content);
	return (content);
}
