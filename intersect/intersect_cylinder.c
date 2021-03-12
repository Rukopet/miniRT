#include "minirt.h"

//static void 		do_plane(t_pl *pl, t_cy *cy)
//{
//	pl->x = cy->x;
//	pl->y = cy->y;
//	pl->z = cy->z;
//	pl->vec_x = cy->vec_x;
//	pl->vec_y = cy->vec_y;
//	pl->vec_z = cy->vec_z;
//}
//
//static double 		intersect_ret_double(t_cyl *cyl, t_cy *cy, t_rt *scene,
//t_vec *start)
//{
//	t_pl			pl;
//	t_vec 			ret;
//	double 			check;
//	double 			pl_t;
//	double 			tmp;
//
//	tmp = INFINITY;
//	check = (cyl->t[0] >= 0) ? cyl->t[0] : INFINITY;
//	check = (cyl->t[1] >= 0) ? cyl->t[1] : check;
//
//	ret = (t_vec){scene->d->vec_matrix->x + cyl->vec->x * check,
//				  scene->d->vec_matrix->y + cyl->vec->y * check,
//				  scene->d->vec_matrix->z + cyl->vec->z * check};
//	do_plane(&pl, cy);
//	pl_t = intersect_plane(&cyl->orient, &pl, scene, scene->d->vec_matrix);
//	if (pl_t <= cy->height / 2)
//		check = pl_t;
//	pl_t = intersect_plane(&(t_vec){-cyl->orient.x, -cyl->orient.y,
//	-cyl->orient.z}, &pl, scene, scene->d->vec_matrix);
//	if (pl_t <= cy->height / 2)
//		check = pl_t;
//	return (check);
//}
//static void 		take_args(t_cyl *cyl, t_cy *cy, t_vec *vec)
//{
//	cyl->orient = (t_vec){cy->vec_x, cy->vec_y, cy->vec_z};
//	cyl->point = (t_vec){cy->x, cy->y, cy->z};
//	cyl->norm_v = (t_vec){cy->vec_x, cy->vec_y, cy->vec_z};
//	norm_vec(&cyl->norm_v);
//	cyl->vec = vec;
//}


static void take_args(t_c *cyl, t_cy *cy, t_vec *vec)
{
	cyl->orient = (t_vec){cy->vec_x, cy->vec_y, cy->vec_z};
//	cyl->point = (t_vec){cy->x - start->x, cy->y - start->y, cy->z - start->z};
	cyl->point = (t_vec){cy->x, cy->y, cy->z};
	cyl->norm_ori = (t_vec){cy->vec_x, cy->vec_y, cy->vec_z};
	norm_vec(&cyl->norm_ori);
	cyl->vec = vec;
}

static int check_height_cy(t_cy *cy, t_c *cyl, t_d t)
{
	t_vec		p;
	double 		tmp;

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

static t_d check_point(t_cy *cy, t_c *cyl, t_d t, t_dist *quad)
{
	double			tmp;
	t_vec			x;

	x = vec_subt(cyl->vec[1], cyl->point);
	if (t.d1 > t.d2)
	{
		tmp = t.d1;
		t.d1 = t.d2;
		t.d2 = tmp;
		quad->quad1 = INSIDE;
	}
	if (t.d1 < 0 || !check_height_cy(cy, cyl, t))
	{
		t.d1 = t.d2;
		t.d2 = INFINITY;
		if (t.d1 < 0 || !check_height_cy(cy, cyl, t))
			return ((t_d){INFINITY, INFINITY});
	}
	quad->quad1 = vec_scal(*cyl->vec, vec_multi(cyl->norm_ori,
												cy->diameter / 2)) + vec_scal(x, cyl->vec[0]);
	return (t);
}

static t_d cyl_quadro_cyl(t_cy *cy, t_c *cyl, t_dist *quad)
{
	double 			disc;
	double 			d1;
	double 			d2;
	double 			tmp;

	disc = pow(cyl->b, 2) - 4 * cyl->a * cyl->c;
	if (disc < 0)
		return((t_d){INFINITY, INFINITY});
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

t_d intersect_cylinder(t_vec *vec, t_cy *cy, t_dist *quad)
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