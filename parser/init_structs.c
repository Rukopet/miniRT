#include "minirt.h"

// t_count			*solve_count(char *names, t_count *c)
// {

// }
int			*init_count_struct(t_count *counter)
{
	counter->resolution = 0;
	counter->a_light = 0;
	counter->cam = 0;
	counter->light = 0;
	counter->sp = 0;
	counter->pl = 0;
	counter->sq = 0;
	counter->cy = 0;
	counter->tr = 0;
	return (1);
}