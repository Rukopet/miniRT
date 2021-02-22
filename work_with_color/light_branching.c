#include "minirt.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
//			int fd = open("pars.txt", O_RDWR|O_APPEND|O_CREAT);
//			dprintf(fd, "%f\t%f\t%f\n", vec->x * args.distance, vec->y * args
//			.distance, vec->z *
//			args.distance);
//			close(fd);

t_vec color_light_branching(t_dist args, t_rt *scene, t_vec *vec)
{
	t_vec		color[2];

	if (scene->a_light)
		*color = (t_vec){scene->a_light->r / 255.0 * scene->a_light->b_rate,
						scene->a_light->g / 255.0 * scene->a_light->b_rate,
						scene->a_light->b / 255.0 * scene->a_light->b_rate};
	if (isinf(args.distance) && scene->a_light)
		return ((t_vec){scene->a_light->r / 15.0, scene->a_light->g / 15.0,
				  scene->a_light->b / 15.0});
	else if (isinf(args.distance))
		return ((t_vec){0, 0, 0});
	if (args.index == 1)
	{
		*(color + 1) = (t_vec){scene->sp[args.fig_index]->r,
		scene->sp[args.fig_index]->g, scene->sp[args.fig_index]->b};
		if (scene->light)
			*(color + 1) = vec_to_light(color, scene, vec, args);
		else
			*(color + 1) = (t_vec){color[1].x * color->x,
			color[1].y * color->y, color[1].z * color->z};
	}
//	check_overcolor(color + 1);
//	if (color[1].x == 240 && color[1].y == 168 && color[1].z == 250)
//		return (*(color + 1));
	return (*(color + 1));
}