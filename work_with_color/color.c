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
	double 		c;
	double 		ch;

	i = (i == 0) ? 1 : i;
	c = 0.3;
	ch = c * i;
	tmp = (t_vec){color->x  * (coof.x),
			color->y * (coof.y),
			color->z * (coof.z)};
	return (tmp);
}

t_vec coof_color_after_normal(t_vec a_vec[5], t_rt *scene, t_dist tmp_args,
							  t_light *l)
{
	t_vec *tmp;
	t_vec ret;
	t_vec n_l[2];
 	double com;

	ret = (t_vec){0, 0, 0};
	tmp = product_vec_and_int(a_vec, tmp_args.distance, 0);
	n_l[0] = take_normal_from_obj(tmp_args, scene, tmp, a_vec);
	norm_vec(&n_l[0]);
	n_l[1] = take_light_to_color(l, tmp, scene, tmp_args);
	norm_vec(&n_l[1]);
	com = normal_vector(&n_l[1], &n_l[0]);
//	com = normal_vector(&n_l[1], &n_l[0]) * 0.9;
	if (com > 0)
	{
		ret = (t_vec){l->r / 255.0 * (l->b_rate * com),
					  l->g / 255.0 * (l->b_rate * com),
					  l->b / 255.0 * (l->b_rate * com)};
	}
	free(tmp);
	return (ret);
}

static void init_values(t_vec *value[3], t_vec color[2], t_rt *sc, t_dist args)
{

}

t_vec vec_to_light(t_vec color[2], t_rt *scene, t_vec vec[2], t_dist args)
{
	t_dist 		tmp_args;
	t_vec		t_beg;
	t_vec		light[2];
	t_vec		d_vec[5];
	int 		i;

	//d_vec[3] coof
	//d_vec[4] coor_tr
	//d_vec[5] loght
	tmp_args = (t_dist){args.index, args.fig_index, args.distance, args.dist2};
	d_vec[3] = (t_vec){color->x, color->y, color->z};
	d_vec[4] = vec_multi((t_vec){vec->x, vec->y, vec->z},
					  args.distance);
	i = -1;
	light[1] = (t_vec){scene->d->vec_matrix->x + d_vec[4].x,
	scene->d->vec_matrix->y + d_vec[4].y, scene->d->vec_matrix->z + d_vec[4].z};
	while (scene->light[++i] != NULL)
	{
		t_beg = (t_vec){scene->light[i]->x - light[1].x,
		scene->light[i]->y - light[1].y,scene->light[i]->z - light[1].z};
		light[0] = (t_vec){t_beg.x,t_beg.y,t_beg.z};
		norm_vec(&light[0]);
		args = check_len_figures(light, scene, &d_vec[4]);
		*d_vec = (t_vec){.x = vec->x, .y = vec->y, .z = vec->z};
		*(d_vec + 1) = (t_vec){.x = light[0].x, .y = light[0].y, .z =
		light[0].z};
		if (isinf(args.distance) == 0)
			continue;
		d_vec[3] = summ_colors(d_vec[3], *color, coof_color_after_normal
				(d_vec, scene, tmp_args, scene->light[i]));
	}
	return (get_color_after_normal(color + 1, d_vec[3], i));
}

