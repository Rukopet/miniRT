#include "minirt.h"

t_dist comparison_spheres(t_vec vec[2], t_rt *scene)
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
			tmp = intersect_sphere(vec, scene->sp[i]);
			if (i == 0 || tmp < dist.distance)
			{
				dist.distance = tmp;
				dist.fig_index = i;
			}
		}
	}

	return (dist);
}

t_dist comparison_planes(t_vec vec[2], t_rt *scene)
{
	t_dist		dist;
	int 		i;
	double 		tmp;

	i = -1;
	dist.distance = INFINITY;
	if (scene->pl)
		while (scene->pl[++i] != NULL)
		{
			tmp = intersect_plane(vec, scene->pl[i]);
			if (i == 0 || tmp < dist.distance)
			{
				dist.distance = tmp;
				dist.fig_index = i;
			}
		}
	return (dist);
}

t_dist comparison_squares(t_vec vec[2], t_rt *scene)
{
	t_dist		dist;
	int 		i;
	double 		tmp;

	i = -1;
	dist.distance = INFINITY;
	if (scene->sq)
		while (scene->sq[++i] != NULL)
		{
			tmp = intersect_square(vec, scene->sq[i]);
			if (i == 0 || tmp < dist.distance)
			{
				dist.distance = tmp;
				dist.fig_index = i;
			}
		}
	return (dist);
}

t_dist comparison_cylinder(t_vec vec[2], t_rt *scene)
{
	t_dist		dist;
	int 		i;
	t_d			tmp;
	double 		check;

	i = -1;
	dist.distance = INFINITY;
	if (scene->cy)
		while (scene->cy[++i] != NULL)
		{
			tmp = intersect_cylinder(vec, scene->cy[i], &dist);
			if (isinf(tmp.d1) && isinf(tmp.d2))
				continue;
			else if (tmp.d1 < tmp.d2 && isnormal(tmp.d1))
				check = tmp.d1;
			else
			{
				check = tmp.d2;
			}

			if (i == 0 || check < dist.distance)
			{
				dist.distance = check;
				dist.fig_index = i;
			}
		}
	return (dist);
}

t_dist comparison_triangle(t_vec vec[2], t_rt *scene)
{
	t_dist		dist;
	int 		i;
	double		tmp;

	i = -1;
	dist.distance = INFINITY;
	if (scene->tr)
		while (scene->tr[++i] != NULL)
		{
			tmp = intersect_triangle(vec, scene->tr[i]);
			if ((i == 0 || tmp < dist.distance) && isnormal(tmp))
			{
				dist.distance = tmp;
				dist.fig_index = i;
			}
		}
	return (dist);
}