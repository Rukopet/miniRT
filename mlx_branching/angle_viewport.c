#include "minirt.h"

t_vec get_ray_to_vp(t_rt *sc, int x, int y, t_cam *cam)
{
	t_vec		vec;
	t_vec		xyz;
	double 		tmp;

	xyz = (t_vec){cam->x, cam->y, cam->z};
	tmp = radians_to_degrees(tan(cam->fov / 2.0));
	vec = (t_vec){(2 * (x + 0.5) / (double)sc->resolution->x - 1) * (double)
			   sc->resolution->x / (double)sc->resolution->y * cam->fov, (1 -
			   2 * (y + 0.5) / (double)sc->resolution->y * cam->fov), -1};
	norm_vec(&vec);
}