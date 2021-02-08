#include "minirt.h"

double 				scalar_product_self(t_vec *vec)
{
	return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

double				scalar_product_cos(t_vec *vec1, t_vec *vec2, int flag)
{
	double 			ret;

	ret = length_vector(vec1, vec2, 3) / (scalar_product_self(vec1) *
			scalar_product_self(vec2));
	if (flag == 1)
		free(f);
	else if (flag == 2)
		free(s);
	else if (flag == 0)
	{
		free(f);
		free(s);
	}
	return (ret);
}