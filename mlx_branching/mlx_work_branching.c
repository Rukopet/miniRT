#include "minirt.h"

void 				next_cam(t_rt *sc)
{

}

int 				key_hook(int key_code, t_rt *sc)
{
	if (key_code == 53)
	{
//		mlx_destroy_window(sc->d->mlx, sc->d->win);
		exit(0);
	}
	if (key_code == 49)
	{
//		mlx_put_image_to_window(sc->d->mlx, sc->d->win, param->img->img, 0, 0);
		rtx(sc, 1);
	}

}

void				init_data_struct(t_rt *scene, void *mlx, void *mlx_win)
{
	t_data			*data;

	if(!(data = malloc(sizeof(t_data))))
		errors_and_exit(-1, scene);
	data->mlx = mlx;
	data->win = mlx_win;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	data->x_res_ratio = 0;
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
	if (NULL == mlx_win)
		errors_and_exit(20, scene);
	init_data_struct(scene, mlx, mlx_win);
	rtx(scene, 0);
}
