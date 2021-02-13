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
//	printf("xy %d|%d  %f * %f * %f\n", x, y, angles->angle_x, angles->angle_y,
//		  angles->angle_z);
	color = intersect(norm_vec, scene);
	mlx_pixel_put(scene->d->mlx, scene->d->win, x, y, color);
	free(angles);

}