#include "minirt.h"

t_vec	triangle_light_br(t_dist args, t_rt *scene, t_vec *vec, t_vec color[2])
{
	if (args.index == 5)
	{
		*(color + 1) = (t_vec){scene->tr[args.fig_index]->r,
		scene->tr[args.fig_index]->g, scene->tr[args.fig_index]->b};
		if (scene->light)
			*(color + 1) = vec_to_light(color, scene, vec, args);
		else
			*(color + 1) = (t_vec){color[1].x * color->x,
			color[1].y * color->y, color[1].z * color->z};
	}
	else
		return ((t_vec){0});
	check_overcolor(color + 1);
	return (*(color + 1));
}