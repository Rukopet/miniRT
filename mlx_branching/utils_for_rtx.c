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

double 			radians_to_degrees(double radians)
{
	double 		ret;

	ret = radians * (M_PI / 180);
	return (ret);
}