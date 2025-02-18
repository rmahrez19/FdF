#ifndef INCLUDES_H
#define INCLUDES_H


#define WINDOW_WIDTH 1980
#define WINDOW_HEIGHT 1080


#include <stdbool.h>

// touche clavier echap
#define ESC_KEY 65307
#define ESP_KEY 32
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
#define P_KEY 112
#define O_KEY 111
#define R_KEY 114
#define UP_KEY 65362
#define DOWN_KEY 65364
#define RIGHT_KEY 65363
#define LEFT_KEY 65361
#define UP_KEY 65362
#define DOWN_KEY 65364
#define TAB_KEY 65289
#define L_KEY 108
#define I_KEY 105
#define K_KEY 107
#define T_KEY 116
#define G_KEY 103


// regles a afficher
#define rules_a "w :monter en haut"
#define rules_b "s : allez en bas"
#define rules_c "d :allez a gauche"
#define rules_d "a : allez a droite"

#define n = 10

#ifndef M_PI
#define M_PI
#endif


typedef struct s_pars
{
	size_t	i;
	size_t	j;
	size_t	count;
}t_pars;

typedef struct s_map
{
	char	*map;
	int		**derivate;
	float		**position_z;
	int **color;
	char 	**res;
}t_map;

typedef struct s_d
{
	int dx;
	int dy;
	int sx;
	int sy;
}t_d;

typedef struct s_point
{
	int x_start;
	int y_start;
	int x_end;
	int y_end;
	float zoom;
	float angle;
	int x;
	int y;
	int x_line;
	int y_line;
	float x_rot;
	float y_rot;
	float z_rot;
	int up;
}t_point;


typedef struct s_data {
    void    *mlx_ptr;
    void    *win_ptr;
	void    *img_ptr;
    char    *img_data;
    int     bpp;
    int     size_line;
    int     endian;
	int color;
} t_data;

typedef struct s_all
{
    t_point point;
    t_map   map;
    t_data  data;
} t_all;

typedef struct s_rot
{
	float angle_x;
	float angle_y;
	float angle_z;
	float x_tmp;
	float y_tmp;
	float z_tmp;
	float x_rot;
	float y_rot;
	float z_rot;

}	t_rot;

#endif