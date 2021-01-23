#include "minirt.h"

void		free_struct(void **s)
{
	while (s != NULL)
	{
		free(*s);
		*s = NULL;
		s++;
	}
	free(s);
	s = NULL;
}

void		free_res_al(void *s)
{
	free(s);
	s = NULL;
}
int			free_scene(t_rt *s, int flag)
{
	if (NULL != s->resolution)
		free_res_al(s->resolution);
	if (NULL != s->a_light)
		free_res_al(s->a_light);
	if (NULL != s->cam)
		free_struct(s->cam);
	if (NULL != s->light)
		free_struct(s->light);
	if (NULL != s->sp)
		free_struct(s->sp);
	if (NULL != s->pl)
		free_struct(s->pl);
	if (NULL != s->sq)
		free_struct(s->sq);
	if (NULL != s->cy)
		free_struct(s->cy);
	if (NULL != s->tr)
		free_struct(s->tr);
	if (flag == 0)
		return (0);
	return (1);
}