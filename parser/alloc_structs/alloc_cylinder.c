#include "minirt.h"

void		alloc_cylinder(t_count *c, t_rt *scene)
{
	int		i;

	i = 0;
	if (!(scene->cy = (t_cy **)malloc(sizeof(t_cy *) * (c->cy + 1))))
		errors_and_exit(9, scene);
	scene->cy[c->cy] = NULL;
	while (i != c->cy)
		if (!(scene->cy[i++] = malloc(sizeof(t_cy))))
			errors_and_exit(9, scene);
}