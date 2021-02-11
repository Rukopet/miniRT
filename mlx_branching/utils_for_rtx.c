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

t_cos_sin *alloc_init_cos_sin(t_rt *scene, double degrees)
{
	t_cos_sin 	*tmp;

	if (!(tmp = malloc(sizeof(t_cos_sin))))
		errors_and_exit(-1, scene);
	tmp->cos_c = cos(degress_to_radians(degrees));
	tmp->sin_c = sin(degress_to_radians(degrees));
	return (tmp);
}