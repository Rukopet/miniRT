#include "minirt.h"
#include <stdio.h>
double intersect_sphere(t_vec *vec, t_sp *sp, t_rt *scene)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	distance_1;
	double	distance_2;
	t_vec	*sp_center;
	t_vec	*cam_sp;
//	sp_center = vector_deduction(alloc_vector(sp->x, sp->y, sp->z),
//								 scene->d->vec_matrix, 1);
	a = 1;
	sp_center = alloc_vector(sp->x, sp->y, sp->z);
	b = 2 * scalar_product(sp_center, vec, 3);
	c = scalar_product(sp_center, sp_center, 3) - pow(sp->diameter / 2, 2);
	if (0 > (discriminant = b * b - 4 * a * c))
	{
		printf("%10.4f*", discriminant);
		return (-100);
	}
	else
	{
		printf("%10.4fsdfgfref", discriminant);
		return (discriminant);
	}

	distance_1 = -1 * b - sqrt(discriminant) / (2 * a);
	distance_2 = -1 * b + sqrt(discriminant) / (2 * a);
	if (distance_1 < 0)
		return (0);
	return (distance_1);
}