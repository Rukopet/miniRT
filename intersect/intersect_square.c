#include "minirt.h"
#include <stdio.h>

static double check_plane(t_sq *sq, t_vec *vec)
{
	t_pl		tmp;
	double		dist;

	tmp = (t_pl){.x = sq->x, .y = sq->y,
			  .z =  sq->z, .vec_x = sq->vec_x,
			  .vec_y = sq->vec_y, .vec_z = sq->vec_z};
	dist = intersect_plane(vec, &tmp);
	if (isnormal(dist) && (dist > MINIMUM))
		return (dist);
	return (INFINITY);
}

static int check_borders(t_vec tmp[4], t_sq *sq)
{
	double 		p;
	double 		up;
	t_vec		check;

	check = vec_subt(tmp[3], (t_vec){sq->x, sq->y, sq->z});
	p = vec_scal(check, tmp[0]);
	up = vec_scal(check, tmp[1]);
	if ((fabs(p) <= sq->side_size / 2.0) && (fabs(up) <= sq->side_size / 2.0))
		return (1);
	return (0);
}

double intersect_square(t_vec vec[2], t_sq *sq)
{
	t_vec		tmp[4];
	double 		dist;

	tmp[2] = (sq->vec_y == 1) ? (t_vec){0, 0, 1} : (t_vec){0, 1, 0};
	tmp[2] = (sq->vec_y == -1) ? (t_vec){0, 0, 1} : tmp[2];
	tmp[0] = vector_cross(&(t_vec){sq->vec_x, sq->vec_y, sq->vec_z}, &tmp[2]);
	norm_vec(&tmp[0]);
	tmp[1] = vector_cross(&(t_vec){sq->vec_x, sq->vec_y, sq->vec_z}, &tmp[0]);
	norm_vec(&tmp[1]);
	dist = check_plane(sq, vec);
	if (isnormal(dist))
	{
		tmp[3] = vec_multi(vec[0], dist);
		tmp[3] = (t_vec){vec[1].x + tmp[3].x, vec[1].y + tmp[3].y, tmp[1].z +
		tmp[3].z};
		if (check_borders(tmp, sq))
			return (dist);
	}
	return (INFINITY);
}