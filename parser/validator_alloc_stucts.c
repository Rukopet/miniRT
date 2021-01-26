#include "minirt.h"
#include "libft.h"

int			alloc_structs(t_count *c, t_rt *scene)
{
	int		i;

	i = 0;
	if (!(scene->resolution = malloc(sizeof(t_res) * c->resolution)))
		return (0);
	if (c->a_light != 0)
		if (!(scene->a_light = malloc(sizeof(t_al) * c->a_light)))
			return (0);
	if (c->cam != 0)
	{
		if (!(scene->cam = (t_cam**)malloc(sizeof(t_cam *) * (c->cam + 1))))
			return (0);
		scene->cam[c->cam] = NULL;
		while (scene->cam[i] != NULL)
			if (!(scene->cam[i] = malloc(sizeof(t_cam))))
				return (0);
	}

	return (1);
}
int			count_validate(t_count *counter, t_rt *scene)
{
	if (counter->resolution >= 2)
	{
		write (2, "Error\nMultiplae resolution options\n", 36);
		return (0);
	}
	if (counter->a_light >= 2)
	{
		write (2, "Error\nMultiplae ambient light options\n", 39);
		return (0);
	}
	return (alloc_structs(counter, scene));
}