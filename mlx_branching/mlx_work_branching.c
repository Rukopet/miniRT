/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_work_branching.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:49:30 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:50:52 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int					key_hook(int key_code, t_rt *sc)
{
	t_img			img;
	int				max;

	if (key_code == 53)
		exit(0);
	if (key_code == 49)
	{
		if (1 >= (max = check_max_cams(sc)))
			return (0);
		if (sc->cam1 == max - 1)
			sc->cam1 = 0;
		else
			sc->cam1++;
		rtx(sc, &img, sc->cam1);
	}
	return (0);
}

void				get_img(t_rt *scene)
{
	scene->img->img = mlx_new_image(scene->d->mlx, scene->resolution->x,
	scene->resolution->y);
	scene->img->adr = mlx_get_data_addr(scene->img->img,
	&scene->img->bits_per_pixel, &scene->img->line_len, &scene->img->endian);
}

void				init_data_struct(t_rt *scene, void *mlx, void *mlx_win)
{
	t_data			*data;

	if (!(data = ft_calloc(1, sizeof(t_data))))
		errors_and_exit(-1, scene);
	data->mlx = mlx;
	data->win = mlx_win;
	scene->d = data;
}

void				begin_mlx_work(t_rt *scene)
{
	void			*mlx;
	void			*mlx_win;
	t_img			img;
	int				cam;

	scene->cam1 = 0;
	if (NULL == (mlx = mlx_init()))
		errors_and_exit(20, scene);
	check_resolution(scene, mlx);
	mlx_win = mlx_new_window(mlx, scene->resolution->x, scene->resolution->y,
	"miniRT");
	if (NULL == mlx_win)
		errors_and_exit(20, scene);
	cam = 0;
	init_data_struct(scene, mlx, mlx_win);
	rtx(scene, &img, cam);
}
