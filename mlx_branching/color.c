#include "minirt.h"

void vec_to_light(t_vec **color, t_rt *scene, t_vec *vec, t_dist args)
{
	t_vec 		*coords_tr;
	t_vec		*tmp_begin;
	int 		i;

	coords_tr = product_vec_and_int(vec, args.distance, 0);
	i = -1;
	tmp_begin = alloc_vector(0, 0, 0);
	while (scene->light[++i] != NULL)
	{
		tmp_begin->x = scene->light[i]->x;
		tmp_begin->y = scene->light[i]->y;
		tmp_begin->z = scene->light[i]->z;
//		args = check_len_figures();
	}
	free(tmp_begin);
	tmp_begin = NULL;
}