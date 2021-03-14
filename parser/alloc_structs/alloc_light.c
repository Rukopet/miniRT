/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:31:24 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 12:31:58 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		alloc_light(t_count *c, t_rt *scene)
{
	int		i;

	i = 0;
	if (!(scene->light = (t_light **)malloc(sizeof(t_light *) * \
					(c->light + 1))))
		errors_and_exit(9, scene);
	scene->light[c->light] = NULL;
	while (i != c->light)
		if (!(scene->light[i++] = malloc(sizeof(t_light))))
			errors_and_exit(9, scene);
}
