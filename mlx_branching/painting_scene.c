#include "minirt.h"
#include <stdio.h>

void			painting_scene(t_rt *scene, int x, int y)
{
	t_angles 	angles;
	t_vec		*norm_vec;

	calculate_angles(&angles, scene, x, y);
	norm_vec = firs_dot_angles_to_coordinate(&angles);
	printf("xy %d|%d  %f * %f * %f\n", x, y, angles.angle_x, angles.angle_y,
		  angles.angle_z);
//	mlx_pixel_put(scene->d->mlx, scene->d->win, x, y, 0x0000F0F0);

}