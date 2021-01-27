#include "minirt.h"

void		alloc_sphere(t_count *c, t_rt *scene)
{
	int		i;

	i = 0;
	if (!(scene->sp = (t_sp **)malloc(sizeof(t_sp *) * (c->sp + 1))))
		erros_and_exit(9, scene);
	scene->sp[c->sp] = NULL;
	while (i != c->sp)
		if (!(scene->sp[i++] = malloc(sizeof(t_sp))))
			erros_and_exit(9, scene);
}