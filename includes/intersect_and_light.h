#ifndef INTERSECT_AND_LIGHT_H
# define INTERSECT_AND_LIGHT_H

int intersect(t_vec *vec, t_rt *scene);
double intersect_sphere(t_vec *ray, t_sp *sp, t_rt *scene, t_vec *start);
double			intersect_plane(t_vec *vec, t_pl *pl, t_rt *scene, t_vec
*start);
double			intersect_square(t_vec *vec, t_sq *sq, t_rt *scene, t_vec
*start);
double			intersect_triangle(t_vec *vec, t_tr *tr, t_rt *sc, t_vec
*start);

t_vec color_light_branching(t_dist args, t_rt *scene, t_vec *vec);
t_vec	take_normal_from_obj(t_dist args, t_rt *scene, t_vec *tmp, t_vec *vec);
t_vec	take_light_to_color(t_light *l, t_vec *tmp, t_rt *scene, t_dist args);
t_vec	triangle_light_br(t_dist args, t_rt *scene, t_vec *vec, t_vec color[2]);






t_dist comparison_spheres(t_vec *vec, t_rt *scene, t_vec *start);
t_dist comparison_planes(t_vec *vec, t_rt *scene, t_vec *start);
t_dist comparison_squares(t_vec *vec, t_rt *scene, t_vec *start);
t_dist comparison_cylinder(t_vec *vec, t_rt *scene, t_vec *start);
t_dist comparison_triangle(t_vec *vec, t_rt *scene, t_vec *start);

t_vec *sum_colors(t_vec *col1, t_vec *col2);
void	check_overcolor(t_vec* tmp);
int 	vec_to_int_color(t_vec color, int flag_del);

t_vec vec_to_light(t_vec *color, t_rt *scene, t_vec *vec, t_dist args);

t_dist check_len_figures(t_vec *vec, t_rt *scene, t_vec *start);

typedef struct	s_triangle
{
	t_vec		*mal[2];
	t_vec		*p[3];
	t_vec		*start;
}				t_triangle;





#endif
