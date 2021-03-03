#include "minirt.h"
#include <stdio.h>

void painting_scene(t_rt *scene, int x, int y)
{
	t_angles 	*angles;
	t_vec		*norm_vec;
	int 		color;

	if (!(angles = malloc(sizeof(t_angles))))
		errors_and_exit(-1, scene);
	calculate_angles(scene, x, y, angles);
	norm_vec = firs_dot_angles_to_coordinate(angles);
//
//	#include <fcntl.h>
//	#include <sys/types.h>
//	#include <sys/stat.h>
//	#include <unistd.h>
//
//		int fd = open("pars.txt", O_RDWR|O_APPEND|O_CREAT);
//		dprintf(fd, "%f\t%f\t%f\n", norm_vec->x, norm_vec->y, norm_vec->z);
//		close(fd);

//	printf("xy %d|%d  %f * %f * %f\n", x, y, angles->angle_x, angles->angle_y,
//		  angles->angle_z);
	color = intersect(norm_vec, scene);
	mlx_pixel_put(scene->d->mlx, scene->d->win, x, y, color);
	free(angles);

}