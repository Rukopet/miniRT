#ifndef INTERSECT_AND_LIGHT_H
# define INTERSECT_AND_LIGHT_H

int intersect(t_vec *vec, t_rt *scene);
double intersect_sphere(t_vec *vec, t_sp *sp, t_rt *scene, t_vec *start);

t_vec * color_light_branching(t_dist args, t_rt *scene, t_vec *vec);


t_dist comparison_spheres(t_vec *vec, t_rt *scene, t_vec *start);
t_dist comparison_planes(t_vec *vec, t_rt *scene, t_vec *start);
t_dist comparison_squares(t_vec *vec, t_rt *scene, t_vec *start);
t_dist comparison_cylinder(t_vec *vec, t_rt *scene, t_vec *start);
t_dist comparison_triangle(t_vec *vec, t_rt *scene, t_vec *start);

t_vec *sum_colors(t_vec *col1, t_vec *col2);
void	check_overcolor(t_vec* tmp);
int 	vec_to_int_color(t_vec *color, int flag_del);
void vec_to_light(t_vec **color, t_rt *scene, t_vec *vec, t_dist args);
t_dist check_len_figures(t_vec *vec, t_rt *scene, t_vec *start);







#endif
