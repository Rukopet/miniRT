#include "minirt.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

t_vec summ_colors(t_vec color1, t_vec color, t_vec color2)
{
		color1 = (t_vec){color1.x + color2.x,
						 color1.y + color2.y,
						 color1.z + color2.z};
		return (color1);
}

t_vec			get_color_after_normal(t_vec *color, t_vec coof, int i)
{
	t_vec		tmp;

	i = (i == 0) ? 1 : i;
	tmp = (t_vec){color->x / i * coof.x,
			color->y / i * coof.y,
			color->z / i * coof.z};
	return (tmp);
}

t_vec			coof_color_after_normal(t_vec *a_vec, t_rt *scene, t_vec *matrix,
							 t_dist tmp_args, t_light *l) {
	t_vec *tmp;
	t_vec ret;
	t_vec normal;
	t_vec light;
	double com;
	double len_l;
	double len_n;

	ret = (t_vec){0, 0, 0};
	tmp = product_vec_and_int(a_vec, tmp_args.distance, 0);
	normal = (t_vec){.x = tmp->x - (scene->sp[tmp_args.fig_index]->x -
	scene->d->vec_matrix->x), .y = tmp->y -(scene->sp[tmp_args.fig_index]->y -
	scene->d->vec_matrix->y), .z = tmp->z - (scene->sp[tmp_args.fig_index]->z -
	scene->d->vec_matrix->z)};
	light = (t_vec) {l->x - scene->sp[tmp_args.fig_index]->x - tmp->x,
					l->y - scene->sp[tmp_args.fig_index]->y - tmp->y,
					l->z - scene->sp[tmp_args.fig_index]->z - tmp->z};
	com = normal_vector(&light, &normal) * 0.9;
	if (com > 0.0)
	{
		ret = (t_vec){l->r / 255.0 * (l->b_rate) * com,
					  l->g / 255.0 * (l->b_rate) * com,
					  l->b / 255.0 * (l->b_rate) * com};
	norm_vec(&normal);
	}


	free(tmp);

	return (ret);
}

t_vec vec_to_light(t_vec color[2], t_rt *scene, t_vec *vec, t_dist args)
{
	t_vec 		coof;
	t_vec 		*coor_tr;
	t_dist 		tmp_args;
	t_vec		t_beg;
	t_vec		*t_mtx;
	t_vec		*light;
	t_vec		d_vec[2];
	int 		i;

	tmp_args = args;
	coof = (t_vec){color->x, color->y, color->z};
	coor_tr = product_vec_and_int(vec, args.distance, 0);
	i = -1;
	t_mtx = alloc_vector(scene->d->vec_matrix->x + coor_tr->x,
	scene->d->vec_matrix->y + coor_tr->y, scene->d->vec_matrix->z + coor_tr->z);
	while (scene->light[++i] != NULL)
	{
		t_beg = (t_vec){.x = scene->light[i]->x - t_mtx->x, .y =
		scene->light[i]->y - t_mtx->y, .z = scene->light[i]->z - t_mtx->z};
		norm_vec(light = alloc_vector(t_beg.x, t_beg.y, t_beg.z));
		args = check_len_figures(light, scene, coor_tr);
		*d_vec = (t_vec){.x = vec->x, .y = vec->y, .z = vec->z};
		*(d_vec + 1) = (t_vec){.x = light->x, .y = light->y, .z = light->z};
		if (isinf(args.distance) == 0)
			continue;
//		{
			coof = summ_colors(coof, *color, coof_color_after_normal
			(d_vec,	scene, t_mtx, tmp_args, scene->light[i]));
//		}
//		else
//			return (summ_colors(color[1], (t_vec){0}, color[0]));
	}
	free(t_mtx);
	t_mtx = NULL;
	return (get_color_after_normal(color + 1, coof, i));
}