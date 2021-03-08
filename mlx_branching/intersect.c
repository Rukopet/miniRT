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

	a = 0.998;
	sp_center = alloc_vector((sp->x - start->x),
	(sp->y - start->y),(sp->z - start->z));
	b = 2 * scalar_product(sp_center, vec, 3);
	c = scalar_product(sp_center, sp_center, 3) - pow(sp->diameter / 2, 2);
//	free(sp_center);
//	sp_center = NULL;
	discriminant = pow(b, 2) - (4 * a * c);
	if (discriminant >= 0)
	{
		distance_1 = (-b - sqrt(discriminant)) / 2;
		distance_2 = (-b + sqrt(discriminant)) / 2;
		if (distance_1 < 0)
		{
			distance_1 = (distance_2 > distance_1) ? distance_2 : distance_1;
			return (fabs(distance_1));
		}

	}
	return (INFINITY);
}

t_dist check_len_triangle(t_vec *vec, t_rt *scene, t_dist *tmp, t_vec *start)
{
	t_dist		first;

	first = comparison_triangle(vec, scene, start);
	if (first.distance < tmp->distance)
	{
		tmp->distance = first.distance;
		tmp->fig_index = first.fig_index;
		tmp->index = 5;
	}

	return (*tmp);
}

t_dist check_len_cylinder(t_vec *vec, t_rt *scene, t_dist *tmp, t_vec *start)
{
	t_dist		first;
	t_dist		second;
	t_dist		self_tmp;

	self_tmp.fig_index = 0;
	self_tmp.index = 0;
	self_tmp.distance = 0;
	first = comparison_squares(vec, scene, start);
	second = comparison_cylinder(vec, scene, start);
	if (first.distance < second.distance && isnormal(first.distance))
	{
		self_tmp.distance = first.distance;
		self_tmp.index = 3;
		self_tmp.fig_index = first.fig_index;
	}
	else if (!isinf(second.distance) && second.fig_index != -1)
	{
		self_tmp.distance = second.distance;
 		self_tmp.index = 4;
		self_tmp.fig_index = second.fig_index;
	}
	if (tmp->distance > self_tmp.distance && isnormal(self_tmp.distance))
		return (check_len_triangle(vec, scene, &self_tmp, NULL));
	return (check_len_triangle(vec, scene, tmp, NULL));
}

t_dist check_len_figures(t_vec vec[2], t_rt *scene, t_vec *start)
{
	t_dist 		first;
	t_dist 		second;
	t_dist 		tmp;

	tmp.index = 0;
	tmp.fig_index = -1;
	tmp.distance = INFINITY;
	first = comparison_spheres(vec, scene, start);
	second = comparison_planes(vec, scene, start);

	if (first.distance < second.distance && isnormal(first.distance))
	{
		tmp.distance = first.distance;
		tmp.index = 1;
		tmp.fig_index = first.fig_index;
	}
	else if (isnormal(second.distance))
	{
		tmp.distance = second.distance;
		tmp.index = 2;
		tmp.fig_index = second.fig_index;
	}
	return (check_len_cylinder(vec, scene, &tmp, start));
}

int intersect(t_vec vec[2], t_rt *scene)
{
	t_dist		args;
	t_vec 		color;

	args = check_len_figures(vec, scene, scene->d->vec_matrix);
//	if (args.index == 4)
//		return (vec_to_int_color((t_vec){255, 100, 0}, 0));

	color = color_light_branching(args, scene, vec);
	return (vec_to_int_color(color, 1));
}