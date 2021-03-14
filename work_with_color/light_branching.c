/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_branching.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:16:55 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:18:34 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec			square_light_br(t_dist args, t_rt *scene, t_vec *vec,\
			t_vec color[2])
{
	if (args.index == 3)
	{
		*(color + 1) = (t_vec){scene->sq[args.fig_index]->r,
		scene->sq[args.fig_index]->g, scene->sq[args.fig_index]->b};
		if (scene->light)
			*(color + 1) = vec_to_light(color, scene, vec, args);
		else
			*(color + 1) = (t_vec){color[1].x * color->x,
			color[1].y * color->y, color[1].z * color->z};
	}
	else
		return (triangle_light_br(args, scene, vec, color));
	return (*(color + 1));
}

t_vec			plane_light_br(t_dist args, t_rt *scene,\
			t_vec *vec, t_vec color[2])
{
	if (args.index == 2)
	{
		*(color + 1) = (t_vec){scene->pl[args.fig_index]->r,
		scene->pl[args.fig_index]->g, scene->pl[args.fig_index]->b};
		if (scene->light)
			*(color + 1) = vec_to_light(color, scene, vec, args);
		else
			*(color + 1) = (t_vec){color[1].x * color->x,
			color[1].y * color->y, color[1].z * color->z};
	}
	else
		return (square_light_br(args, scene, vec, color));
	return (*(color + 1));
}

t_vec			color_light_branching(t_dist args, t_rt *scene, t_vec vec[2])
{
	t_vec		color[2];

	if (scene->a_light)
		*color = (t_vec){scene->a_light->r / 255.0 * scene->a_light->b_rate *
		0.55, scene->a_light->g / 255.0 * scene->a_light->b_rate * 0.55,
		scene->a_light->b / 255.0 * scene->a_light->b_rate * 0.55};
	if (isinf(args.distance) && scene->a_light)
		return ((t_vec){scene->a_light->r / 15.0, scene->a_light->g / 15.0,
			scene->a_light->b / 15.0});
	else if (isinf(args.distance))
		return ((t_vec){0, 0, 0});
	if (args.index == 1)
	{
		*(color + 1) = (t_vec){scene->sp[args.fig_index]->r,
		scene->sp[args.fig_index]->g, scene->sp[args.fig_index]->b};
		if (scene->light)
			*(color + 1) = vec_to_light(color, scene, vec, args);
		else
			*(color + 1) = (t_vec){color[1].x * color->x,
			color[1].y * color->y, color[1].z * color->z};
	}
	else
		return (plane_light_br(args, scene, vec, color));
	return (*(color + 1));
}
