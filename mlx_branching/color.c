#include "minirt.h"

void vec_to_light(t_vec **color, t_rt *scene, t_vec *vec, t_dist args)
{
	t_vec 		*coords_tr;
	t_vec		*tmp_begin;
	t_vec		*tmp_matrix;
	t_vec		*norm_light;
	int 		i;

	tmp_matrix = scene->d->vec_matrix;
	coords_tr = product_vec_and_int(vec, args.distance, 0);
	i = -1;
	tmp_begin = alloc_vector(0, 0, 0);
	scene->d->vec_matrix = alloc_vector(coords_tr->x + tmp_matrix->x,
		coords_tr->y + tmp_matrix->y, coords_tr->z  + tmp_matrix->z);
	while (scene->light[++i] != NULL)
	{
		tmp_begin->x = scene->light[i]->x - scene->d->vec_matrix->x;
		tmp_begin->y = scene->light[i]->y - scene->d->vec_matrix->y;
		tmp_begin->z = scene->light[i]->z - scene->d->vec_matrix->z;
		norm_light = alloc_vector(tmp_begin->x, tmp_begin->y, tmp_begin->z);
		norm_vec(norm_light);
		args = check_len_figures(norm_light, scene, coords_tr);
		if (isinf(args.distance))
		{
			(*color)->x = 255;
			(*color)->y = 255;
			(*color)->z = 255;
		}
	}
	free(scene->d->vec_matrix);
	scene->d->vec_matrix = tmp_matrix;
	free(tmp_begin);
	tmp_begin = NULL;
	tmp_matrix = NULL;
}