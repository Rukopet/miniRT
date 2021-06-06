/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_normals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:22:30 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:22:47 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec			take_normal_cylinder(t_cy *cy, t_dist *args, t_vec *vec)
{
	t_vec		vn;
	t_vec		c_c[2];
	t_vec		os;
	double		m;

	c_c[0] = (t_vec){cy->x, cy->y, cy->z};
	os = (t_vec){cy->vec_x, cy->vec_y, cy->vec_z};
	norm_vec(&os);
	m = vec_scal(*vec, vec_multi(os, args->distance)) +
			vec_scal(os, vec_subt(vec[3], *c_c));
	c_c[1] = vec_multi(*vec, args->distance);
	vn = vec_subt(vec_summ(c_c[1], vec_subt(vec[3], *c_c)), vec_multi(os, m));
	norm_vec(&vn);
	return (vn);
}
