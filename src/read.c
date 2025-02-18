/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:24:30 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/15 17:49:26 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

char	*read_alloc_fd(int fd)
{
	char	*str;
	char	*buffer;
	int		size;
	int		line_len;

	ft_init_read(&str, &buffer, &size, &line_len);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		line_len = ft_strlen(buffer);
		str = ft_realloc(str, size, size + line_len + 1, 1);
		if (!str)
		{
			free(buffer);
			error();
		}
		ft_memcpy(str + size, buffer, line_len);
		size += line_len;
		free(buffer);
	}
	if (str)
		str[size] = '\0';
	return (str);
}

void	ft_read_map(char *av, t_map *s_map)
{
	int	fd;

	(void)av;
	fd = open(&av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: cannot open file\n", 2);
		exit(1);
	}
	s_map->map = read_alloc_fd(fd);
}
