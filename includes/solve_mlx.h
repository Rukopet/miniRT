#ifndef SOLVE_MLX_H
# define SOLVE_MLX_H

typedef struct	s_limits
{
	int			x;
	int 		y;
}				t_limits;

void			rtx(t_rt *scene);
void			begin_mlx_work(t_rt *scene);
t_vp			*alloc_viewport(t_rt *scene);


#endif
