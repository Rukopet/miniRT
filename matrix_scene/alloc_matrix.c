/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:16:03 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 21:17:18 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	**alloc_el(int k, int s)
{
	double		**ret;
	double		*tmp;
	int			i;
	int			j;

	i = -1;
	if (!(ret = (double**)malloc(sizeof(double*) * k + (k * s * \
						sizeof(double)))))
		errors_and_exit(-1, NULL);
	tmp = (double*)((char*)ret + k * sizeof(double*));
	while (++i < k)
		ret[i] = tmp + i * s;
	i = 0;
	while (i < k)
	{
		j = -1;
		while (++j < s)
			ret[i][j] = 0;
		i++;
	}
	return (ret);
}

void			alloc_matrix(t_cam *cam)
{
	int			i;
	int			j;

	cam->tran_mat = alloc_el(4, 4);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			cam->tran_mat[i][j] = (i == j) ? 1 : 0;
	}
}
