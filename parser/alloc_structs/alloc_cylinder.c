/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:21:49 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 12:22:20 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		alloc_cylinder(t_count *c, t_rt *scene)
{
	int		i;

	i = 0;
	if (!(scene->cy = (t_cy **)malloc(sizeof(t_cy *) * (c->cy + 1))))
		errors_and_exit(9, scene);
	scene->cy[c->cy] = NULL;
	while (i != c->cy)
		if (!(scene->cy[i++] = malloc(sizeof(t_cy))))
			errors_and_exit(9, scene);
}
