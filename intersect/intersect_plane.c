#include "minirt.h"

double			intersect_plane(t_vec *vec, t_pl *pl, t_rt *scene, t_vec *start)
{
	double		ret;
	t_vec		k;
	t_vec		normal;
	double		a;
	double		b;

	k = (t_vec){pl->x - scene->d->vec_matrix->x, pl->y -
	scene->d->vec_matrix->y, pl->z - scene->d->vec_matrix->z};
	normal = (t_vec){pl->vec_x, pl->vec_y, pl->vec_z};
	k = (t_vec){-k.x, -k.y, -k.z};
	norm_vec(&normal);
	a = scalar_product(&k, &normal, 3);
	b =	scalar_product(vec, &normal, 3);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (INFINITY);
	ret = -a / b;
	if (ret < 0)
		return (INFINITY);
	return (ret);
}