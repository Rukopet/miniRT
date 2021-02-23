#include "minirt.h"

int 	vec_to_int_color(t_vec color, int flag_del)
{
	int 		ret;

	ret = (int)color.x << 16 | (int)color.y << 8;
	ret += (int)color.z;
	return (ret);
}

void	check_overcolor(t_vec* tmp)
{
	if (tmp->z >= 255 || tmp->x >= 255 || tmp->y >= 255)
	{

	}
	tmp->x = (tmp->z >= 255) ? 255 : tmp->x;
	tmp->y = (tmp->y >= 255) ? 255 : tmp->y;
	tmp->z = (tmp->z >= 255) ? 255 : tmp->z;
}

t_vec *sum_colors(t_vec *col1, t_vec *col2)
{
	return (alloc_vector((col1->x + col2->x) / 2, (col1->y + col2->y) / 2,
					  (col1->z + col2->z) / 2));
}