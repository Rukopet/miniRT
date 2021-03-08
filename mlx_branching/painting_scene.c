#include "minirt.h"
#include <stdio.h>

void add_matrix(t_vec *next, t_cam *cam, int i)
{
	cam->tran_mat[i][0] = next->x;
	cam->tran_mat[i][1] = next->y;
	cam->tran_mat[i][2] = next->z;
	if (i == 2)
	{
		i += 1;
		cam->tran_mat[i][0] = cam->x;
		cam->tran_mat[i][1] = cam->y;
		cam->tran_mat[i][2] = cam->z;
	}
}

void transform_matrix(t_cam *cur_cam)
{
	t_vec		tmp[3];
	t_vec		dir;
	t_vec		up;


	dir = (t_vec){-cur_cam->vec_x, -cur_cam->vec_y, -cur_cam->vec_z};
	norm_vec(&dir);
	tmp[0] = (t_vec){0, 1, 0};
	tmp[1] = (t_vec){1, 0, 0};
	if (!(dir.y == 1 || dir.y == -1))
		tmp[1] = vector_cross(&tmp[0], &dir);
	norm_vec(&tmp[1]);
	up = vector_cross(&dir, &tmp[1]);
	norm_vec(&up);
	add_matrix(&tmp[1], cur_cam, 0);
	add_matrix(&up, cur_cam, 1);
	add_matrix(&dir, cur_cam, 2);
}

void put_pixel(t_rt *sc, int x, int y, int color)
{
	char 		*d;

	d = sc->img->adr + (y * sc->img->line_len + x * (sc->img->bits_per_pixel /
			8));
	*(unsigned  int*)d = color;
}

void painting_scene(t_rt *scene, int x, int y, t_cam *cam)
{
	t_angles 	angles;
	t_vec		norm_vec[2];
	int 		color;

	if (cam == NULL)
		cam = scene->cam[0];
	norm_vec[1] = (t_vec){cam->x, cam->y, cam->z};
	if (cam->fov == 60)
	{
		if (cam->tran_mat == NULL)
			alloc_matrix(cam);
		transform_matrix(cam);
		norm_vec[0] = get_ray_to_vp(scene, x, y, cam);
	}
	else
	{
		calculate_angles(scene, x, y, &angles);
		norm_vec[0] = firs_dot_angles_to_coordinate(&angles);
	}
	color = intersect(&norm_vec, scene);
	put_pixel(scene, x, y, color);
}
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

//	mlx_pixel_put(scene->d->mlx, scene->d->win, x, y, color);
