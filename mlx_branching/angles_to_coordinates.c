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

	ret_y = (double)sin(degress_to_radians(y));
	return (ret_y);
}

double 			angle_to_z(double z)
{
	double 		ret_z;

	ret_z = (double)sin(degress_to_radians(z));
	return (ret_z);
}

t_vec			*firs_dot_angles_to_coordinate(t_rt *scene, t_cam *cam)
{
	t_vec		*first_dot;

	first_dot = alloc_vector(angle_to_x(scene->d->angle_x - cam->fov / 2),
						  angle_to_y(scene->d->angle_x - cam->fov / 2),
						  angle_to_z(scene->d->angle_z + scene->d->fov_for_y
						  / 2));
	t_vec 		*ok = alloc_vector(first_dot->x, first_dot->y, first_dot->z);
	norm_vec(ok);
	return (first_dot);
}