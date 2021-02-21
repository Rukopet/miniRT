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

t_vec			get_color_after_normal(t_vec *color, t_vec coof)
{
	t_vec		tmp;

	tmp = (t_vec){color->x * coof.x,
			color->y * coof.y,
			color->z * coof.z};
	return (tmp);
}

t_vec			coof_color_after_normal(t_vec *a_vec, t_rt *scene, t_vec *matrix,
							 t_dist tmp_args, t_light *l)
{
	t_vec		*tmp;
	t_vec		ret;
	t_vec		normal;
	double 		com;
	double 		len_l;
	double 		len_n;

	tmp = product_vec_and_int(a_vec, tmp_args.distance, 0);
	normal = (t_vec){.x = tmp->x - scene->sp[tmp_args.fig_index]->x,
			.y = tmp->y - scene->sp[tmp_args.fig_index]->y,
			.z = tmp->z - scene->sp[tmp_args.fig_index]->z};
	norm_vec(&normal);
	com = normal_vector(&normal, a_vec) * 1.2;
//	com = (com < 0) ? com * -1 : com;
	ret = (t_vec){l->r / 255.0 * (1 + l->b_rate) * com,
			   l->g / 255.0 * (1 + l->b_rate) * com,
			   l->b / 255.0 * (1 + l->b_rate) * com};
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
	coof = (t_vec){color[1].x, color[1].y, color[1].z};
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
		if (isinf(args.distance) != 0)
		{
			coof = summ_colors(coof, *color, coof_color_after_normal
					(d_vec,	scene, t_mtx, tmp_args, scene->light[i]));
		}
		else
			return (summ_colors(color[1], (t_vec){0}, color[0]));
	}
	free(t_mtx);
	t_mtx = NULL;
	return (get_color_after_normal(color + 1, coof));
}