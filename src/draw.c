#include "mlx.h"
#include "../includes/FdF.h"

void draw_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int color) {
    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
}

int ft_count_line(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\n' && str[i] != 0)
	{
		i++;
	}
	return (i);
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
void project_isometric(int x, int y, int z, t_point *point, void *mlx_ptr, void *win_ptr, int color) {
    float angle = M_PI  / 6; // 30 degrés
    int zoom = 20;
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
	point->temp_x = x;
	point->temp_y = y;
}

// Fonction principale de dessin
// int draw_map(t_map s_map) {
//     t_data  data;
//     t_point point;
//     int j;

//     // Initialisation des coordonnées temporaires
//     point.temp_x = 0;
//     point.temp_y = 0;

//     // Initialisation de MiniLibX
//     data.mlx_ptr = mlx_init();
//     if (!data.mlx_ptr)
//         return (1);
//     data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
//     if (!data.win_ptr) {
//         free(data.mlx_ptr);
//         return (1);
//     }

//     // Parcourir la matrice pour dessiner chaque point
//     for (j = 0; s_map.position[j] != NULL; j++) {
//             project_isometric(s_map.position[j][0], s_map.position[j][1], s_map.position[j][2], &point, 
//                               data.mlx_ptr, data.win_ptr, 0x00FF00);
// 		// if((ft_count_line(s_map.map) % j) == 0)
// 		// {

// 		// }
//         // point.temp_x = 0;
//         // point.temp_y = 0;
//     }

//     // Lancement de la boucle d'événements
//     mlx_loop(data.mlx_ptr);

//     return (0);
// }


int draw_map(t_map s_map) {
    t_data  data;
    t_point point;

    // Initialisation des coordonnées temporaires
    point.temp_x = 0;
    point.temp_y = 0;

    // Initialisation de MiniLibX
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
    if (!data.win_ptr) {
        free(data.mlx_ptr);
        return (1);
    }

    // Parcourir la matrice pour dessiner chaque point
    size_t i = 0; // Index pour parcourir tous les points
    while (s_map.position[i] != NULL) {
        // Obtenir les coordonnées actuelles
        int x = s_map.position[i][0];
        int y = s_map.position[i][1];
        int z = s_map.position[i][2];

        // Projeter et tracer à partir du point actuel
        project_isometric(x, y, z, &point, data.mlx_ptr, data.win_ptr, 0x00FF00);

        // Tracer la ligne horizontale (point -> point suivant sur la même ligne)
        if ((i + 1) % ft_count_line(s_map.map) != 0 && s_map.position[i + 1] != NULL) {
            draw_line(data.mlx_ptr, data.win_ptr,
                      x, y, // Point courant
                      s_map.position[i + 1][0], s_map.position[i + 1][1], // Point suivant
                      0x00FF00);
        }

        // Tracer la ligne verticale (point -> point juste en dessous)
        if (s_map.position[i + ft_count_line(s_map.map)] != NULL) {
            draw_line(data.mlx_ptr, data.win_ptr,
                      x, y, // Point courant
                      s_map.position[i + ft_count_line(s_map.map)][0],  // Point dessous
                      s_map.position[i + ft_count_line(s_map.map)][1], 
                      0x00FF00);
        }

        i++; // Passer au point suivant
    }

    // Lancement de la boucle d'événements
    mlx_loop(data.mlx_ptr);

    return (0);
}


// Parcourir la matrice pour dessiner chaque point
// for (int i = 0; i < s_map.height; i++) { // Parcourt les lignes
    // for (int j = 0; j < s_map.width; j++) { // Parcourt les colonnes
        //Projection du point courant
        // project_isometric(s_map.position[i][j][0], s_map.position[i][j][1], s_map.position[i][j][2], 
                        //   &point, data.mlx_ptr, data.win_ptr, 0x00FF00);
// 
        //Tracer la ligne horizontale (point -> point suivant dans la ligne)
        // if (j + 1 < s_map.width) {
            // draw_line(data.mlx_ptr, data.win_ptr,
                    //   s_map.position[i][j][0], s_map.position[i][j][1],  // Point courant
                    //   s_map.position[i][j + 1][0], s_map.position[i][j + 1][1], // Point suivant
                    //   0x00FF00);
        // }
// 
        //Tracer la ligne verticale (point -> point juste en dessous)
        // if (i + 1 < s_map.height) {
            // draw_line(data.mlx_ptr, data.win_ptr,
                    //   s_map.position[i][j][0], s_map.position[i][j][1],  // Point courant
                    //   s_map.position[i + 1][j][0], s_map.position[i + 1][j][1], // Point dessous
                    //   0x00FF00);
        // }
    // }
// }
// 