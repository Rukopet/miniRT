#include "minirt.h"

t_vec *color_light_branching(t_dist args, t_rt *scene, t_vec *vec)
{
	t_vec		*color;
//	t_vec		*color_al;

	if (isinf(args.distance) && scene->a_light)
		return (alloc_vector(scene->a_light->r / 3 *
		scene->a_light->bright_rate,
					   scene->a_light->g / 3 * scene->a_light->bright_rate,
					   scene->a_light->b / 2 * scene->a_light->bright_rate));
	if (args.index == 1)
	{
		color = alloc_vector(scene->sp[args.fig_index]->r, scene->sp[args
		.fig_index]->g, scene->sp[args.fig_index]->b);
		color->x = color->x / 255 * scene->a_light->r;
		color->y = color->y / 255 * scene->a_light->g;
		color->z = color->z / 255 * scene->a_light->b;
//		check_overcolor(color);
//		vec_to_light(&color, scene, vec, args);
		return (color);
	}
	return (NULL);
	//chech it
}