/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_and_light.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:43:06 by egums             #+#    #+#             */
/*   Updated: 2021/03/15 18:46:36 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_AND_LIGHT_H
# define INTERSECT_AND_LIGHT_H

# include "minirt.h"

int				intersect(t_vec vec[2], t_rt *scene);
double			intersect_sphere(t_vec vec[2], t_sp *sp);
double			intersect_plane(t_vec vec[2], t_pl *pl);
double			intersect_square(t_vec vec[2], t_sq *sq);
double			intersect_triangle(t_vec vec[2], t_tr *tr);
t_d				intersect_cylinder(t_vec *vec, t_cy *cy);
t_vec			color_light_branching(t_dist args, t_rt *scene, t_vec *vec);
t_vec			take_normal_from_obj(t_dist args, t_rt *scene, \
		t_vec *tmp, t_vec *vec);
t_vec			take_triangle_normal(t_tr *tr, t_vec dot);
t_vec			take_normal_cylinder(t_cy *cy, t_dist *args, t_vec *vec);
t_vec			take_light_to_color(t_light *l, t_vec *tmp);
t_vec			triangle_light_br(t_dist args, t_rt *scene, \
		t_vec *vec, t_vec color[2]);
t_dist			comparison_spheres(t_vec vec[2], t_rt *scene);
t_dist			comparison_planes(t_vec vec[2], t_rt *scene);
t_dist			comparison_squares(t_vec vec[2], t_rt *scene);
t_dist			comparison_cylinder(t_vec vec[2], t_rt *scene);
t_dist			comparison_triangle(t_vec vec[2], t_rt *scene);
int				vec_to_int_color(t_vec color);

t_vec			vec_to_light(t_vec *color, t_rt *sc, \
		t_vec *vec, t_dist args);
t_dist			check_len_figures(t_vec vec[2], t_rt *scene);
void			check_resolution(t_rt *sc, void *mlx);

#endif
