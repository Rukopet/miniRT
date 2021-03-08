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

t_vec				firs_dot_angles_to_coordinate(t_angles *angles)
{
	t_vec			tmp;

	tmp = (t_vec){angles->angle_x, angles->angle_y, angles->angle_z};
	norm_vec(&tmp);
	return (tmp);
}