/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:30:00 by ramahrez          #+#    #+#             */
/*   Updated: 2026/10/08 00:30:00 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	has_fdf_extension(const char *path)
{
	size_t	len;

	len = ft_strlen(path);
	return (len > 4 && ft_strncmp(path + len - 4, ".fdf", 4) == 0);
}

static void	graphics_error(t_fdf *fdf, const char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd((char *)msg, 2);
	fdf_exit(fdf, EXIT_FAILURE);
}

static void	init_graphics(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		fatal("cannot connect to the X server");
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!fdf->win)
		graphics_error(fdf, "cannot create the window");
	fdf->img.ptr = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img.ptr)
		graphics_error(fdf, "cannot create the image");
	fdf->img.addr = mlx_get_data_addr(fdf->img.ptr, &fdf->img.bpp,
			&fdf->img.line_len, &fdf->img.endian);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2 || !has_fdf_extension(argv[1]))
	{
		ft_putendl_fd("Usage: ./fdf <map.fdf>", 2);
		return (EXIT_FAILURE);
	}
	ft_bzero(&fdf, sizeof(fdf));
	load_map(argv[1], &fdf.map);
	init_graphics(&fdf);
	reset_view(&fdf);
	render(&fdf);
	mlx_hook(fdf.win, 2, 1L << 0, on_key_press, &fdf);
	mlx_hook(fdf.win, 3, 1L << 1, on_key_release, &fdf);
	mlx_hook(fdf.win, 17, 0, on_close, &fdf);
	mlx_loop_hook(fdf.mlx, on_loop, &fdf);
	mlx_loop(fdf.mlx);
	return (EXIT_SUCCESS);
}
