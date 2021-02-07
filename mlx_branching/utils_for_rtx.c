#include "minirt.h"

int 			check_max_cams(t_rt *scene)
{
	int			i;

	i = 0;
	while (scene->cam[i] != NULL)
	{
		i++;
	}
	return (i);
}