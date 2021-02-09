#include "minirt.h"

//t_vp				*alloc_viewport(t_rt *scene)
//{
//	t_vp			*ret;
//	double			ratio;
//
//	if(!(ret = malloc(sizeof(t_vp))))
//		errors_and_exit(-1, scene);
//	ret->x = 1;
//	ratio = RES_X / RES_Y;
//	ret->y = 1 / ratio;
//	ret->x_iter = ret->x / RES_X;
//	ret->y_iter = ret->y / RES_Y;
//	return (ret);
//}

void rtx_with_angles(t_rt *scene, t_cam *cam)
{
	t_vec			*first_dot;

	first_dot = firs_dot_angles_to_coordinate(scene, cam);
	init_dots(scene);
}

void 				rtx(t_rt *scene)
{
	static int 		cam;
	static int 		max;

	max = check_max_cams(scene);
	cam = 0;
	matrix_rellocation(scene, cam);
	get_angles_to_data(scene, scene->cam[cam]);
	rtx_with_angles(scene,  scene->cam[cam]);

//	rtx_cam_zy(scene, &location, , 3);
//	vp = alloc_viewport(scene);
}
