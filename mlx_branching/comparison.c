#include "minirt.h"

t_dist comparison_spheres(t_vec *vec, t_rt *scene, t_vec *start)
{
	int 			i;
	t_dist			dist;
	double 			tmp;

	i = -1;
	dist.distance = INFINITY;
	if (scene->sp)
	{
		while (scene->sp[++i] != NULL)
		{
			tmp = intersect_sphere(vec, scene->sp[i], scene, start);
			if (i == 0 || tmp < dist.distance)
			{
				dist.distance = tmp;
				dist.fig_index = i;
			}
		}
	}

	return (dist);
}

t_dist comparison_planes(t_vec *vec, t_rt *scene, t_vec *start)
{
	t_dist		ret;
	int 		i;

	i = -1;
	ret.distance = INFINITY;
	if (scene->pl)
		while (scene->pl[++i] != NULL)
		{
		}
	return (ret);
}

t_dist comparison_squares(t_vec *vec, t_rt *scene, t_vec *start)
{
	t_dist		ret;
	int 		i;

	i = -1;
	ret.distance = INFINITY;
	if (scene->sq)
		while (scene->sq[++i] != NULL)
		{
		}
	return (ret);
}

t_dist comparison_cylinder(t_vec *vec, t_rt *scene, t_vec *start)
{
	t_dist		ret;
	int 		i;

	i = -1;
	ret.distance = INFINITY;
	if (scene->cy)
		while (scene->cy[++i] != NULL)
		{
		}
	return (ret);
}

t_dist comparison_triangle(t_vec *vec, t_rt *scene, t_vec *start)
{
	t_dist		ret;
	int 		i;

	i = -1;
	ret.distance = INFINITY;
	if (scene->tr)
		while (scene->tr[++i] != NULL)
		{
		}
	return (ret);
}