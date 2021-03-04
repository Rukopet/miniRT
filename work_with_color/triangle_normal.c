#include "minirt.h"

t_vec		take_triangle_normal(t_tr *tr, t_vec dot)
{
	t_vec	pnt[2];
	t_vec	ded[2];
	t_vec	vec[2];
	double 	len[2];

	pnt[0] = (t_vec){tr->first_x, tr->first_y, tr->first_z};
	pnt[1] = (t_vec){tr->second_x, tr->second_y, tr->second_z};
	vec[0] = (t_vec){dot.x - pnt[0].x, dot.y - pnt[0].y, dot.z - pnt[0].z};
	vec[1] = (t_vec){pnt[1].x - pnt[0].x, pnt[1].y - pnt[0].y, pnt[1].z -
	pnt[0].z};
	ded[0] = vector_cross(&vec[0], &vec[1]);
	norm_vec(&ded[0]);
	ded[1] = (t_vec){-ded[0].x, - ded[0].y, -ded[0].z};
	len[0] = length_vector(&(t_vec){dot.x - ded[0].x, dot.y - ded[0].y,
								  dot.z - ded[0].z});
	len[1] = length_vector(&(t_vec){dot.x - ded[1].x, dot.y - ded[1].y,
								  dot.z - ded[1].z});
	return (len[0] > len[1] ? ded[0] : ded[1]);
}