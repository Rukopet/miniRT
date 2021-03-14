/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:33:20 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 12:33:22 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		alloc_square(t_count *c, t_rt *scene)
{
	int		i;

	i = 0;
	if (!(scene->sq = (t_sq **)malloc(sizeof(t_sq *) * (c->sq + 1))))
		errors_and_exit(9, scene);
	scene->sq[c->sq] = NULL;
	while (i != c->sq)
		if (!(scene->sq[i++] = malloc(sizeof(t_sq))))
			errors_and_exit(9, scene);
}
