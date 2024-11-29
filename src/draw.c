#include "mlx.h"
#include "../includes/FdF.h"

void    draw_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
}

void project_isometric(int x, int y, int z, void *mlx_ptr, void *win_ptr, int color) 
{

	int x_proj;
    int y_proj;
    float angle;
    int zoom = 20;
    int offset_x = 400;  // Centrage horizontal pour une fenêtre de 800px de large
    int offset_y = 300;  // Centrage vertical pour une fenêtre de 600px de hauteur

    angle = M_PI / 6; // 30 degrés
    // Calcul des coordonnées projetées (sans zoom)
    x_proj = (x - y) * cos(angle);
    y_proj = (x + y) * sin(angle) - z;

    // Appliquer le zoom en multipliant les coordonnées projetées par le facteur de zoom
    x_proj = x_proj * zoom;
    y_proj = y_proj * zoom;

    // Centrer les coordonnées projetées sur l'écran
    x_proj += offset_x;
    y_proj += offset_y;

    // Dessiner le pixel avec MiniLibX
    mlx_pixel_put(mlx_ptr, win_ptr, x_proj, y_proj, color);

}


// Algorithme de Bresenham pour tracer une ligne entre deux points
// void    draw_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color)
// {
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx;
//     int sy;
//     int err;
//     int e2;void *mlx_ptr, void *win_ptr

//     if (x0 < x1)
//         sx = 1;
//     else
//         sx = -1;

//     if (y0 < y1)
//         sy = 1;
//     else
//         sy = -1;

//     err = dx - dy;

//     while (1)
//     {
//         draw_pixel(mlx_ptr, win_ptr, x0, y0, color);
//         if (x0 == x1 && y0 == y1)
//             break;
//         e2 = 2 * err;
//         if (e2 > -dy)
//         {
//             err -= dy;
//             x0 += sx;
//         }
//         if (e2 < dx)
//         {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }






// void    draw_square(void *mlx_ptr, void *win_ptr, int x0, int y0, int color)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;

// 	while (i < 50)
// 	{
// 		draw_pixel(mlx_ptr, win_ptr, x0 + i, y0, color);
// 		i++;
// 	}
// 	x0 += i;
// 	i = 0;
// 	while (i < 50)
// 	{
// 		draw_pixel(mlx_ptr, win_ptr, x0, y0 + i, color);
// 		i++;
// 	}
// 	y0 += i;
// 	i = 0;
// 	while (i < 50)
// 	{
// 		draw_pixel(mlx_ptr, win_ptr, x0 - i, y0, color);
// 		i++;
// 	}
// 	x0 -= i;
// 	i = 0;
// 	while (i < 50)
// 	{
// 		draw_pixel(mlx_ptr, win_ptr, x0, y0 - i, color);
// 		i++;
// 	}
// }

int draw_map(t_map s_map)
{
    t_data  data;
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

    // Tracer une ligne entre deux points (x0, y0) et (x1, y1)
	while(j < ft_count(s_map.map))
	{

		project_isometric(s_map.position[j][0], s_map.position[j][1], s_map.position[j][2], data.mlx_ptr, data.win_ptr, 0x00FF00);
		j++;
	}

    // Lancement de la boucle d'événements
	
    mlx_loop(data.mlx_ptr);

    return (0);
}