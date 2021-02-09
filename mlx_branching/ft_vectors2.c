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