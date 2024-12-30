#ifndef INCLUDES_H
#define INCLUDES_H

typedef struct s_map
{
	char	*map;
	int		**derivate;
	float		**position;
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
	
}t_point;

typedef struct s_data {
    void    *mlx_ptr;
    void    *win_ptr;
} t_data;


#endif