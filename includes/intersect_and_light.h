#ifndef INTERSECT_AND_LIGHT_H
# define INTERSECT_AND_LIGHT_H

int intersect(t_vec *vec, t_rt *scene);
double intersect_sphere(t_vec *vec, t_sp *sp, t_rt *scene);

t_dist comparison_spheres(t_vec *vec, t_rt *scene);
t_dist comparison_planes(t_vec *vec,  t_rt *scene);
t_dist comparison_squares(t_vec *vec,  t_rt *scene);
t_dist comparison_cylinder(t_vec *vec,  t_rt *scene);
t_dist comparison_triangle(t_vec *vec,  t_rt *scene);



#endif INTERSECT_AND_LIGHT_H
