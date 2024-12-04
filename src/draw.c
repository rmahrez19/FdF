#include "mlx.h"
#include "../includes/FdF.h"

void draw_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int color) {
    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
}


// Algorithme de tracé de ligne de Bresenham
void draw_line(void *mlx_ptr, void *win_ptr, int x_start, int y_start, int x_end, int y_end, int color) {
    int dx = abs(x_end - x_start);
    int dy = abs(y_end - y_start);
    int sx = (x_start < x_end) ? 1 : -1;
    int sy = (y_start < y_end) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        draw_pixel(mlx_ptr, win_ptr, x_start, y_start, color);
        if (x_start == x_end && y_start == y_end)
            break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x_start += sx;
        }
        if (e2 < dx) {
            err += dx;
            y_start += sy;
        }
    }
}


// Fonction de projection isométrique
void project_isometric(int x, int y, int z, t_point *point, void *mlx_ptr, void *win_ptr, int color, int zoom)
 {
    float angle = M_PI  / 6; // 30 degrés
    int offset_x = WINDOW_WIDTH / 2;
    int offset_y = WINDOW_HEIGHT / 2;

    // Calcul des coordonnées projetées
    int x_proj = (x - y) * cos(angle) * zoom + offset_x;
    int y_proj = (x + y) * sin(angle) * zoom - z * zoom + offset_y;

    // Tracer une ligne entre le dernier point projeté et le nouveau
    

    if (point->temp_x_proj != 0 || point->temp_y_proj != 0)
        draw_line(mlx_ptr, win_ptr, point->temp_x_proj, point->temp_y_proj, x_proj, y_proj, color);

    point->temp_x_proj = x_proj;
    point->temp_y_proj = y_proj;
	// point->temp_x = x;
	// point->temp_y = y;
}

void ft_project_isometric(int x, int y, int z, t_point *point, void *mlx_ptr, void *win_ptr, int color, int zoom)
 {
    float angle = M_PI  / 6; // 30 degrés
    int offset_x = WINDOW_WIDTH / 2;
    int offset_y = WINDOW_HEIGHT / 2;

    // Calcul des coordonnées projetées
    int x_proj = (x - y) * cos(angle) * zoom + offset_x;
    int y_proj = (x + y) * sin(angle) * zoom - z * zoom + offset_y;

    // Tracer une ligne entre le dernier point projeté et le nouveau
    

    if (point->temp_x_proj != 0 || point->temp_y_proj != 0)
        draw_line(mlx_ptr, win_ptr, point->temp_x_proj, point->temp_y_proj, x_proj, y_proj, color);

	// point->temp_x = x;
	// point->temp_y = y;
}

int draw_map(t_map s_map)
{
    t_data  data;
	t_point s_point;
	int zoom = 20;
	int i;
	int j;

	i = 0;
	j = 0;

    // Initialisation de MiniLibX
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Tracer une ligne");
    if (!data.win_ptr)
    {
        free(data.mlx_ptr);
        return (1);
    }

	while(j < ft_count_line(s_map.map))
	{
		while(i < ft_count_colone(s_map.map))
		{
			if(i < ft_count_colone(s_map.map) && !(i == 0 && j == 0))
			project_isometric(i + 1, j + 1, s_map.position[j][i], &s_point, data.mlx_ptr, data.win_ptr, 0x00FF00, zoom);
			if(j + 1 < ft_count_line(s_map.map))
				ft_project_isometric(i + 1, j + 2, s_map.position[j + 1][i], &s_point, data.mlx_ptr, data.win_ptr, 0x00ff00, zoom);
			i++;
		}
		s_point.temp_x_proj = 0;
    	s_point.temp_y_proj = 0;
		i = 0;
		j++;
	}


    mlx_loop(data.mlx_ptr);

    return (0);
}


