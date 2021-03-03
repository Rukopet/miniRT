#include "minirt.h"

static double	check_points_mal(t_triangle trian, t_tr *tr, t_rt *sc, t_vec
*vec)
{
	double 		eq[4];
	t_vec		tmp[3];
	t_vec		*n_f;

	tmp[0] = vector_cross(vec, trian.mal[1]);
	eq[0] = scalar_product(trian.mal[0], &tmp[0], 3);
	if (fabs(eq[0]) < MINIMUM)
		return (INFINITY);
	eq[1] = 1.0 / eq[0];
	n_f = vector_deduction(sc->d->vec_matrix, trian.p[0], 3);
	eq[1] = scalar_product(&tmp[0], n_f, 3) * eq[1];
	if (eq[1] < 0 || eq[1] > 1)
		return (INFINITY);
	tmp[1] = vector_cross(&tmp[0], trian.mal[0]);
	eq[2] = scalar_product(vec, &tmp[1], 3);
	if (eq[2] < 0 || (eq[1] + eq[2]) > 1)
		return (INFINITY);
	eq[3] = scalar_product(trian.mal[1], n_f, 2);
	return (eq[3]);
}

double			intersect_triangle(t_vec *vec, t_tr *tr, t_rt *sc, t_vec
*start)
{
	t_triangle	trian;
	t_vec		mal[2];
	t_vec		p[3];

	p[0] = (t_vec){tr->first_x, tr->first_y, tr->first_z};
	p[1] = (t_vec){tr->second_x,tr->second_y, tr->second_z};
	p[2] = (t_vec){tr->third_x, tr->third_y, tr->third_z};
	mal[0] = (t_vec){p[1].x - p->x, p[1].y - p->y, p[1].z - p->z};
	mal[1] = (t_vec){p[2].x - p->x, p[2].z - p->z, p[2].z - p->z};
	trian.start = start;
	trian.p[0] = &p[0];
	trian.p[1] = &p[1];
	trian.p[2] = &p[2];
	trian.mal[0] = &mal[0];
	trian.mal[1] = &mal[1];
	return (check_points_mal(trian, tr, sc, vec));
}