#include "minirt.h"

double 				scalar_product_self(t_vec *vec)
{
	return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

double				scalar_product_cos(t_vec *vec1, t_vec *vec2, int flag)
{
	double 			ret;

	ret = (scalar_product(vec1, vec2, 3)) /
			(length_vector(vec1) * length_vector(vec2));
	if (flag == 1)
		free(vec1);
	else if (flag == 2)
		free(vec2);
	else if (flag == 0)
	{
		free(vec1);
		free(vec2);
		vec1 = NULL;
		vec2 = NULL;
	}
	return (ret);
}

t_vec 				*product_vec_and_int(t_vec *vec, double distance, int flag)
{
	t_vec			*new_vec;

	new_vec = alloc_vector(vec->x * distance, vec->y * distance, vec->z *
	distance);
	if (flag == 1)
		free(vec);
	return (new_vec);
}

double				normal_vector(t_vec *vec1, t_vec *vec2)
{
	return (scalar_product(vec1, vec2, 3) / (length_vector(vec1) +
	length_vector(vec2)) / 2);
}