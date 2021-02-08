#include "minirt.h"

t_vp				*alloc_viewport(t_rt *scene)
{
	t_vp			*ret;
//	double			ratio;
//
//	if(!(ret = malloc(sizeof(t_vp))))
//		errors_and_exit(-1, scene);
//	ret->x = 1;
//	ratio = RES_X / RES_Y;
//	ret->y = 1 / ratio;
//	ret->x_iter = ret->x / RES_X;
//	ret->y_iter = ret->y / RES_Y;
	return (ret);
}
double 				rtx_cam_zyz(t_rt *scene, t_matrix *matrix, t_cam *cam)
{
	double 			angle_z;
	double			angle_xy;
}

double 				rtx_cam_zy(t_rt *scene, t_matrix *matrix, t_cam *cam, int
xyz)
{
	t_vec			*v_cdir;
	double 			cos_cam_z;
	double 			degrees;
	t_vec			*tmp_z;

	v_cdir = alloc_vector(cam->vec_x, cam->vec_y, cam->vec_z);
	tmp_z = alloc_vector(cam->vec_x, cam->vec_y, 0);
	cos_cam_z = scalar_product_cos(v_cdir, tmp_z, 2);
	degrees = radians_to_degrees(acos(cos_cam_z));

	/*
	** tmp_z being freed
	*/

	return (degrees);
}

void 				rtx(t_rt *scene)
{
	static t_matrix location;
	static int 		cam;
	static int 		max;

	max = check_max_cams(scene);
	cam = 0;
	matrix_rellocation(&location, scene, cam);
	rtx_branching(scene, &location, scene->cam[cam]);
//	vp = alloc_viewport(scene);
}
