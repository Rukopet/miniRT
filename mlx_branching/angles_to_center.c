#include "minirt.h"


double 				rtx_cam_x(t_cam *cam, t_vec *tmp)
{
	double 			cos_cam_z;
	double 			degrees;
	t_vec			*tmp_x;

	tmp_x = alloc_vector(1, 0, 0);
	cos_cam_z = scalar_product_cos(tmp, tmp_x, 2);
	degrees = radians_to_degrees(acos(cos_cam_z));

	/*
	** tmp_x being freed
	*/

	return (degrees);
}

double 				rtx_cam_y(t_cam *cam, t_vec *tmp)
{
	double 			cos_cam_z;
	double 			degrees;
	t_vec			*tmp_y;

	tmp_y = alloc_vector(0, 1, 0);
	cos_cam_z = scalar_product_cos(tmp, tmp_y, 2);
	degrees = radians_to_degrees(acos(cos_cam_z));

	/*
	** tmp_y being freed
	*/

	return (degrees);
}

double 				rtx_cam_z(t_rt *scene, t_cam *cam, t_vec *tmp)
{
	t_vec			*v_cdir;
	double 			cos_cam_z;
	double 			degrees;
	t_vec			*tmp_z;

	v_cdir = alloc_vector(cam->vec_x, cam->vec_y, cam->vec_z);
	cos_cam_z = scalar_product_cos(tmp, v_cdir, 3);
	degrees = radians_to_degrees(acos(cos_cam_z));

	/*
	** tmp_z v_z being freed
	*/

	if (scene->d)
		scene->d->v_cdir = v_cdir;
	return (degrees);
}

void 				get_angles_to_data(t_rt *scene, t_cam *cam)
{
	t_vec			*tmp;

	if (cam->vec_x == 0 && cam->vec_y == 0 && cam->vec_z == 1)
		norm_vec(tmp = alloc_vector(cam->vec_x, cam->vec_y, 1));
	else
		norm_vec(tmp = alloc_vector(cam->vec_x, cam->vec_y, 0));
	if (scene->d && scene->resolution)
	{

		scene->d->angle_x = rtx_cam_x(cam, tmp);
		scene->d->angle_y = rtx_cam_y(cam, tmp);
		scene->d->angle_z = rtx_cam_z(scene, cam, tmp);
		scene->d->x_res_ratio = (double)cam->fov / (double)scene->resolution->x;
		scene->d->fov_for_y = (scene->d->x_res_ratio * RES_Y);
	}
	free(tmp);
	tmp = NULL;
}
