#include "minirt.h"
#include <stdio.h>

void put_pixel(t_rt *sc, int x, int y, int color)
{
	char 		*d;

	d = sc->img->adr + (y * sc->img->line_len + x * (sc->img->bits_per_pixel /
			8));
	*(unsigned  int*)d = color;
}

void painting_scene(t_rt *scene, int x, int y, t_cam *cam)
{
	t_angles 	*angles;
	t_vec		*norm_vec;
	int 		color;

	if (!(angles = malloc(sizeof(t_angles))))
		errors_and_exit(-1, scene);
//	if (cam->fov > 170)
//	{
		calculate_angles(scene, x, y, angles);
		norm_vec = firs_dot_angles_to_coordinate(angles);
//	}

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
	put_pixel(scene, x, y, color);
//	mlx_pixel_put(scene->d->mlx, scene->d->win, x, y, color);
	free(angles);
}