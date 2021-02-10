#ifndef SOLVE_MLX_H
# define SOLVE_MLX_H

typedef struct	s_limits
{
	int			x;
	int 		y;
}				t_limits;

typedef struct	s_matrix
{
	t_vec 		*first;
	t_vec		*second;
	t_vec		*third;
}				t_matrix;

typedef struct	s_cos_sin
{
	double 		sin_c;
	double 		cos_c;
}				t_cos_sin;

void			rtx(t_rt *scene);
void			begin_mlx_work(t_rt *scene);
t_vp			*alloc_viewport(t_rt *scene);

void			matrix_rellocation(t_rt *scene, int c);
t_vec *firs_dot_angles_to_coordinate(t_rt *scene, t_cam *cam);


int 			check_max_cams(t_rt *scene);
double 			degress_to_radians(double degrees);
double 			radians_to_degrees(double radians);
t_cos_sin *alloc_init_cos_sin(t_rt *scene, double degrees);

void 			get_angles_to_data(t_rt *scene, t_cam *cam);

void 			init_dots(t_rt *scene);
void init_matrix_z(t_rt *scene, t_matrix *mat, t_cos_sin *cs);
void init_matrix_y(t_rt *scene, t_matrix *mat, t_cos_sin *cs);
void alloc_matrix_vecs(t_matrix *matrix, t_rt *scene);
t_vec *rotate_osy(t_rt *scene, t_cam *cam, double angle, t_matrix *matrix);
void 			matrix_use_vec(t_matrix *mat, t_vec **vec);



t_figures 		*cp_scene(t_rt* scene);
void			alloc_figures(t_rt *scene, t_figures *fig);
void 			alloc_cylinder_fig(t_rt *scene, t_figures *fig);






#endif