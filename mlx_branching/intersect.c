#include "minirt.h"
#include <stdio.h>
double intersect_sphere(t_vec *vec, t_sp *sp, t_rt *scene)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	distance_1;
	double	distance_2;
	t_vec	*sp_center;
	t_vec	*cam_sp;
//	sp_center = vector_deduction(alloc_vector(sp->x, sp->y, sp->z),
//								 scene->d->vec_matrix, 1);
	a = 1;
	sp_center = alloc_vector(sp->x, sp->y, sp->z);
	b = 2 * scalar_product(sp_center, vec, 3);
	c = scalar_product(sp_center, sp_center, 3) - pow(sp->diameter / 2, 2);
	if (0 > (discriminant = b * b - 4 * a * c))
	{
		distance_1 = -1 * b - sqrt(discriminant) / (2 * a);
		return (distance_1);
	}
	else
	{
		return (discriminant);
	}
//	distance_2 = -1 * b + sqrt(discriminant) / (2 * a);
	return (-1);
}
t_dist			check_len_triangle(t_vec *vec, t_rt *scene, t_dist tmp)
{
	t_dist		first;

	first = comparison_triangle(vec, scene);
	if (first.distance < tmp.distance)
	{

	}
	return (tmp);
}

t_dist			check_len_cylinder(t_vec*vec, t_rt *scene, t_dist tmp)
{
	t_dist		first;
	t_dist		second;
	t_dist		self_tmp;

	self_tmp.fig_index = -1;
	first = comparison_squares(vec, scene);
	second = comparison_cylinder(vec, scene);
	if ((first.distance != -1 && first.distance) < (second.distance || second
	.distance == -1))
	{
		self_tmp.distance = first.distance;
		self_tmp.index = 3;
		self_tmp.fig_index = first.fig_index;
	}
	else if (second.distance != -1)
	{
		self_tmp.distance = second.distance;
		self_tmp.index = 4;
		self_tmp.fig_index = second.fig_index;
	}
	if (tmp.distance > self_tmp.distance)
		tmp = self_tmp;
	return (check_len_triangle(vec, scene,tmp));
}

t_dist			check_len_figures(t_vec* vec, t_rt *scene)
{
	t_dist 		first;
	t_dist 		second;
	t_dist 		tmp;

	tmp.index = 0;
	tmp.fig_index = -1;
	first = comparison_spheres(vec, scene);
	second = comparison_planes(vec, scene);
	if (first.distance < second.distance)
	{
		tmp.distance = first.distance;
		tmp.index = 1;
		tmp.fig_index = first.fig_index;
	}
	else if (second.distance != -1)
	{
		tmp.distance = second.distance;
		tmp.index = 2;
		tmp.fig_index = second.fig_index;
	}
	return (check_len_cylinder(vec, scene, tmp));
}

int intersect(t_vec *vec, t_rt *scene)
{
	double		sp_distnce;
	double 		close_distance;
	double 		tmp;
	t_dist		args;

	/*
	** 1 sp close;
	** 2
	*/

	args = check_len_figures(vec, scene);
}