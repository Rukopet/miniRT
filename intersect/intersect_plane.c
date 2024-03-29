/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:09:48 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 21:10:26 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			intersect_plane(t_vec vec[2], t_pl *pl)
{
	double		ret;
	t_vec		k;
	t_vec		normal;
	double		a;
	double		b;

	k = vec_subt(vec[1], (t_vec){pl->x, pl->y, pl->z});
	normal = (t_vec){pl->vec_x, pl->vec_y, pl->vec_z};
	norm_vec(&normal);
	normal = (vec_scal(*vec, normal) > 0) ? vec_multi(normal, -1) : normal;
	a = scalar_product(&k, &normal, 3);
	b = scalar_product(&vec[0], &normal, 3);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (INFINITY);
	ret = -a / b;
	if (ret < 0)
		return (INFINITY);
	return (ret);
}
