#include "minirt.h"

void 				alloc_inside_figures_three(t_rt *scene, t_figures *fig)
{
	int 			len;

	len = scene->counter->tr;
	if (len > 0)
	{
		if (!(fig->tr = malloc(sizeof(t_cy*) * (len + 1))))
			errors_and_exit(-1, scene);
		fig->tr[len] = NULL;
	}
	else
		fig->tr = NULL;
}

void 				alloc_inside_figures_two(t_rt *scene, t_figures *fig)
{
	int 			len;

	len = scene->counter->sq;
	if (len > 0)
	{
		if (!(fig->sq = malloc(sizeof (t_sq*) + (len + 1))))
			errors_and_exit(-1, scene);
		fig->sq[len] = NULL;
	}
	else
		fig->sq = NULL;
	len = scene->counter->cy;
	if (len > 0)
	{
		if (!(fig->cy = malloc(sizeof(t_cy*) * (len + 1))))
			errors_and_exit(-1, scene);
		fig->cy[len] = NULL;
	}
	else
		fig->cy = NULL;
	alloc_inside_figures_three(scene, fig);
}

void 				alloc_inside_figures_one(t_rt *scene, t_figures *fig)
{
	int 			len;

	len = scene->counter->pl;
	if (len > 0)
	{
		if (!(fig->pl = malloc(sizeof(t_pl*) * (len + 1))))
			errors_and_exit(-1, scene);
		fig->pl[len] = NULL;
	}
	else
		fig->pl = NULL;
	len = scene->counter->sp;
	if (len > 0)
	{
		if (!(fig->sp = malloc(sizeof(t_sp*) * (len + 1))))
			errors_and_exit(-1, scene);
		fig->sp[len] = NULL;
	}
	else
		fig->sp = NULL;
	alloc_inside_figures_two(scene, fig);
}

void				alloc_inside_figures(t_rt *scene, t_figures *fig)
{
	int 			len;

	len = scene->counter->cam;
	if (!(fig->cam = malloc(sizeof(t_cam*) * (len + 1))))
		errors_and_exit(-1, scene);
	fig->cam[len] = NULL;
	len = scene->counter->light;
	if (len > 0)
	{
		if (!(fig->light = malloc(sizeof(t_light*) * (len + 1))))
			errors_and_exit(-1, scene);
		fig->light[len] = NULL;
	}
	else
		fig->light = NULL;
	alloc_inside_figures_one(scene, fig);
}

t_figures			*cp_scene(t_rt* scene)
{
	t_figures		*new;
	int				i;

	i = -1;
	if (!(new = malloc(sizeof(t_figures))))
		errors_and_exit(-1, scene);
	alloc_inside_figures(scene, new);
	alloc_figures(scene, new);
	return (new);
}