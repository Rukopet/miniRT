#include "minirt.h"

double			intersect_plane(t_vec vec[2], t_pl *pl, t_rt *scene, t_vec
*start)
{
	double		ret;
	t_vec		k;
	t_vec		normal;
	double		a;
	double		b;

	k = (t_vec){vec[1].x - pl->x, vec[1].y - pl->y, vec[1].z - pl->z};
	normal = (t_vec){pl->vec_x, pl->vec_y, pl->vec_z};
	if (vec[1].x != start->x)
		a = a;
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