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
	coof = vec_multi(coof, 0.8);
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

t_vec coof_color_after_normal(t_vec *a_vec, t_rt *scene, t_dist tmp_args,
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
	com = vec_scal(n_l[0], vec_multi(*a_vec, -1));
	*n_l = (vec_scal(*n_l, vec_multi(*a_vec, -1)) != 0) ?
			vec_multi(*n_l, com) : *n_l;
	norm_vec(&*n_l);
	n_l[1] = take_light_to_color(l, tmp, scene, tmp_args);
	norm_vec(&n_l[1]);
	com = normal_vector(&n_l[1], &n_l[0]);
	if (com > 0)
	{
		ret = (t_vec){l->r / 255.0 * (l->b_rate * com),
					  l->g / 255.0 * (l->b_rate * com),
					  l->b / 255.0 * (l->b_rate * com)};
	}
	free(tmp);
	return (ret);
}

t_vec vec_to_light(t_vec color[2], t_rt *sc, t_vec vec[2], t_dist args)
{
	t_vec		n_v[2];
	int 		i;
	t_dist		new;
	t_vec		tmp[4];

	i = -1;
	tmp[3] = vec[1];
	tmp[2] = vec_summ(vec_multi(*vec, args.distance), vec[1]);
	*tmp = (t_vec){vec->x, vec->y, vec->z};
	while (sc->light[++i] != NULL)
	{
		n_v[1] = (t_vec){sc->light[i]->x, sc->light[i]->y,
						sc->light[i]->z};
		n_v[0] = vec_subt(tmp[2], (t_vec){sc->light[i]->x, sc->light[i]->y,
						sc->light[i]->z});
		norm_vec(&n_v[0]);
		new = check_len_figures(n_v, sc);
		if (args.fig_index != new.fig_index || args.index != new.index)
			continue ;
		*(tmp + 1) = vec_subt((t_vec){sc->light[i]->x,
						sc->light[i]->y, sc->light[i]->z}, tmp[2]);
		*color = summ_colors(*color, coof_color_after_normal
				(tmp, sc, args, sc->light[i]));
	}
	return (get_color_after_normal(color + 1, *color, i));
}
