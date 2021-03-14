/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_to_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:57:55 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:58:40 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			angle_to_x(double x)
{
	double		ret_x;

	ret_x = (double)cos(degress_to_radians(x));
	return (ret_x);
}

double			angle_to_y(double y)
{
	double		ret_y;

	ret_y = (double)cos(degress_to_radians(y));
	return (ret_y);
}

double			angle_to_z(double z)
{
	double		ret_z;

	ret_z = (double)sin(degress_to_radians(z));
	return (ret_z);
}

t_vec			firs_dot_angles_to_coordinate(t_angles *angles)
{
	t_vec		tmp;

	tmp = (t_vec){angles->angle_x, angles->angle_y, angles->angle_z};
	norm_vec(&tmp);
	return (tmp);
}
