/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_branching2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:21:15 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:21:18 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	cylinder_light_br(t_dist args, t_rt *scene, t_vec *vec, t_vec color[2])
{
	if (args.index == 4)
	{
		*(color + 1) = (t_vec){scene->cy[args.fig_index]->r,
		scene->cy[args.fig_index]->g, scene->cy[args.fig_index]->b};
		if (scene->light)
			*(color + 1) = vec_to_light(color, scene, vec, args);
		else
			*(color + 1) = (t_vec){color[1].x * color->x,
			color[1].y * color->y, color[1].z * color->z};
	}
	else
		errors_and_exit(19, scene);
	return (*(color + 1));
}

t_vec	triangle_light_br(t_dist args, t_rt *scene, t_vec *vec, t_vec color[2])
{
	if (args.index == 5)
	{
		*(color + 1) = (t_vec){scene->tr[args.fig_index]->r,
		scene->tr[args.fig_index]->g, scene->tr[args.fig_index]->b};
		if (scene->light)
			*(color + 1) = vec_to_light(color, scene, vec, args);
		else
			*(color + 1) = (t_vec){color[1].x * color->x,
			color[1].y * color->y, color[1].z * color->z};
	}
	else
		return (cylinder_light_br(args, scene, vec, color));
	return (*(color + 1));
}
