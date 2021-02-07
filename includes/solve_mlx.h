#ifndef SOLVE_MLX_H
# define SOLVE_MLX_H

typedef struct	s_limits
{
	int			x;
	int 		y;
}				t_limits;

typedef struct	s_dots
{
	t_vec 		d_c;
}				t_dots;

typedef struct	s_matrix
{
	t_vec 		*vec;
}				t_matrix;

void			rtx(t_rt *scene);
void			begin_mlx_work(t_rt *scene);
t_vp			*alloc_viewport(t_rt *scene);

void			matrix_rellocation(t_matrix *location, t_rt *scene, int c);

int 			check_max_cams(t_rt *scene);


#endif