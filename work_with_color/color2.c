#include "minirt.h"

t_vec	take_plane_normal(t_vec point, t_pl *plane)
{
	t_vec normal1;
	t_vec normal2;
	double len1;
	double len2;

	normal1 = (t_vec){-plane->vec_x, -plane->vec_y, -plane->vec_z};
	normal2 = (t_vec){plane->vec_x, plane->vec_y, plane->vec_z};
	len1 = length_vector(&(t_vec){point.x - normal1.x, point.y - normal1.y,
							   point.z - normal1.z});
	len2 = length_vector(&(t_vec){point.x - normal2.x, point.y - normal2.y,
								  point.z - normal2.z});
	return (len1 < len2 ? normal2 : normal1);
}

t_vec	take_square_normal(t_vec point, t_sq *sq)
{
	t_vec normal1;
	t_vec normal2;
	double len1;
	double len2;

	normal1 = (t_vec){-sq->vec_x, -sq->vec_y, -sq->vec_z};
	normal2 = (t_vec){sq->vec_x, sq->vec_y, sq->vec_z};
	len1 = length_vector(&(t_vec){point.x - normal1.x, point.y - normal1.y,
								  point.z - normal1.z});
	len2 = length_vector(&(t_vec){point.x - normal2.x, point.y - normal2.y,
								  point.z - normal2.z});
	return (len1 > len2 ? normal1 : normal2);
}

t_vec take_normal_from_obj(t_dist args, t_rt *scene, t_vec *tmp, t_vec vec[4])
{
	t_vec normal;

	if (args.index == 1)
		normal = (t_vec){tmp->x - (scene->sp[args.fig_index]->x -
		scene->d->vec_matrix->x), tmp->y - (scene->sp[args.fig_index]->y -
		scene->d->vec_matrix->y), tmp->z - (scene->sp[args.fig_index]->z -
		scene->d->vec_matrix->z)};
	if (args.index == 2)
		normal = take_plane_normal((t_vec){vec->x , vec->y, vec->z},
			scene->pl[args.fig_index]);
	if (args.index == 3)
		normal = take_square_normal((t_vec){vec->x, vec->y, vec->z },
			scene->sq[args.fig_index]);
	if (args.index == 4)
		normal = take_normal_cylinder(vec, scene->cy[args.fig_index],
			&args, vec);
	if (args.index == 5)
		normal = take_triangle_normal(scene->tr[args.fig_index],
			(t_vec){vec->x, vec->y, vec->z});
	return (normal);
}

t_vec	take_light_to_color(t_light *l, t_vec *tmp, t_rt *scene, t_dist args)
{
	t_vec		light;

	if (args.index == 1)
		light = (t_vec){l->x - tmp->x, l->y - tmp->y, l->z - tmp->z};
	if (args.index == 2)
		light = (t_vec){l->x - tmp->x, l->y - tmp->y, l->z - tmp->z};
	if (args.index == 3)
		light = (t_vec){l->x - tmp->x, l->y - tmp->y, l->z - tmp->z};
	if (args.index == 4)
		light = (t_vec){l->x - tmp->x, l->y - tmp->y, l->z - tmp->z};
	if (args.index == 5)
		light = (t_vec){l->x - tmp->x, l->y - tmp->y, l->z - tmp->z};
	return (light);
}