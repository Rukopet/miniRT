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

	ret = radians * 180 / M_PI;
	return (ret);
}

double 			degress_to_radians(double degrees)
{
	double		ret;

	ret = degrees * (M_PI / 180);
	return (ret);
}

void 			init_dots(t_rt *scene)
{
	t_data_dots *dot;

	if (!(dot = malloc(sizeof(t_data_dots))))
		errors_and_exit(-1, scene);
	dot->first_dot = NULL;
	if (scene->d)
		scene->d->dots = dot;
}