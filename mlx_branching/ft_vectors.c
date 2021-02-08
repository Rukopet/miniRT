#include "minirt.h"

t_vec				*alloc_vector(double x, double y, double z)
{
	t_vec			*ret;
	t_rt 			l;

	if (!(ret = malloc(sizeof(t_vec))))
		errors_and_exit(-1, &l);
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

double 				length_vector(t_vec *vec)
{
	return (sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

int 				norm_vec(t_vec *vec)
{
	double			len;

	len = length_vector(vec);
	vec->x = vec->x / len;
	vec->y = vec->y / len;
	vec->z = vec->z / len;
	return (0);
}

t_vec				*vector_deduction(t_vec *fir, t_vec *sec, int flag)
{
	t_vec			*ret;

	ret = alloc_vector(fir->x - sec->x, fir->y - sec->y,
					fir->z - sec->z);
	if (flag == 1)
		free(fir);
	else if (flag == 2)
		free(sec);
	else if (flag == 0)
	{
		free(fir);
		free(sec);
	}
	return (ret);
}

double				scalar_product(t_vec *f, t_vec *s, int flag)
{
	double			ret;

	ret = ((f->x * s->x) + (f->y * s->y) + (f->z * s->z));
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