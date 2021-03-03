#include "minirt.h"

t_vec		take_triangle_normal(t_tr *tr, t_vec dot)
{
	t_vec	point[2];
	t_vec	ded;

	point[0] = (t_vec){tr->first_x, tr->first_y, tr->first_z};
	point[1] = (t_vec){tr->second_x, tr->second_y, tr->second_z};
//	ded = (t_vec){point[0].x - point[1].x, point[0].y - point[1].y, point[0]
//	.z - point[1].z};
	ded = (t_vec){dot.x - point[0].x, dot.y - point[0].y, dot.z - point[0].z};
	norm_vec(&ded);




}