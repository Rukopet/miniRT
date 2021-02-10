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

void			matrix_rellocation(t_rt *scene, int c);
t_vec			*firs_dot_angles_to_coordinate(t_rt *scene, t_cam *cam);


int 			check_max_cams(t_rt *scene);
double 			degress_to_radians(double degrees);
double 			radians_to_degrees(double radians);

void 			get_angles_to_data(t_rt *scene, t_cam *cam);

void 			init_dots(t_rt *scene);

t_figures 		*cp_scene(t_rt* scene);
void			alloc_figures(t_rt *scene, t_figures *fig);
void 			alloc_cylinder_fig(t_rt *scene, t_figures *fig);






#endif