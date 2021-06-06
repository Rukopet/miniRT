/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_to_center.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:51:23 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:54:14 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double				rtx_cam_x(t_vec *tmp)
{
	double			cos_cam_z;
	double			degrees;
	t_vec			*tmp_x;

	tmp_x = alloc_vector(1, 0, 0);
	cos_cam_z = scalar_product_cos(tmp, tmp_x, 2);
	degrees = radians_to_degrees(acos(cos_cam_z));
	return (degrees);
}

double				rtx_cam_y(t_vec *tmp)
{
	double			cos_cam_z;
	double			degrees;
	t_vec			*tmp_y;

	tmp_y = alloc_vector(0, 1, 0);
	cos_cam_z = scalar_product_cos(tmp, tmp_y, 2);
	degrees = radians_to_degrees(acos(cos_cam_z));
	return (degrees);
}

double				rtx_cam_z(t_cam *cam, t_vec *tmp)
{
	t_vec			*v_cdir;
	double			cos_cam_z;
	double			degrees;

	v_cdir = alloc_vector(cam->vec_x, cam->vec_y, cam->vec_z);
	cos_cam_z = scalar_product_cos(tmp, v_cdir, 3);
	degrees = radians_to_degrees(acos(cos_cam_z));
	if (v_cdir->z < 0.0)
		degrees *= -1.0;
	return (degrees);
}

void				get_angles_to_data(t_rt *scene, t_cam *cam)
{
	t_vec			*tmp;

	if (cam->vec_x == 0 && cam->vec_y == 0 && cam->vec_z == 1)
		norm_vec(tmp = alloc_vector(cam->vec_x, cam->vec_y, 1));
	else
		norm_vec(tmp = alloc_vector(cam->vec_x, cam->vec_y, 0));
	if (scene->d && scene->resolution)
	{
		scene->d->angle_x = rtx_cam_x(tmp);
		scene->d->angle_y = rtx_cam_y(tmp);
		scene->d->angle_z = rtx_cam_z(cam, tmp);
		scene->d->x_res_ratio = (double)cam->fov / (double)scene->resolution->x;
	}
	free(tmp);
	tmp = NULL;
}
