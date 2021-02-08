#include "minirt.h"

void		alloc_triangle(t_count *c, t_rt *scene)
{
	int		i;

	i = 0;
	if (!(scene->tr = (t_tr **)malloc(sizeof(t_tr *) * (c->tr + 1))))
		errors_and_exit(9, scene);
	scene->tr[c->tr] = NULL;
	while (i != c->tr)
		if (!(scene->tr[i++] = malloc(sizeof(t_tr))))
			errors_and_exit(9, scene);
}