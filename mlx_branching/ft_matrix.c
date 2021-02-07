#include "minirt.h"

void				matrix_rellocation(t_matrix *location, t_rt *scene, int c)
{
	location->vec = alloc_vector(scene->cam[c]->x, scene->cam[c]->y,
								 scene->cam[c]->z);
}