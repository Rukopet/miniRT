#include "minirt.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

t_vec			summ_colors(t_vec color1, t_vec color2)
{
	t_vec		ret;

	return (ret);
}
t_vec			get_color_after_normal(t_vec color, double coof)
{
	if (coof != 0)
		color = (t_vec){color.x * coof, color.y * coof, color.z * coof};
	return (color);
}

t_vec			coof_color_after_normal(t_vec *a_vec, t_rt *scene, t_vec *matrix,
							 t_dist tmp_args, t_light *l)
{
	t_vec		*tmp;
	t_vec		ret;
	t_vec		normal;
	double 		com;

	tmp = product_vec_and_int(a_vec, tmp_args.distance, 0);
	normal = (t_vec){.x = tmp->x - scene->sp[tmp_args.fig_index]->x,
			.y = tmp->y - scene->sp[tmp_args.fig_index]->y,
			.z = tmp->z - scene->sp[tmp_args.fig_index]->z};
	norm_vec(&normal);
	com = normal_vector(&normal, a_vec + 1) * l->bright_rate;
	ret = (t_vec){l->r / 255.0 * l->bright_rate};
	free(tmp);
	return ();
}

t_vec vec_to_light(t_vec color, t_rt *scene, t_vec *vec, t_dist args)
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
	coof = 0;
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
		scene->d->color_t = color;
		*d_vec = (t_vec){.x = vec->x, .y = vec->y, .z = vec->z};
		*(d_vec + 1) = (t_vec){.x = light->z, .y = light->y, .z = light->z};
		if (isinf(args.distance) != 0)
		{
			coof = summ_colors(coof, coof_color_after_normal(d_vec,
			scene, t_mtx, tmp_args, scene->light[i]));
//			color = (t_vec){.x = 200, .y = 255, .z = 50};
		}

//			return ((t_vec){.x = 200, .y = 255, .z = 50});

	}
	free(t_mtx);
	t_mtx = NULL;
	return (get_color_after_normal(color, coof));
}