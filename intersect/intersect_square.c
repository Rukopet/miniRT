#include "minirt.h"
#include <stdio.h>

static double 		check_plane(t_sq *sq, t_vec *vec, t_rt *scene, t_vec *start)
{
	t_pl		tmp;
	double		dist;

	tmp = (t_pl){.x = sq->x - start->x, .y = sq->y - start->y,
			  .z =  sq->z - start->z , .vec_x = sq->vec_x,
			  .vec_y = sq->vec_y, .vec_z = sq->vec_z};
	dist = intersect_plane(vec, &tmp, scene, start);
	if (isnormal(dist) && (dist > MINIMUM))
		return (dist);
	return (INFINITY);
}

static int 		check_borders(t_vec tmp[4], double k[3], t_sq *sq)
{
	double 		p;
	double 		up;
	t_vec		check;

	check = vec_subt(tmp[3], (t_vec){sq->x, sq->y, sq->z});
	p = vec_scal(check, tmp[0]);
	up = vec_scal(check, tmp[1]);
	if ((fabs(p) <= sq->side_size / 2.0) && (fabs(up) <= sq->side_size / 2.0))
		return (1);
	return (0);
}

double			intersect_square(t_vec vec[2], t_sq *sq, t_rt *scene, t_vec
*start)
{
//	double		a;
//	double 		b;
//	double 		dist[2];
//	t_vec		*tmp[2];
//	t_vec		normal;
//	t_vec		k;
//
//	k = (t_vec){(scene->d->vec_matrix->x - sq->x - start->x),
//	(scene->d->vec_matrix->y - sq->y - start->y),
//	(scene->d->vec_matrix->z - sq->z - start->z)};
//	normal = (t_vec){sq->vec_x, sq->vec_y, sq->vec_z};
//	norm_vec(&normal);
//	b = scalar_product(vec, &normal, 3);
//	a = scalar_product(&k, &normal, 3);
//	if (b == 0 || (b > 0 && a > 0) || (a < 0 && b < 0))
//		return (INFINITY);
//	dist[0] = -a / b;
//	tmp[0] = product_vec_and_int(vec, dist[0], 3);
//	k = (t_vec){-k.x, -k.y, -k.z};
//	tmp[1] = vector_deduction(tmp[0], &k, 1);
//	dist[1] = sq->side_size / 2.0;
//	if (fabs(tmp[1]->x) > dist[1] || fabs(tmp[1]->y) > dist[1] || fabs
//	(tmp[1]->z) > dist[1])
//		return (INFINITY);
//	return (*dist > 0 ? *dist : INFINITY);
	t_vec		tmp[4];
	double 		k[3];
	double 		dist;

	tmp[2] = (sq->vec_y == 1) ? (t_vec){0, 0, 1} : (t_vec){0, 1, 0};
	tmp[2] = (sq->vec_y == -1) ? (t_vec){0, 0, 1} : tmp[2];
	tmp[0] = vector_cross(&(t_vec){sq->vec_x, sq->vec_y, sq->vec_z}, &tmp[2]);
	norm_vec(&tmp[0]);
	tmp[1] = vector_cross(&(t_vec){sq->vec_x, sq->vec_y, sq->vec_z}, &tmp[0]);
	norm_vec(&tmp[1]);
	dist = check_plane(sq, vec, scene, start);
	if (isnormal(dist))
	{
		tmp[3] = vec_multi(vec[0], dist);
		tmp[3] = (t_vec){start->x + tmp[3].x, start->y + tmp[3].y, start->z +
		tmp[3].z};
		if (check_borders(tmp, k, sq))
			return (dist);
	}
	return (INFINITY);
}