#include "minirt.h"

double 			angle_to_x(double x)
{
	double 		ret_x;

	ret_x = (double)cos(degress_to_radians(x));
	return (ret_x);
}

double 			angle_to_y(double y)
{
	double 		ret_y;

	ret_y = (double)cos(degress_to_radians(y));
	return (ret_y);
}

double 			angle_to_z(double z)
{
	double 		ret_z;

	ret_z = (double)sin(degress_to_radians(z));
	return (ret_z);
}

//t_vec *rotate_osz(t_rt *scene, t_cam *cam, double angle, t_matrix *matrix)
//{
//	t_cos_sin 	*cs;
//
//	cs = alloc_init_cos_sin(scene, angle);
//	init_matrix_z(scene, matrix, cs);
//	return (tmp);
//}

t_vec *firs_dot_angles_to_coordinate(t_angles *angles)
{
	t_vec		*first_dot;

	first_dot = alloc_vector(angle_to_x(angles->angle_x),
						  angle_to_y(angles->angle_y),
						  angle_to_z(angles->angle_z));
//	t_vec 		*ok = alloc_vector(first_dot->x, first_dot->y, first_dot->z);
//	norm_vec(ok);
//	t_matrix 		*mat;
//	t_matrix 		*mat1;
//	t_vec		*tmp;
//	t_cos_sin 	*cs;
//	t_cos_sin 	*cs1;
//
//	tmp = alloc_vector(1, 0, 0);
//	mat = malloc(sizeof(t_matrix));
//	mat1 = malloc(sizeof(t_matrix));
//	alloc_matrix_vecs(mat, scene);
//	alloc_matrix_vecs(mat1, scene);
//	matrix_use_vec(mat, &tmp);
//
//	cs = alloc_init_cos_sin(scene, scene->d->angle_x);
//	cs1 = alloc_init_cos_sin(scene, scene->d->angle_y);
//	init_matrix_z(scene, mat, cs);
//	init_matrix_z(scene, mat1, cs1);
////	first_dot = rotate_osz(scene, cam, scene->d->angle_x, mat);
	norm_vec(first_dot);
	return (first_dot);
}