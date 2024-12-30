#include "../includes/FdF.h"

void ft_normalise(t_map *s_map)
{
    int i, j;
    float scale;
    int z_min, z_max;
    float z_range;
    float z_offset = 0;

    // Trouver les valeurs minimales et maximales de z
    z_min = s_map->position[0][0];
    z_max = s_map->position[0][0];

    for (i = 0; i < ft_count_line(s_map->map); i++) {
        for (j = 0; j < ft_count_colone(s_map->map); j++) {
            if (s_map->position[i][j] < z_min)
                z_min = s_map->position[i][j];
            if (s_map->position[i][j] > z_max)
                z_max = s_map->position[i][j];
        }
    }

    // Si la plage est négative, on applique un décalage pour rendre toutes les valeurs positives
    if (z_min < 0) {
        z_offset = -z_min; // Décalage pour rendre z_min positif
    }
    
    // Appliquer le décalage à toutes les valeurs de z
    for (i = 0; i < ft_count_line(s_map->map); i++) {
        for (j = 0; j < ft_count_colone(s_map->map); j++) {
            s_map->position[i][j] += z_offset;
        }
    }

    // Recalculer les valeurs minimales et maximales après le décalage
    z_min = s_map->position[0][0];
    z_max = s_map->position[0][0];

    for (i = 0; i < ft_count_line(s_map->map); i++) {
        for (j = 0; j < ft_count_colone(s_map->map); j++) {
            if (s_map->position[i][j] < z_min)
                z_min = s_map->position[i][j];
            if (s_map->position[i][j] > z_max)
                z_max = s_map->position[i][j];
        }
    }

    // Calculer la plage après décalage
    z_range = (float)(z_max - z_min);

    if (z_range == 0) {
        scale = 1.0f; // Si toute la plage est identique, on applique un scale arbitraire
    } else {
        scale = 2.0f / z_range; // Modifier cette échelle si nécessaire pour rendre la carte plus visible
    }

    // Normaliser et appliquer l'échelle à chaque valeur de z
    for (i = 0; i < ft_count_line(s_map->map); i++) {
        for (j = 0; j < ft_count_colone(s_map->map); j++) {
            s_map->position[i][j] = (s_map->position[i][j] - z_min) * scale;
        }
    }
}
