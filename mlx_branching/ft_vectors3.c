/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:49:01 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:49:11 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec			vec_subt(t_vec vec1, t_vec vec2)
{
	return ((t_vec){vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z});
}

double			vec_scal(t_vec vec1, t_vec vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vec			vec_multi(t_vec vec, double dist)
{
	return ((t_vec){vec.x * dist, vec.y * dist, vec.z * dist});
}

t_vec			norm_vector_stack(t_vec *vec)
{
	double			len;

	len = length_vector(vec);
	return ((t_vec){vec->x / len, vec->y / len, vec->z / len});
}

t_vec			vec_summ(t_vec vec1, t_vec vec2)
{
	return ((t_vec){vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z});
}
