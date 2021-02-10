#include "minirt.h"

t_vec *rotate_osy(t_rt *scene, t_cam *cam, double angle, t_matrix *matrix)
{
	t_cos_sin 	*cs;
	t_vec		*tmp;

	tmp = alloc_vector(0, 0, 1);
	cs = alloc_init_cos_sin(scene, angle);
	init_matrix_z(scene, matrix, cs);
	matrix_use_vec(matrix, &tmp);
	return (tmp);
}