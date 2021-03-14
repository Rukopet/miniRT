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
							  t_light *l, t_vec *full)
{
	t_vec *tmp;
	t_vec ret;
	t_vec n_l[2];
 	double com;

	ret = (t_vec){0, 0, 0};
	tmp = product_vec_and_int(a_vec, tmp_args.distance, 0);
	if (full == NULL)
	{
		n_l[0] = take_normal_from_obj(tmp_args, scene, tmp, a_vec, NULL);
		norm_vec(&n_l[0]);
	}
	else
		*n_l = *full;
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

//static int 		check_cyl_shadow(t_vec vec[2], t_dist *args, t_light *l,
//							  t_dist *new)
//{
//	t_vec		n_vec[2];
//	t_vec		p;
//	t_dist		tmp;
//
//	n_vec[1] = vec_multi(*vec, args->distance);
//	*n_vec = vec_subt((t_vec){l->x, l->y, l->z}, p);
//	norm_vec(&n_vec[0])
//	if ()
//}

t_vec vec_to_light(t_vec color[2], t_rt *sc, t_vec vec[2], t_dist args)
{
	t_vec		c[3];
	t_vec		n_v[2];
	int 		i;
	t_dist		new;
	t_vec		tmp[2];

	i = -1;
	c[0] = vec_multi(*vec, args.distance);
	c[0] = (t_vec){c->x + vec[1].x, c->y + vec[1].y, c->z + vec[1].z};
	*tmp = (t_vec){vec->x, vec->y, vec->z};
	while (sc->light[++i] != NULL)
	{
		n_v[1] = (t_vec){sc->light[i]->x, sc->light[i]->y,
						sc->light[i]->z};
		n_v[0] = vec_subt(*c, (t_vec){sc->light[i]->x, sc->light[i]->y,
						sc->light[i]->z});
		norm_vec(&n_v[0]);
		new = check_len_figures(n_v, sc);
		if (args.fig_index != new.fig_index || args.index != new.index)
			continue ;
		*(tmp + 1) = vec_subt((t_vec){sc->light[i]->x,
						sc->light[i]->y, sc->light[i]->z}, c[0]);
		*color = summ_colors(*color, coof_color_after_normal
				(tmp, sc, args, sc->light[i], NULL));
	}
	return (get_color_after_normal(color + 1, *color, i));
}

t_vec vec_to_light_cyl(t_vec color[2], t_rt *sc, t_vec vec[2], t_dist args)
{
	t_vec		c[2];
	t_vec		tmp[2];
	t_vec		vn;
	int 		i;
	t_dist		new;

	i = -1;
	c[1] = vec_summ(vec_multi(*vec, args.distance), *(vec + 1));
	*tmp = *vec;

	while (sc->light[++i] != NULL)
	{
		c[0] = vec_subt((t_vec){sc->light[i]->x, sc->light[i]->y,
			sc->light[i]->z}, vec_multi(*vec, args.distance));
		norm_vec(&c[0]);
		tmp[1] = c[1];
//		vn = take_normal_cylinder(vec_multi(*vec, args.distance),
//			sc->cy[args.fig_index], &args, tmp);

//		double 	check = vec_scal(vec_subt(c[1], (t_vec){sc->cy[args
//		.fig_index]->x, sc->cy[args.fig_index]->y, sc->cy[args
//		.fig_index]->z}), (t_vec){sc->cy[args.fig_index]->vec_x,
//		sc->cy[args.fig_index]->vec_y, sc->cy[args.fig_index]->vec_z});
//		vn = vec_multi((t_vec){sc->cy[args.fig_index]->vec_x,
//		sc->cy[args.fig_index]->vec_y, sc->cy[args.fig_index]->vec_z}, check);
//		vn = vec_subt(vec_subt(c[1], (t_vec){sc->cy[args.fig_index]->vec_x,
//		sc->cy[args.fig_index]->vec_y, sc->cy[args.fig_index]->vec_z}), vn);
//		c[1] = vec_summ(c[1], vec_multi(vn, 0.001));


		t_vec c_c = (t_vec){sc->cy[args
		.fig_index]->x, sc->cy[args.fig_index]->y, sc->cy[args
		.fig_index]->z};
		t_vec oc = vec_subt(vec[1], c_c);

		t_vec orient = (t_vec){sc->cy[args.fig_index]->vec_x,
		sc->cy[args.fig_index]->vec_y, sc->cy[args.fig_index]->vec_z};
		norm_vec(&orient);
		double m = vec_scal(*vec, vec_multi(orient, args
		.distance)) + vec_scal(orient, oc);
		t_vec dt = vec_multi(*vec, args.distance);
		vn = vec_subt(vec_summ(dt, oc), vec_multi(orient, m));
//		vn = vec_multi(vn, -1);
//		c[1] = vec_summ(c[1], vec_multi(vn, 0.001));
		norm_vec(&vn);

		t_vec opp = vec_multi(*vec, -1);
		double kek = vec_scal(vn, opp);
		if (vec_scal(vn, opp) != 0)
			vn = vec_multi(vn, kek);

		new = check_len_figures(c, sc);

		if (isnormal(new.distance))
			continue ;
		*color = summ_colors(*color, coof_color_after_normal
				(tmp, sc, args, sc->light[i], &vn));
	}
	return (get_color_after_normal(color + 1, *color, i));


//#include <fcntl.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <unistd.h>
//		int fd = open("pars.txt", O_RDWR|O_APPEND|O_CREAT);
//		dprintf(fd, "%f\t%f\t%f\n", vec->x * args.distance + vn.x, vec->y * args
//				.distance + vn.y, vec->z * args.distance + vn.z);
//		close(fd);


}