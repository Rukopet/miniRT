#include "minirt.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

t_vec color_light_branching(t_dist args, t_rt *scene, t_vec *vec)
{
	t_vec		color;
//	t_vec		*color_al;

	color.x = 0;
	color.y = 0;
	color.z = 0;
	if (isinf(args.distance) && scene->a_light)
		return (color);
//		return (alloc_vector(scene->a_light->r / 2 *
//		scene->a_light->bright_rate,
//					   scene->a_light->g / 2 * scene->a_light->bright_rate,
//					   scene->a_light->b / 2 * scene->a_light->bright_rate));
	if (args.index == 1)
	{
		color.x = scene->sp[args.fig_index]->r / 255 * scene->a_light->r *
				scene->a_light->bright_rate;
		color.y = scene->sp[args.fig_index]->g / 255 * scene->a_light->g *
				scene->a_light->bright_rate;
		color.z = scene->sp[args.fig_index]->b / 255 * scene->a_light->b *
				scene->a_light->bright_rate;
//		check_overcolor(color);
		if (0 == isinf(args.distance))
		{
//			int fd = open("pars.txt", O_RDWR|O_APPEND|O_CREAT);
//			dprintf(fd, "%f\t%f\t%f\n", vec->x * args.distance, vec->y * args
//			.distance, vec->z *
//			args.distance);
//			close(fd);
			color = vec_to_light(color, scene, vec, args);
		}
	}
	return (color);
	//chech it
}