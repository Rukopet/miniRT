/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtx_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:43:23 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:46:21 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int			do_close(int keycode, t_rt *sc)
{
	(void)keycode;
	(void)sc;
	exit(0);
}

void				do_rtx_calculations(void *limits)
{
	t_limits		*tmp;
	int				i;
	int				j;

	tmp = (t_limits*)limits;
	i = tmp->prev_y;
	while (++i != tmp->y)
	{
		j = tmp->prev_x;
		while (++j != tmp->x)
		{
			painting_scene(tmp->scene, j, i, tmp->cam);
		}
	}
	free(limits);
	limits = NULL;
}

void				rtx_with_angles(t_rt *scene, t_cam *cam)
{
	t_limits		**limits;
	pthread_t		thread[4];
	int				i;

	i = -1;
	limits = alloc_limits(scene, cam);
	while (++i != 4)
	{
		if (0 != pthread_create(&thread[i], NULL, (void*)do_rtx_calculations,
				(void*)limits[i]))
			errors_and_exit(-2, scene);
	}
	i = -1;
	while (++i != 4)
		if (0 != pthread_join(thread[i], NULL))
			errors_and_exit(-2, scene);
	free(limits);
	limits = NULL;
}

void				rtx(t_rt *scene, t_img *img, int cam)
{
	scene->img = img;
	get_img(scene);
	mlx_key_hook(scene->d->win, key_hook, scene);
	mlx_hook(scene->d->win, 17, (1L << 2), do_close, &scene);
	if (scene->cam[cam]->fov > 170)
		get_angles_to_data(scene, scene->cam[cam]);
	rtx_with_angles(scene, scene->cam[cam]);
	if (scene->save)
		image_to_bmp(scene);
	mlx_put_image_to_window(scene->d->mlx, scene->d->win,
							scene->img->img, 0, 0);
	mlx_loop(scene->d->mlx);
}
