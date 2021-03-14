/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_rtx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:32:05 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:37:34 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				check_max_cams(t_rt *scene)
{
	int			i;

	i = 0;
	while (scene->cam[i] != NULL)
	{
		i++;
	}
	return (i);
}

double			radians_to_degrees(double radians)
{
	double		ret;

	ret = radians * 180 / M_PI;
	return (ret);
}

double			degress_to_radians(double degrees)
{
	double		ret;

	ret = degrees * (M_PI / 180);
	return (ret);
}
