#include "minirt.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

t_vec summ_colors(t_vec color1, t_vec color2)
{
		color1 = (t_vec){color1.x + color2.x,
						 color1.y + color2.y,
						 color1.z + color2.z};
		return (color1);
}

t_vec			get_color_after_normal(t_vec *color, t_vec coof, int i)
{
	double		max;
	double		check;

	check = 1;
	*color = (t_vec){color->x * coof.x,
						color->y * coof.y,
						color->z * coof.z};
	if (color->x > 255 || color->y> 255 || color->z > 255)
	{
		max = fmax(color->x, fmax(color->y, color->z));
		check = 254.0 / max;
	}
	*color = (t_vec){color->x * check, color->y * check, color->z * check};
	return (*color);
}

t_vec coof_color_after_normal(t_vec a_vec[2], t_rt *scene, t_dist tmp_args,
							  t_light *l)
{
	t_vec *tmp;
	t_vec ret;
	t_vec n_l[2];
 	double com;

 	if (tmp_args.index == 4)
 		com = com;
	ret = (t_vec){0, 0, 0};
	tmp = product_vec_and_int(a_vec, tmp_args.distance, 0);
	n_l[0] = take_normal_from_obj(tmp_args, scene, tmp, a_vec);
//	if (tmp_args.index == 2)
//	{
//		t_vec check = (t_vec){scene->pl[tmp_args.fig_index]->x,
//							  scene->pl[tmp_args.fig_index]->y,
//							  scene->pl[tmp_args.fig_index]->z};
//		t_vec opos = (t_vec){-a_vec->x, -a_vec->y, -a_vec->z};
//		double vpr = vec_scal(opos, check);
//		if (vec_scal(check, opos) != 0)
//		{
//			check = vec_multi(check, vpr);
//			norm_vec(&check);
//			n_l[0] = check;
//		}
//	}
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
	t_vec		c[3];
	t_vec		new_vec[2];
	int 		i;
	t_dist		new;
	t_vec		tmp[2];

	i = -1;
	c[0] = vec_multi(*vec, args.distance);
	c[0] = (t_vec){c->x + vec[1].x, c->y + vec[1].y, c->z + vec[1].z};
	*tmp = (t_vec){vec->x, vec->y, vec->z};
	while (scene->light[++i] != NULL)
	{
		new_vec[1] = (t_vec){scene->light[i]->x, scene->light[i]->y,
		scene->light[i]->z};
		new_vec[0] = vec_subt(*c, (t_vec){scene->light[i]->x, scene->light[i]->y,
										  scene->light[i]->z});
		norm_vec(&new_vec[0]);
		new = check_len_figures(new_vec, scene);
		if (args.fig_index != new.fig_index || args.index != new.index)
			continue ;
		*(tmp + 1) = vec_subt((t_vec){scene->light[i]->x,
		scene->light[i]->y, scene->light[i]->z}, c[0]);
		*color = summ_colors(*color, coof_color_after_normal
			(tmp, scene, args, scene->light[i]));
	}
	return (get_color_after_normal(color + 1, *color, i));
}

