#include "minirt.h"

//void 				try_put_pixel(t_rt *scene)
//{
//	t_data 			*d;
//	d = scene->d;
//	int 			t_x = -1;
//	int 			t_y = -1;
//
//
//	while (++t_x != scene->resolution->x)
//	{
//		t_y = -1;
//		while (++t_y != scene->resolution->y)
//		{
//			mlx_pixel_put(d->mlx, d->win, t_x,
//						  t_y, 0x0000F0F0);
//		}
//	}
//	mlx_loop(scene->d->mlx);
//}

void				init_data_struct(t_rt *scene, void *mlx, void *mlx_win)
{
	t_data			*data;

	if(!(data = malloc(sizeof(t_data))))
		errors_and_exit(-1, scene);
	data->mlx = mlx;
	data->win = mlx_win;
	data->vp = NULL;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	data->v_cdir = NULL;
	data->x_res_ratio = 0;
	data->fov_for_y = 0;
	data->vec_matrix = NULL;
	scene->d = data;
}

void				begin_mlx_work(t_rt *scene)
{
	void			*mlx;
	void			*mlx_win;

	if (NULL == (mlx = mlx_init()))
		errors_and_exit(20, scene);
	mlx_win = mlx_new_window(mlx, scene->resolution->x, scene->resolution->y, "miniRT21");
	init_data_struct(scene, mlx, mlx_win);
	rtx(scene);
}
