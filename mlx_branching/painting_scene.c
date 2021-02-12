#include "minirt.h"
#include <stdio.h>

void painting_scene(t_rt *scene, int x, int y)
{
	t_angles 	*angles;
	t_vec		*norm_vec;

	if (!(angles = malloc(sizeof(t_angles))))
		errors_and_exit(-1, scene);
	calculate_angles(scene, x, y, angles);
	norm_vec = firs_dot_angles_to_coordinate(angles);
	printf("xy %d|%d  %f * %f * %f\n", x, y, angles->angle_x, angles->angle_y,
		  angles->angle_z);
//		mlx_pixel_put(scene->d->mlx, scene->d->win, x, y, color);

	if (-100 != intersect_sphere(norm_vec, scene->sp[0], scene))
		mlx_pixel_put(scene->d->mlx, scene->d->win, x, y, 0x00F00FFF);
	else
		mlx_pixel_put(scene->d->mlx, scene->d->win, x, y, 0x0);
	free(angles);

}