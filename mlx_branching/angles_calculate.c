#include "minirt.h"

static void		calculate_angles_xless(t_angles *angles, t_rt *scene, int x,
								 int y)
{
	int 		tmp;
	int			tmp_y;

	angles->angle_x = scene->d->angle_x + ((RES_X - tmp) *
										   scene->d->x_res_ratio);
	angles->angle_y = scene->d->angle_y - ((RES_X - tmp) *
										   scene->d->x_res_ratio);
	angles->angle_z = (y > (tmp_y = scene->resolution->y / 2)) ?
			scene->d->angle_z - ((RES_Y - tmp_y) *scene->d->x_res_ratio) :
			scene->d->angle_z + ((RES_Y - tmp_y) * scene->d->x_res_ratio);
}
void 			calculate_angles(t_angles *angles, t_rt *scene, int x, int y)
{
	int			tmp;
	int 		tmp_y;

	if (x > (tmp = scene->resolution->x / 2))
	{
		angles->angle_x = scene->d->angle_x - ((RES_X - tmp) *
				scene->d->x_res_ratio);
		angles->angle_y = scene->d->angle_y + ((RES_X - tmp) *
				scene->d->x_res_ratio);
		angles->angle_z = (y > (tmp_y = scene->resolution->y / 2)) ?
						scene->d->angle_z - ((RES_Y - tmp_y) *
						scene->d->x_res_ratio) : scene->d->angle_z +
						((RES_Y - tmp_y) * scene->d->x_res_ratio);
	}
	else
		calculate_angles_xless(angles, scene, x, y);
}