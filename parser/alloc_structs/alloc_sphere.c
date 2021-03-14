/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:32:52 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 12:32:53 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		alloc_sphere(t_count *c, t_rt *scene)
{
	int		i;

	i = 0;
	if (!(scene->sp = (t_sp **)malloc(sizeof(t_sp *) * (c->sp + 1))))
		errors_and_exit(9, scene);
	scene->sp[c->sp] = NULL;
	while (i != c->sp)
		if (!(scene->sp[i++] = malloc(sizeof(t_sp))))
			errors_and_exit(9, scene);
}
