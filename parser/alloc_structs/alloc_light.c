#include "minirt.h"

void		alloc_light(t_count *c, t_rt *scene)
{
	int		i;

	i = 0;
	if (!(scene->light = (t_light **)malloc(sizeof(t_light *) * (c->light + 1))))
		errors_and_exit(9, scene);
	scene->light[c->light] = NULL;
	while (i != c->light)
		if (!(scene->light[i++] = malloc(sizeof(t_light))))
			errors_and_exit(9, scene);
}