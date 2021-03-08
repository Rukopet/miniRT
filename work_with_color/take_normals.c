#include "minirt.h"

t_vec take_normal_cylinder(t_vec p, t_cy *cy, t_rt *sc, t_vec *vec)
{
	t_vec		norm;
	t_vec		p_dir;
	double 		tmp[2];

	tmp[0] = vec_scal(vec_subt((t_vec){cy->x, cy->y, cy->z}, p), (t_vec)
	{cy->vec_x, cy->vec_y, cy->vec_z});
	norm = vec_multi((t_vec){cy->vec_x, cy->vec_y, cy->vec_z}, tmp[0]);
	norm = vec_subt(vec_subt((t_vec){cy->x, cy->y, cy->z}, p), norm);
	norm_vec(&norm);
	tmp[1] = vec_scal((t_vec){-vec->x, -vec->y, -vec->z}, norm);
	if (vec_scal(norm, (t_vec){-vec->x, -vec->y, -vec->z}) != 0)
	{
		p_dir = vec_multi(norm, tmp[1]);
		norm_vec(&p_dir);
		return (p_dir);
	}
//	check = vec_multi(norm, MINIMUM);
	return (norm);
//	return ((t_vec){-norm.x, -norm.y, -norm.z});
}