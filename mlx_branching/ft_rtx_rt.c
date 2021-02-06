#include "minirt.h"

t_vp				*alloc_viewport(t_rt *scene)
{
	t_vp			*ret;
	double			ratio;

	if(!(ret = malloc(sizeof(t_vp))))
		erros_and_exit(-1, scene);
	ret->x = 1;
	ratio = RES_X / RES_Y;
	ret->y = 1 / ratio;
	ret->x_iter = ret->x / RES_X;
	ret->y_iter = ret->y / RES_Y;
	return (ret);
}
void 				rtx(t_rt *scene)
{
	int 			x;
	int 			y;
	double 			x_iter;
	double			y_iter;
	int 			color;
	t_vec			*ray;
	t_limits		*vp;

	vp = alloc_viewport(scene);
}
