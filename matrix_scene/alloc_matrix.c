#include "minirt.h"

static double	**alloc_el(int k, int s)
{
	double 		**ret;
	double 		*tmp;
	int 		i;
	int 		j;

	i = -1;
	if (!(ret = malloc(sizeof(double*) * k + k * s * sizeof(double))))
		errors_and_exit(-1, NULL);
	tmp = (double*)((char*)ret + k * sizeof(double*));
	while (++i < k)
		ret[i] = tmp + i * s;
	i = 0;
	while (i < k)
	{
		j = -1;
		while (++j < s)
			ret[i][j] = 0;
		i++;
	}
	return (ret);
}

void			alloc_matrix(t_cam *cam)
{
	int			i;
	int 		j;

	cam->tran_mat = alloc_el(4, 4);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			cam->tran_mat[i][j] = (i == j) ? 1 : 0;
	}
}