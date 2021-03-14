/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_alloc_stucts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:04:15 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:04:57 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			alloc_structs_res(t_count *c, t_rt *scene)
{
	int		i;
	int		len;

	i = 0;
	len = c->cam + 1;
	if (!(scene->resolution = malloc(sizeof(t_res) * c->resolution)))
		return (0);
	if (c->a_light != 0)
		if (!(scene->a_light = malloc(sizeof(t_al) * c->a_light)))
			return (0);
	if (c->cam != 0)
	{
		if (!(scene->cam = (t_cam**)malloc(sizeof(t_cam *) * len)))
			return (0);
		scene->cam[c->cam] = NULL;
		while (i != (len - 1))
			if (!(scene->cam[i++] = malloc(sizeof(t_cam))))
				return (0);
	}
	return (1);
}

void		alloc_structs_branching(t_count *counter, t_rt *scene)
{
	if (counter->light > 0)
		alloc_light(counter, scene);
	if (counter->sp > 0)
		alloc_sphere(counter, scene);
	if (counter->pl > 0)
		alloc_plane(counter, scene);
	if (counter->sq > 0)
		alloc_square(counter, scene);
	if (counter->cy > 0)
		alloc_cylinder(counter, scene);
	if (counter->tr > 0)
		alloc_triangle(counter, scene);
}

int			count_validate(t_count *counter, t_rt *scene)
{
	if (counter->resolution >= 2 || counter->resolution < 1)
	{
		write(2, "Error\nMultiplae resolution options or less than one\n", 55);
		return (0);
	}
	if (counter->a_light >= 2)
	{
		write(2, "Error\nMultiplae ambient light options or less then one\n", \
				58);
		return (0);
	}
	if (counter->cam > 0)
	{
		if (!(alloc_structs_res(counter, scene)))
			errors_and_exit(8, scene);
	}
	else
		errors_and_exit(5, scene);
	alloc_structs_branching(counter, scene);
	return (1);
}
