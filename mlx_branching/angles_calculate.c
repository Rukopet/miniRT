#include "minirt.h"

static void		calculate_angles_xless(t_angles *angles, t_rt *scene, int x,
								 int y)
{
	int 		tmp;
	int			tmp_y;

	tmp = scene->resolution->x / 2;
	tmp_y = scene->resolution->y / 2;

	angles->angle_x = scene->d->angle_x + (tmp - x) * scene->d->x_res_ratio;
	angles->angle_y = scene->d->angle_y - (tmp - x) *
										   scene->d->x_res_ratio;
	angles->angle_z = (y > tmp_y) ? scene->d->angle_z - ((y - tmp_y) *
					  				scene->d->x_res_ratio) : scene->d->angle_z +
					 				((tmp_y - y) * scene->d->x_res_ratio);
}
void 			calculate_angles(t_angles *angles, t_rt *scene, int x, int y)
{
	int			tmp;
	int 		tmp_y;

	tmp = scene->resolution->x / 2;
	tmp_y = scene->resolution->y / 2;
	if (x > tmp)
	{
		angles->angle_x = scene->d->angle_x - ((x - tmp) *
				scene->d->x_res_ratio);
		angles->angle_y = scene->d->angle_y + ((x - tmp) *
				scene->d->x_res_ratio);
		angles->angle_z = (y > tmp_y) ?	scene->d->angle_z - ((y - tmp_y) *
				scene->d->x_res_ratio) : scene->d->angle_z +
						((tmp_y - y) * scene->d->x_res_ratio);
	}
	else
		calculate_angles_xless(angles, scene, x, y);
}