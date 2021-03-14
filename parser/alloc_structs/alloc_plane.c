/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:32:10 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 12:32:26 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		alloc_plane(t_count *c, t_rt *scene)
{
	int		i;

	i = 0;
	if (!(scene->pl = (t_pl **)malloc(sizeof(t_pl *) * (c->pl + 1))))
		errors_and_exit(9, scene);
	scene->pl[c->pl] = NULL;
	while (i != c->pl)
		if (!(scene->pl[i++] = malloc(sizeof(t_pl))))
			errors_and_exit(9, scene);
}
