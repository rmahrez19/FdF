/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	alloc_grids(t_map *map)
{
	int	y;

	map->alt = ft_malloc(sizeof(int *) * map->height);
	map->color = ft_malloc(sizeof(int *) * map->height);
	map->proj = ft_malloc(sizeof(t_pixel *) * map->height);
	if (!map->alt || !map->color || !map->proj)
		fatal("out of memory");
	y = -1;
	while (++y < map->height)
	{
		map->alt[y] = ft_malloc(sizeof(int) * map->width);
		map->color[y] = ft_malloc(sizeof(int) * map->width);
		map->proj[y] = ft_malloc(sizeof(t_pixel) * map->width);
		if (!map->alt[y] || !map->color[y] || !map->proj[y])
			fatal("out of memory");
	}
}

static void	parse_row(t_map *map, char *row, int y)
{
	char	**points;
	char	*comma;
	int		x;

	points = ft_split(row, ' ');
	if (!points)
		fatal("out of memory");
	if (count_words(points) != map->width)
		fatal("invalid map: rows do not have the same length");
	x = -1;
	while (++x < map->width)
	{
		if (!is_valid_point(points[x]))
			fatal("invalid map: unexpected value");
		map->alt[y][x] = ft_atoi(points[x]);
		map->color[y][x] = DEFAULT_COLOR;
		comma = ft_strchr(points[x], ',');
		if (comma)
			map->color[y][x] = parse_hex(comma + 3);
	}
}

static void	compute_alt_range(t_map *map)
{
	int	x;
	int	y;

	map->alt_min = map->alt[0][0];
	map->alt_max = map->alt[0][0];
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->alt[y][x] < map->alt_min)
				map->alt_min = map->alt[y][x];
			if (map->alt[y][x] > map->alt_max)
				map->alt_max = map->alt[y][x];
		}
	}
}

void	load_map(const char *path, t_map *map)
{
	char	*content;
	char	**rows;
	char	**first;
	int		y;

	content = read_file(path);
	rows = ft_split(content, '\n');
	free(content);
	if (!rows)
		fatal("out of memory");
	map->height = count_words(rows);
	if (map->height == 0)
		fatal("the map is empty");
	first = ft_split(rows[0], ' ');
	if (!first)
		fatal("out of memory");
	map->width = count_words(first);
	if (map->width == 0)
		fatal("the map is empty");
	alloc_grids(map);
	y = -1;
	while (++y < map->height)
		parse_row(map, rows[y], y);
	compute_alt_range(map);
}
