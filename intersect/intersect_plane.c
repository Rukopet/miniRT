#include "minirt.h"

double			intersect_plane(t_vec *vec, t_pl *pl, t_rt *scene, t_vec *start)
{
	double		ret;
	t_vec 		*s_vec;
	t_vec		k;
	t_vec		orient;
	double		a;
	double		b;

	k = (t_vec){pl->x - start->z, pl->y - start->y, pl->z - start->z};
	orient = (t_vec){pl->vec_x, pl->vec_y, pl->vec_z};
	norm_vec(&orient);
	a = scalar_product(&k, &orient, 3);
	b =	scalar_product(vec, &orient,3);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (INFINITY);
	ret = -a / b;
	if (ret < 0)
		return (INFINITY);
	return (ret);
}