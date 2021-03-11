#include "minirt.h"
#include <stdio.h>

double intersect_sphere(t_vec vec[2], t_sp *sp)
{
	double	k[4];
	double	discriminant;
	double	distance[3];
	t_vec	sp_center;

	k[1] = 0.99999999;
	sp_center = vec_subt(vec[1], (t_vec){sp->x, sp->y, sp->z});
	if (vec[1].x != 4)
		vec->x = vec->x;
	k[2] = 2 * scalar_product(&sp_center, &vec[0], 3);
	k[3] = scalar_product(&sp_center, &sp_center, 3) - pow(sp->diameter / 2, 2);
	discriminant = pow(k[2], 2) - (4 * k[1] * k[3]);
	if (discriminant >= 0)
	{
		distance[1] = (-k[2] - sqrt(discriminant)) / 2;
		distance[2] = (-k[2] + sqrt(discriminant)) / 2;
		if (distance[1] < 0 && distance[2] > 0)
			return (distance[2]);
		else if (distance[1] > 0 )
			return (distance[1]);
	}
	return (INFINITY);
}

t_dist check_len_triangle(t_vec vec[2], t_rt *scene, t_dist *tmp)
{
	t_dist		first;

	first = comparison_triangle(vec, scene);
	if (first.distance < tmp->distance)
	{
		tmp->distance = first.distance;
		tmp->fig_index = first.fig_index;
		tmp->index = 5;
	}

	return (*tmp);
}

t_dist check_len_cylinder(t_vec *vec, t_rt *scene, t_dist *tmp)
{
	t_dist		first;
	t_dist		second;
	t_dist		self_tmp;

	self_tmp.fig_index = 0;
	self_tmp.index = 0;
	self_tmp.distance = 0;
	first = comparison_squares(vec, scene);
	second = comparison_cylinder(vec, scene);
	if (first.distance < second.distance && isnormal(first.distance))
	{
		self_tmp.distance = first.distance;
		self_tmp.index = 3;
		self_tmp.fig_index = first.fig_index;
	}
	else if (isnormal(second.distance))
	{
		self_tmp.distance = second.distance;
 		self_tmp.index = 4;
		self_tmp.fig_index = second.fig_index;
	}
	if (tmp->distance > self_tmp.distance && isnormal(self_tmp.distance))
		return (check_len_triangle(vec, scene, &self_tmp));
	return (check_len_triangle(vec, scene, tmp));
}

t_dist check_len_figures(t_vec vec[2], t_rt *scene)
{
	t_dist 		first;
	t_dist 		second;
	t_dist 		tmp;

	tmp.index = 0;
	tmp.fig_index = -1;
	tmp.distance = INFINITY;
	first = comparison_spheres(vec, scene);
	second = comparison_planes(vec, scene);

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
	return (check_len_cylinder(vec, scene, &tmp));
}

int intersect(t_vec vec[2], t_rt *scene)
{
	t_dist		args;
	t_vec 		color;

	args = check_len_figures(vec, scene);
	args.distance *= 0.999999999;
	color = color_light_branching(args, scene, vec);
	return (vec_to_int_color(color, 1));
}