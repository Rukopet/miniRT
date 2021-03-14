/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_limits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:03:43 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 21:04:11 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_limits			**init_limits(t_limits **limits, t_rt *scene)
{
	int				i;

	i = -1;
	while (++i != 4)
	{
		limits[i]->scene = scene;
		limits[i]->y = (i > 1) ? scene->resolution->y : scene->resolution->y
				/ 2;
		limits[i]->prev_y = (i > 1) ? scene->resolution->y -
				scene->resolution->y / 2 - 1 : -1;
		if (i == 0 || i == 2)
		{
			limits[i]->x = scene->resolution->x / 2;
			limits[i]->prev_x = -1;
		}
		else if (i == 1 || i == 3)
		{
			limits[i]->x = scene->resolution->x;
			limits[i]->prev_x = scene->resolution->x / 2 - 1;
		}
	}
	return (limits);
}

t_limits			**alloc_limits(t_rt *scene, t_cam *cam)
{
	t_limits		**ret;
	int				i;

	i = -1;
	if (!(ret = malloc(sizeof(t_limits*) * 5)))
		errors_and_exit(-1, scene);
	ret[4] = NULL;
	while (++i != 4)
	{
		if (!(ret[i] = malloc(sizeof(t_limits))))
			errors_and_exit(-1, scene);
		ret[i]->cam = cam;
	}
	return (init_limits(ret, scene));
}
