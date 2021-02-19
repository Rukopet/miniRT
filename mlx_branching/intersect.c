#include "minirt.h"
#include <stdio.h>

double intersect_sphere(t_vec *vec, t_sp *sp, t_rt *scene, t_vec *start)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	distance_1;
	double 	distance_2;
	t_vec	*sp_center;

	a = 1;
	sp_center = alloc_vector((sp->x - start->x),
	(sp->y - start->y),(sp->z - start->z));
	b = 2 * scalar_product(sp_center, vec, 3);
	c = scalar_product(sp_center, sp_center, 3) - pow(sp->diameter / 2, 2);
	free(sp_center);
	sp_center = NULL;
	discriminant = pow(b, 2) - (4 * a * c);
	if (discriminant < 0)
		return (INFINITY);
	distance_1 = fabs((-b + sqrt(discriminant)) / 2);
	distance_2 = fabs((-b - sqrt(discriminant)) / 2);
	if (distance_1 > MINIMUM && distance_2 > MINIMUM)
		return (distance_1 < distance_2 ? distance_1 : distance_2);
	if (distance_1 > MINIMUM)
		return (distance_1);
	return (distance_2 > MINIMUM ? distance_2 : INFINITY);
}

t_dist check_len_triangle(t_vec *vec, t_rt *scene, t_dist tmp, t_vec *start)
{
	t_dist		first;

	first = comparison_triangle(vec, scene, start);
	if (first.distance < tmp.distance)
	{
		tmp.distance = first.distance;
		tmp.fig_index = first.fig_index;
		tmp.index = 5;
	}
	return (tmp);
}

t_dist check_len_cylinder(t_vec *vec, t_rt *scene, t_dist tmp, t_vec *start)
{
	t_dist		first;
	t_dist		second;
	t_dist		self_tmp;

	self_tmp.fig_index = -1;
	first = comparison_squares(vec, scene, start);
	second = comparison_cylinder(vec, scene, start);
	if (first.distance < second.distance || (isinf(first.distance) && isinf
	(second.distance)))
	{
		self_tmp.distance = first.distance;
		self_tmp.index = 3;
		self_tmp.fig_index = first.fig_index;
	}
	else if (isinf(second.distance))
	{
		self_tmp.distance = second.distance;
		self_tmp.index = 4;
		self_tmp.fig_index = second.fig_index;
	}
	if (tmp.distance > self_tmp.distance)
		tmp = self_tmp;
	return (check_len_triangle(vec, scene, tmp, NULL));
}

t_dist check_len_figures(t_vec *vec, t_rt *scene, t_vec *start)
{
	t_dist 		first;
	t_dist 		second;
	t_dist 		tmp;

	tmp.index = 0;
	tmp.fig_index = -1;
	tmp.distance = INFINITY;
	first = comparison_spheres(vec, scene, start);
	second = comparison_planes(vec, scene, start);
	if (first.distance < second.distance || (isinf(first.distance) && isinf
	(second.distance)))
	{
		tmp.distance = first.distance;
		tmp.index = 1;
		tmp.fig_index = first.fig_index;
	}
	else if (isinf(second.distance))
	{
		tmp.distance = second.distance;
		tmp.index = 2;
		tmp.fig_index = second.fig_index;
	}
	return (check_len_cylinder(vec, scene, tmp, NULL));
}

int intersect(t_vec *vec, t_rt *scene)
{
	t_dist		args;
	t_vec 		color;
//	t_vec		zero;

	/*
	** 1 sp close;
	** 2
	*/

//	zero.x = 0;
//	zero.y = 0;
//	zero.z = 0;

	args = check_len_figures(vec, scene, scene->d->vec_matrix);
	color = color_light_branching(args, scene, vec);
	return (vec_to_int_color(color, 1));
}