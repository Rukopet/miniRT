/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_mlx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:00:08 by egums             #+#    #+#             */
/*   Updated: 2021/03/15 19:00:10 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_MLX_H
# define SOLVE_MLX_H

# include "minirt.h"

void			rtx(t_rt *scene, t_img *img, int cam);
void			begin_mlx_work(t_rt *scene);

t_vec			firs_dot_angles_to_coordinate(t_angles *angles);

int				check_max_cams(t_rt *scene);
double			degress_to_radians(double degrees);
double			radians_to_degrees(double radians);

void			get_angles_to_data(t_rt *scene, t_cam *cam);
t_vec			get_ray_to_vp(t_rt *sc, int x, int y, t_cam *cam);

void			alloc_matrix(t_cam *cam);

t_limits		**alloc_limits(t_rt *scene, t_cam *cam);
void			calculate_angles(t_rt *scene, int x, int y, t_angles *angles);
void			painting_scene(t_rt *scene, int x, int y, t_cam *cam);

int				key_hook(int key_code, t_rt *sc);
void			image_to_bmp(t_rt *sc);
void			get_img(t_rt *scene);

#endif
