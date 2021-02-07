#include "minirt.h"

t_vp				*alloc_viewport(t_rt *scene)
{
	t_vp			*ret;
//	double			ratio;
//
//	if(!(ret = malloc(sizeof(t_vp))))
//		erros_and_exit(-1, scene);
//	ret->x = 1;
//	ratio = RES_X / RES_Y;
//	ret->y = 1 / ratio;
//	ret->x_iter = ret->x / RES_X;
//	ret->y_iter = ret->y / RES_Y;
	return (ret);
}

void 				rtx_branching(t_rt *scene, t_matrix *matrix, int cam)
{

}

void 				rtx(t_rt *scene)
{
	static t_matrix location;
	static int 		cam;
	static int 		max;

	max = check_max_cams(scene);
	cam = 0;
	matrix_rellocation(&location, scene, cam);
	rtx_branching(scene, &location, cam)
//	vp = alloc_viewport(scene);
}
