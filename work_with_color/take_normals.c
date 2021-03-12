#include "minirt.h"

t_vec take_normal_cylinder(t_vec p, t_cy *cy, t_dist *args, t_vec *vec)
{
//	t_vec		norm;
//	t_vec		p_dir;
//	double 		tmp[2];
//
//	tmp[0] = vec_scal(vec_subt((t_vec){cy->x, cy->y, cy->z}, p), (t_vec)
//	{cy->vec_x, cy->vec_y, cy->vec_z});
//	norm = vec_multi((t_vec){cy->vec_x, cy->vec_y, cy->vec_z}, tmp[0]);
//	norm = vec_subt(vec_subt((t_vec){cy->x, cy->y, cy->z}, p), norm);
//	norm_vec(&norm);
//	tmp[1] = vec_scal((t_vec){-vec->x, -vec->y, -vec->z}, norm);
//	if (vec_scal(norm, (t_vec){-vec->x, -vec->y, -vec->z}) != 0)
//	{
//		p_dir = vec_multi(norm, tmp[1]);
//		norm_vec(&p_dir);
//		return (p_dir);
//	}
////	check = vec_multi(norm, MINIMUM);
//	return (norm);
////	return ((t_vec){-norm.x, -norm.y, -norm.z});

//	double 		check;
//	t_vec		vn;
//	t_vec		k;
//	t_vec		opp;
//	double		tmp;
//
//	k = (t_vec){p.x + vec[1].x, p.y + vec[1].y, p.z + vec[1].z};
//	check = vec_scal(vec_subt(k, (t_vec){cy->x, cy->y, cy->z}), (t_vec)
//	{cy->vec_x, cy->vec_y, cy->vec_z});
//	vn = vec_multi((t_vec){cy->vec_x, cy->vec_y, cy->vec_z}, check);
//	vn = vec_subt(vec_subt(k, (t_vec){cy->x, cy->y, cy->z}), vn);
//	norm_vec(&vn);
//	opp = (t_vec){-vn.x, -vn.y, -vn.z};
//	tmp = vec_scal(opp, vn);
//	vn = (vec_scal(vn, opp) != 0) ? vec_multi(vn, tmp) : vn;
//	norm_vec(&vn);

	t_vec		vn;
	t_vec		tmp;
	tmp = vec_subt(p, (t_vec){cy->x, cy->y, cy->z});
	vn = vec_multi(*vec, args->quad1);
	vn = vec_subt(tmp, vn);
	norm_vec(&vn);
	if (args->quad1 != INSIDE)
		vn = vec_multi(vn, -1);
	return (vn);
}