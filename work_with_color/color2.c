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

t_vec	take_normal_from_obj(t_dist args, t_rt *scene, t_vec *tmp, t_vec
vec[5])
{
	t_vec normal;

	if (args.index == 1)
		normal = (t_vec){tmp->x - (scene->sp[args.fig_index]->x -
		scene->d->vec_matrix->x), tmp->y - (scene->sp[args.fig_index]->y -
		scene->d->vec_matrix->y), tmp->z - (scene->sp[args.fig_index]->z -
		scene->d->vec_matrix->z)};
	if (args.index == 2)
		normal = take_plane_normal((t_vec){vec->x * args.distance, vec->y *
		args.distance, vec->z * args.distance}, scene->pl[args.fig_index]);
	if (args.index == 3)
		normal = take_square_normal((t_vec){vec->x * args.distance, vec->y *
		args.distance, vec->z * args.distance}, scene->sq[args.fig_index]);
	if (args.index == 4)
		normal = take_normal_cylinder((t_vec){vec->x * args.distance,
		vec->y * args.distance, vec->z * args.distance},
		scene->cy[args.fig_index], scene, vec);
	if (args.index == 5)
		normal = take_triangle_normal(scene->tr[args.fig_index], (t_vec){vec->x *
		args.distance, vec->y * args.distance, vec->z * args.distance});
	return (normal);
}

t_vec	take_light_to_color(t_light *l, t_vec *tmp, t_rt *scene, t_dist args)
{
	t_vec		light;

	if (args.index == 1)
		light = (t_vec){l->x - (scene->sp[args.fig_index]->x -
		tmp->x), l->y - (scene->sp[args.fig_index]->y -
		tmp->y), l->z - (scene->sp[args.fig_index]->z - tmp->z)};
	if (args.index == 2)
		light = (t_vec){l->x - (scene->pl[args.fig_index]->x -
		tmp->x), l->y - (scene->pl[args.fig_index]->y -
		tmp->y), l->z - (scene->pl[args.fig_index]->z - tmp->z)};
	if (args.index == 3)
		light = (t_vec){l->x - (scene->sq[args.fig_index]->x -
		tmp->x), l->y - (scene->sq[args.fig_index]->y -
		tmp->y), l->z - (scene->sq[args.fig_index]->z - tmp->z)};
	if (args.index == 4)
		light = (t_vec){l->x - (scene->cy[args.fig_index]->x -
		tmp->x), l->y - (scene->cy[args.fig_index]->y -
		tmp->y), l->z - (scene->cy[args.fig_index]->z - tmp->z)};
	if (args.index == 5)
		light = (t_vec){l->x - (scene->tr[args.fig_index]->first_x -
		tmp->x), l->y - (scene->tr[args.fig_index]->first_y -
		tmp->y), l->z - (scene->tr[args.fig_index]->first_z - tmp->z)};
	return (light);
}