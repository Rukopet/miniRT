#include "minirt.h"

static void		calculate_angles_xless(t_angles *angles, t_rt *scene, int x,
								 int y)
{
	int 		tmp;
	int			tmp_y;

	tmp = scene->resolution->x / 2;
	tmp_y = scene->resolution->y / 2;

	angles->angle_y = (scene->d->angle_y - (double)(tmp - x)) *
			scene->d->x_res_ratio;
	angles->angle_x = scene->d->angle_x + (double)(tmp - x) * scene->d->x_res_ratio;
	angles->angle_z = (y > tmp_y) ? scene->d->angle_z - ((double)(y - tmp_y) *
					  				scene->d->x_res_ratio) : scene->d->angle_z +
					 				((tmp_y - y) * scene->d->x_res_ratio);
}
void calculate_angles(t_rt *scene, int x, int y, t_angles *angles)
{
	int			tmp;
	int 		tmp_y;

	tmp = scene->resolution->x / 2;
	tmp_y = scene->resolution->y / 2;
	if (x > tmp)
	{
		angles->angle_x = scene->d->angle_x - ((double)(x - tmp) *
				scene->d->x_res_ratio);
		angles->angle_y = scene->d->angle_y + ((double)(x - tmp) *
				scene->d->x_res_ratio);
		angles->angle_z = (y > tmp_y) ?	scene->d->angle_z - ((double)(y - tmp_y) *
				scene->d->x_res_ratio) : scene->d->angle_z +
						((tmp_y - y) * scene->d->x_res_ratio);
	}
	else
		calculate_angles_xless(angles, scene, x, y);

}