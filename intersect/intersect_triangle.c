#include "minirt.h"

//static double	check_points_mal(t_triangle trian, t_tr *tr, t_rt *sc, t_vec
//*vec)
//{
//	double 		eq[4];
//	t_vec		tmp[3];
//	t_vec		*n_f;
//
//	tmp[0] = vector_cross(vec, trian.mal[1]);
//	eq[0] = scalar_product(trian.mal[0], &tmp[0], 3);
//	if (fabs(eq[0]) < MINIMUM)
//		return (INFINITY);
//	eq[1] = 1.0 / eq[0];
//	n_f = vector_deduction(sc->d->vec_matrix, trian.p[0], 3);
//	eq[1] = scalar_product(&tmp[0], n_f, 3) * eq[1];
//	if (eq[1] < 0 || eq[1] > 1)
//		return (INFINITY);
//	tmp[1] = vector_cross(&tmp[0], trian.mal[0]);
//	eq[2] = scalar_product(vec, &tmp[1], 3);
//	if (eq[2] < 0 || (eq[1] + eq[2]) > 1)
//		return (INFINITY);
//	eq[3] = scalar_product(trian.mal[1], n_f, 2);
//	return (eq[3]);
//}
//
//double			intersect_triangle(t_vec *vec, t_tr *tr, t_rt *sc, t_vec
//*start)
//{
//	t_triangle	trian;
//	t_vec		mal[2];
//	t_vec		p[3];
//
//	p[0] = (t_vec){tr->first_x, tr->first_y, tr->first_z};
//	p[1] = (t_vec){tr->second_x,tr->second_y, tr->second_z};
//	p[2] = (t_vec){tr->third_x, tr->third_y, tr->third_z};
//	mal[0] = (t_vec){p[1].x - p->x, p[1].y - p->y, p[1].z - p->z};
//	mal[1] = (t_vec){p[2].x - p->x, p[2].z - p->z, p[2].z - p->z};
//	trian.start = start;
//	trian.p[0] = &p[0];
//	trian.p[1] = &p[1];
//	trian.p[2] = &p[2];
//	trian.mal[0] = &mal[0];
//	trian.mal[1] = &mal[1];
//	return (check_points_mal(trian, tr, sc, vec));
//}

double 			geron_s(t_vec *ab, t_vec *ac, t_vec *bc)
{
	double 		per;
	double		check;

	per	= (length_vector(ab) + length_vector(ac) + length_vector(bc)) * 0.5;
	check = (per * (per - length_vector(ab)) * (per - length_vector(ac)) *
			(per - length_vector(bc)));
	check *= (check < 0) ? -1 : 1;
	check = (check == 0) ? 0 : sqrt(check);
	return (check);
}

static double	summ_square(t_triangle *tri, t_vec p, double dist)
{
	double		sq_pac;
	double 		sq_pbc;
	double		sq_pab;
	double 		sum;

	sq_pac = geron_s(&tri->ac_s, &(t_vec){tri->p[0].x - p.x, tri->p[0].y - p.y,
	tri->p[0].z - p.z}, &(t_vec){tri->p[2].x - p.x, tri->p[2].y - p.y,
	tri->p[2].z - p.z});
	sq_pab = geron_s(&tri->ab_s, &(t_vec){tri->p[0].x - p.x, tri->p[0].y - p.y,
	tri->p[0].z - p.z}, &(t_vec){tri->p[1].x - p.x, tri->p[1].y - p.y,
	tri->p[1].z - p.z});
	sq_pbc = geron_s(&tri->bc_s, &(t_vec){tri->p[1].x - p.x, tri->p[1].y - p.y,
	tri->p[1].z - p.z}, &(t_vec){tri->p[2].x - p.x, tri->p[2].y - p.y,
	tri->p[2].z - p.z});
	if (((sum = sq_pab + sq_pac + sq_pbc) - tri->s) < MINIMUM)
		return (dist);
	else
		return (INFINITY);
//	return (((sq_pab + sq_pac + sq_pbc) - tri->s) < MINIMUM ? dist : INFINITY);
}

static double	check_normal(t_triangle *tri, t_tr *tr, t_rt *sc, t_vec *start)
{
	double 		dist;
	t_vec		p;

	if (!isinf(dist = intersect_plane(tri->vec, &tri->pl, sc, start)))
	{
		p = (t_vec){dist * tri->vec->x, dist * tri->vec->y, dist * tri->vec->z};
		return (summ_square(tri, p, dist));
	}
	return (INFINITY);
}

double			intersect_triangle(t_vec vec[2], t_tr *tr, t_rt *sc, t_vec
*start)
{
	t_triangle	tri;

	tri.p[0] = (t_vec){tr->first_x - start->x, tr->first_y - start->y,
	tr->first_z - start->z};
	tri.p[1] = (t_vec){tr->second_x - start->x, tr->second_y - start->y,
	tr->second_z - start->z};
	tri.p[2] = (t_vec){tr->third_x - start->x, tr->third_y - start->y,
	tr->third_z - start->z};
	tri.ab_s = (t_vec){tri.p[1].x -  tri.p[0].x, tri.p[1].y -  tri.p[0].y,
	tri.p[1].z -  tri.p[0].z};
	tri.ac_s = (t_vec){tri.p[2].x -  tri.p[0].x, tri.p[2].y -  tri.p[0].y,
	tri.p[2].z -  tri.p[0].z};
	tri.bc_s = (t_vec){tri.p[2].x -  tri.p[1].x ,tri.p[2].y -  tri.p[1].y ,
	tri.p[2].z -  tri.p[1].z};
	tri.s = geron_s(&tri.ab_s, &tri.ac_s, &tri.bc_s);
	tri.vec = vec;
	tri.normal = vector_cross(&tri.ac_s, &tri.ab_s);
	norm_vec(&tri.normal);
	tri.pl = (t_pl){.x = tri.p[0].x, .y =  tri.p[0].y, .z = tri.p[0].z,
	.vec_x = tri.normal.x, .vec_y = tri.normal.y, .vec_z = tri.normal.z};
	return (check_normal(&tri, tr, sc, start));
}