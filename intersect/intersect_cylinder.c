/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:07:09 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 21:09:37 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			take_args(t_c *cyl, t_cy *cy, t_vec *vec)
{
	cyl->orient = (t_vec){cy->vec_x, cy->vec_y, cy->vec_z};
	cyl->point = (t_vec){cy->x, cy->y, cy->z};
	cyl->norm_ori = (t_vec){cy->vec_x, cy->vec_y, cy->vec_z};
	norm_vec(&cyl->norm_ori);
	cyl->vec = vec;
}

static int			check_height_cy(t_cy *cy, t_c *cyl, t_d t)
{
	t_vec			p;
	double			tmp;

	p = vec_multi((t_vec){cyl->vec->x, cyl->vec->y, cyl->vec->z}, t.d1);
	p = (t_vec){cyl->vec[1].x + p.x,
				cyl->vec[1].y + p.y,
				cyl->vec[1].z + p.z};
	tmp = vec_scal(vec_subt(p, (t_vec){cy->x, cy->y, cy->z}),
		cyl->norm_ori);
	if (tmp < 0 || tmp > cy->height)
		return (0);
	return (1);
}

static t_d			check_point(t_cy *cy, t_c *cyl, t_d t, t_dist *quad)
{
	double			tmp;
	t_vec			x;

	x = vec_subt(cyl->vec[1], cyl->point);
	if (t.d1 > t.d2)
	{
		tmp = t.d1;
		t.d1 = t.d2;
		t.d2 = tmp;
	}
	if (t.d1 < 0 || !check_height_cy(cy, cyl, t))
	{
		t.d1 = t.d2;
		t.d2 = INFINITY;
		if (t.d1 < 0 || !check_height_cy(cy, cyl, t))
			return ((t_d){INFINITY, INFINITY});
	}
	return (t);
}

static t_d			cyl_quadro_cyl(t_cy *cy, t_c *cyl, t_dist *quad)
{
	double			disc;
	double			d1;
	double			d2;
	double			tmp;

	disc = pow(cyl->b, 2) - 4 * cyl->a * cyl->c;
	if (disc < 0)
		return ((t_d){INFINITY, INFINITY});
	if (disc == 0)
	{
		d1 = cyl->b / -2.0 / cyl->a;
		d2 = d1;
	}
	if (disc > 0)
	{
		if (cyl->b > 0)
			tmp = (cyl->b + sqrt(disc)) / -2.0;
		else
			tmp = (cyl->b - sqrt(disc)) / -2.0;
		d1 = tmp / cyl->a;
		d2 = cyl->c / tmp;
	}
	return (check_point(cy, cyl, (t_d){d1, d2}, quad));
}

t_d					intersect_cylinder(t_vec *vec, t_cy *cy, t_dist *quad)
{
	t_c				cyl;
	t_vec			tmp;
	t_vec			matrix;

	matrix = (t_vec){vec[1].x, vec[1].y, vec[1].z};
	take_args(&cyl, cy, vec);
	tmp = (t_vec){cyl.vec->x, cyl.vec->y, cyl.vec->z};
	cyl.vpr_p = vec_subt(tmp, vec_multi(cyl.norm_ori,
	vec_scal(cyl.norm_ori, tmp)));
	cyl.vpr_cyl = vec_subt(vec_subt(matrix, cyl.point),
			vec_multi(cyl.norm_ori, vec_scal(cyl.norm_ori,
			vec_subt(matrix, cyl.point))));
	cyl.a = vec_scal(cyl.vpr_p, cyl.vpr_p);
	cyl.b = 2.0 * vec_scal(cyl.vpr_p, cyl.vpr_cyl);
	cyl.c = vec_scal(cyl.vpr_cyl, cyl.vpr_cyl) - pow(cy->diameter, 2) / 4.0;
	return (cyl_quadro_cyl(cy, &cyl, quad));
}
