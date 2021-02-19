#include "minirt.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
t_vec vec_to_light(t_vec color, t_rt *scene, t_vec *vec, t_dist args)
{
	t_vec 		*coords_tr;
	t_vec		tmp;
	t_vec		tmp_begin;
	t_vec		*tmp_matrix;
	t_vec		*norm_light;
	int 		i;
	static int 		j = 0;

	coords_tr = product_vec_and_int(vec, args.distance, 0);
	i = -1;
	tmp_matrix = alloc_vector(scene->d->vec_matrix->x + coords_tr->x,
							  scene->d->vec_matrix->y + coords_tr->y,
							  scene->d->vec_matrix->z + coords_tr->z);
	while (scene->light[++i] != NULL)
	{
		int fd = open("pars.txt", O_RDWR|O_APPEND|O_CREAT);

		tmp_begin.x = scene->light[i]->x - tmp_matrix->x;
		tmp_begin.y = scene->light[i]->y - tmp_matrix->y;
		tmp_begin.z = scene->light[i]->z - tmp_matrix->z;
		norm_light = alloc_vector(tmp_begin.x, tmp_begin.y, tmp_begin.z);
		norm_vec(norm_light);
//		dprintf(fd, "%f\t%f\t%f\n", scene->sp[args.fig_index]->x - tmp_matrix->x,
//				scene->sp[args.fig_index]->y - tmp_matrix->y,
//				scene->sp[args.fig_index]->z - tmp_matrix->z);

//		dprintf(fd, "%f\t%f\t%f\n", coords_tr->x - tmp_matrix->x,
//				coords_tr->y - tmp_matrix->y, coords_tr->z - tmp_matrix->z);
		args = check_len_figures(norm_light, scene, tmp_matrix);
		j++;

//		dprintf(fd, "%f\t%f\t%f\n", norm_light->x * args.distance,
//				norm_light->y * args.distance, vec->z * args.distance);
//		dprintf(fd, "%f\t%f\t%f\n", scene->sp[args.fig_index]->x - tmp_matrix->x,
//		scene->sp[args.fig_index]->y - tmp_matrix->y,
//		scene->sp[args.fig_index]->z - tmp_matrix->z);

		close(fd);
		if (!isinf(args.distance)) {
			color.x = 255;
			color.y = 255;
			color.z = 255;
		}

	}
	free(tmp_matrix);
	return (color);
//	scene->d->vec_matrix = tmp_matrix;
	tmp_matrix = NULL;
}