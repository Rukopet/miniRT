#include "minirt.h"
#include <stdio.h>

static t_vec	do_ray(t_cam *cam, t_vec *vec)
{
	t_vec		tmp;

	tmp = (t_vec){vec->x * cam->tran_mat[0][0] + vec->y * cam->tran_mat[1][0]
			   + vec->z * cam->tran_mat[2][0],
				  vec->x * cam->tran_mat[0][1] + vec->y * cam->tran_mat[1][1]
				  + vec->z * cam->tran_mat[2][1],
				  vec->x * cam->tran_mat[0][2] + vec->y * cam->tran_mat[1][2]
				  + vec->z * cam->tran_mat[2][2]};
	return (tmp);
}

t_vec get_ray_to_vp(t_rt *sc, int x, int y, t_cam *cam)
{
	t_vec		vec;
	double 		tmp;

	tmp = tan(degress_to_radians(cam->fov / 2.0));
	vec = (t_vec){(2.0 * (x + 0.5) / (double)sc->resolution->x - 1) * (double)
			   sc->resolution->x / (double)sc->resolution->y * tmp,
			   (1 - 2.0 * (y + 0.5) / (double)sc->resolution->y) * tmp,
			   -1};
	norm_vec(&vec);
	vec = do_ray(cam, &vec);
//	norm_vec(&vec);
//	#include <fcntl.h>
//	#include <sys/types.h>
//	#include <sys/stat.h>
//	#include <unistd.h>
//	int fd = open("pars.txt", O_RDWR|O_APPEND|O_CREAT);
//	dprintf(fd, "%f\t%f\t%f\n", vec.x, vec.y, vec.z);
//	close(fd);
	return (vec);
}