/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:12:32 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 21:14:43 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			geron_s(t_vec *ab, t_vec *ac, t_vec *bc)
{
	double		per;
	double		check;

	per = (length_vector(ab) + length_vector(ac) + length_vector(bc)) * 0.5;
	check = (per * (per - length_vector(ab)) * (per - length_vector(ac)) *
			(per - length_vector(bc)));
	check *= (check < 0) ? -1 : 1;
	check = (check == 0) ? 0 : sqrt(check);
	return (check);
}

static double	summ_square(t_triangle *tri, t_vec p, double dist)
{
	double		sq_pac;
	double		sq_pbc;
	double		sq_pab;

	sq_pac = geron_s(&tri->ac_s, &(t_vec){tri->p[0].x - p.x, tri->p[0].y - p.y,
	tri->p[0].z - p.z}, &(t_vec){tri->p[2].x - p.x, tri->p[2].y - p.y,
	tri->p[2].z - p.z});
	sq_pab = geron_s(&tri->ab_s, &(t_vec){tri->p[0].x - p.x, tri->p[0].y - p.y,
	tri->p[0].z - p.z}, &(t_vec){tri->p[1].x - p.x, tri->p[1].y - p.y,
	tri->p[1].z - p.z});
	sq_pbc = geron_s(&tri->bc_s, &(t_vec){tri->p[1].x - p.x, tri->p[1].y - p.y,
	tri->p[1].z - p.z}, &(t_vec){tri->p[2].x - p.x, tri->p[2].y - p.y,
	tri->p[2].z - p.z});
	if (((sq_pab + sq_pac + sq_pbc) - tri->s) < MINIMUM)
		return (dist);
	else
		return (INFINITY);
}

static double	check_normal(t_triangle *tri)
{
	double		dist;
	t_vec		p;

	if (!isinf(dist = intersect_plane(tri->vec, &tri->pl)))
	{
		p = (t_vec){dist * tri->vec->x + tri->vec[1].x,
			dist * tri->vec->y + tri->vec[1].y,
			dist * tri->vec->z + tri->vec[1].z};
		return (summ_square(tri, p, dist));
	}
	return (INFINITY);
}

double			intersect_triangle(t_vec vec[2], t_tr *tr)
{
	t_triangle	tri;

	tri.p[0] = (t_vec){tr->first_x, tr->first_y, tr->first_z};
	tri.p[1] = (t_vec){tr->second_x, tr->second_y, tr->second_z};
	tri.p[2] = (t_vec){tr->third_x, tr->third_y, tr->third_z};
	tri.ab_s = (t_vec){tri.p[1].x - tri.p[0].x, tri.p[1].y - tri.p[0].y,
	tri.p[1].z - tri.p[0].z};
	tri.ac_s = (t_vec){tri.p[2].x - tri.p[0].x, tri.p[2].y - tri.p[0].y,
	tri.p[2].z - tri.p[0].z};
	tri.bc_s = (t_vec){tri.p[2].x - tri.p[1].x, tri.p[2].y - tri.p[1].y,
	tri.p[2].z - tri.p[1].z};
	tri.s = geron_s(&tri.ab_s, &tri.ac_s, &tri.bc_s);
	tri.vec = vec;
	tri.normal = vector_cross(&tri.ac_s, &tri.ab_s);
	norm_vec(&tri.normal);
	tri.pl = (t_pl){.x = tri.p[0].x, .y = tri.p[0].y, .z = tri.p[0].z,
	.vec_x = tri.normal.x, .vec_y = tri.normal.y, .vec_z = tri.normal.z};
	return (check_normal(&tri));
}
