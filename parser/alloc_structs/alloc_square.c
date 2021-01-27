#include "minirt.h"

void		alloc_square(t_count *c, t_rt *scene)
{
	int		i;

	i = 0;
	if (!(scene->sq = (t_sq **)malloc(sizeof(t_sq *) * (c->sq + 1))))
		erros_and_exit(9, scene);
	scene->sq[c->sq] = NULL;
	while (i != c->sq)
		if (!(scene->sq[i++] = malloc(sizeof(t_sq))))
			erros_and_exit(9, scene);
}