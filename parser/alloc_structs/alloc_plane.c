#include "minirt.h"

void		alloc_plane(t_count *c, t_rt *scene)
{
	int		i;

	i = 0;
	if (!(scene->pl = (t_pl **)malloc(sizeof(t_pl *) * (c->pl + 1))))
		errors_and_exit(9, scene);
	scene->pl[c->pl] = NULL;
	while (i != c->pl)
		if (!(scene->pl[i++] = malloc(sizeof(t_pl))))
			errors_and_exit(9, scene);
}