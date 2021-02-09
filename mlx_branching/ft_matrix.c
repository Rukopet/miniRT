#include "minirt.h"

void				matrix_rellocation(t_rt *scene, int c)
{
	if (scene->d)
	{
		scene->d->vec_matrix = alloc_vector(scene->cam[c]->x, scene->cam[c]->y,
										   scene->cam[c]->z);
	}
}