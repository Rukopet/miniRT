#include "minirt.h"

t_vec			vec_subt(t_vec vec1, t_vec vec2)
{
	return ((t_vec){vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z});
}

double			vec_scal(t_vec vec1, t_vec vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vec			vec_multi(t_vec vec, double dist)
{
	return ((t_vec){vec.x * dist, vec.y * dist, vec.z * dist});
}