#include "minirt.h"

static void 		do_plane(t_pl *pl, t_cy *cy)
{
	pl->x = cy->x;
	pl->y = cy->y;
	pl->z = cy->z;
	pl->vec_x = cy->vec_x;
	pl->vec_y = cy->vec_y;
	pl->vec_z = cy->vec_z;
}

static double 		intersect_ret_double(t_cyl *cyl, t_cy *cy, t_rt *scene,
t_vec *start)
{
	t_pl			pl;
	t_vec 			ret;
	double 			check;
	double 			pl_t;

	check = (cyl->t[0] >= 0) ? cyl->t[0] : INFINITY;
	check = (cyl->t[1] >= 0) ? cyl->t[1] : check;
	ret = (t_vec){scene->d->vec_matrix->x + cyl->vec->x * check,
				  scene->d->vec_matrix->y + cyl->vec->y * check,
				  scene->d->vec_matrix->z + cyl->vec->z * check};
	do_plane(&pl, cy);
	pl_t = intersect_plane(&cyl->orient, &pl, scene, scene->d->vec_matrix);
	if (pl_t <= cy->height / 2)
		check = pl_t;
	pl_t = intersect_plane(&(t_vec){-cyl->orient.x, -cyl->orient.y,
	-cyl->orient.z}, &pl, scene, scene->d->vec_matrix);
	if (pl_t <= cy->height / 2)
		check = pl_t;
	return (check);
}
static void 		take_args(t_cyl *cyl, t_cy *cy, t_vec *vec)
{
	cyl->orient = (t_vec){cy->vec_x, cy->vec_y, cy->vec_z};
	cyl->point = (t_vec){cy->x, cy->y, cy->z};;
	cyl->vec = vec;
}

double 				intersect_cylinder(t_vec *vec, t_cy *cy, t_rt *scene,
							  t_vec *start)
{
	t_cyl			cyl;

	take_args(&cyl, cy, vec);
	cyl.v[0] = vector_cross(vec, &cyl.orient);
	cyl.m_v[0] = vector_deduction(scene->d->vec_matrix, &cyl.point, 3);
	cyl.v[1] = vector_cross(cyl.m_v[0], &cyl.orient);
	cyl.d[0] = scalar_product(&cyl.v[0], &cyl.v[0], 3);
	cyl.d[1] = scalar_product(&cyl.v[0], &cyl.v[1], 3) * 2;
	cyl.d[2] = scalar_product(&cyl.v[1], &cyl.v[1], 3) - pow(cy->diameter /
	2, 2) * scalar_product(&cyl.orient, &cyl.orient, 3);
	cyl.d[3] = cyl.d[1] * cyl.d[1] - (4 * cyl.d[0] * cyl.d[1]);
	if (cyl.d[3] < MINIMUM)
		return (INFINITY);
	cyl.d[0] *= 2;
	cyl.d[3] = sqrt(cyl.d[3]);
	cyl.t[0] = (-cyl.d[1] - cyl.d[3]) / cyl.d[0];
	cyl.t[1] = (-cyl.d[1] + cyl.d[3]) / cyl.d[0];
	if (cyl.m_v[0] != NULL)
		free(cyl.m_v[0]);
	return (intersect_ret_double(&cyl, cy, scene, start));
}