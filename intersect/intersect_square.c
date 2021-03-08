#include "minirt.h"
#include <stdio.h>

double			intersect_square(t_vec *vec, t_sq *sq, t_rt *scene, t_vec
*start)
{
	double		a;
	double 		b;
	double 		dist[2];
	t_vec		*tmp[2];
	t_vec		normal;
	t_vec		k;

	k = (t_vec){(scene->d->vec_matrix->x - sq->x - start->x),
	(scene->d->vec_matrix->y - sq->y - start->y),
	(scene->d->vec_matrix->z - sq->z - start->z)};
	normal = (t_vec){sq->vec_x, sq->vec_y, sq->vec_z};
	norm_vec(&normal);
	b = scalar_product(vec, &normal, 3);
	a = scalar_product(&k, &normal, 3);
	if (b == 0 || (b > 0 && a > 0) || (a < 0 && b < 0))
		return (INFINITY);
	dist[0] = -a / b;
	tmp[0] = product_vec_and_int(vec, dist[0], 3);
	k = (t_vec){-k.x, -k.y, -k.z};
	tmp[1] = vector_deduction(tmp[0], &k, 1);
	dist[1] = sq->side_size / 2.0;
	if (fabs(tmp[1]->x) > dist[1] || fabs(tmp[1]->y) > dist[1] || fabs
	(tmp[1]->z) > dist[1])
		return (INFINITY);
	return (*dist > 0 ? *dist : INFINITY);


}