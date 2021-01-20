/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:00:04 by egums             #+#    #+#             */
/*   Updated: 2021/01/17 21:00:05 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

typedef struct	s_vec
{
	float		x;
	float		y;
	float		z;
}				t_vec;

typedef struct	s_res
{
	int			x;
	int			y;
}				t_res;

typedef struct	s_al
{
	float		x;
	float		y;
	float		z;
	float		bright_rate;
	char		r;
	char		g;
	char		b;
}				t_al;

typedef struct	s_cam
{
	float		x;
	float		y;
	float		z;
	float		vec_x;
	float		vec_y;
	float		vec_z;
	char		fov;
}				t_cam;

typedef struct	s_light
{
	float		x;
	float		y;
	float		z;
	float		bright_rate;
	char		r;
	char		g;
	char		b;
}				t_light;

typedef struct	s_sp
{
	float		x;
	float		y;
	float		z;
	float		diameter;
	char		r;
	char		g;
	char		b;
}				t_sp;

typedef struct	s_pl
{
	float		x;
	float		y;
	float		z;
	float		vec_x;
	float		vec_y;
	float		vec_z;
	char		r;
	char		g;
	char		b;
}				t_pl;

typedef struct	s_sq
{
	float		x;
	float		y;
	float		z;
	float		vec_x;
	float		vec_y;
	float		vec_z;
	float		side_size;
	char		r;
	char		g;
	char		b;
}				t_sq;

typedef struct	s_cy
{
	float		x;
	float		y;
	float		z;
	float		vec_x;
	float		vec_y;
	float		vec_z;
	float		diameter;
	float		height;
	char		r;
	char		g;
	char		b;
}				t_cy;

typedef struct	s_tr
{
	float		first;
	float		second;
	float		third;
	char		r;
	char		g;
	char		b;
}				t_tr;

typedef	struct	s_count
{
	int			resolution;
	int			a_light;
	int			cam;
	int			light;
	int			sp;
	int			pl;
	int			sq;
	int			cy;
	int			tr;
}				t_count;

typedef struct	s_rt
{
	t_res		*resolution;
	t_al		*a_light;
	t_cam		**cam;
	t_light		**light;
	t_sp		**sp;
	t_pl		**pl;
	t_sq		**sq;
	t_cy		**cy;
	t_tr		**tr;
}				t_rt;

/*
** main structure;
*/

typedef struct	s_error
{
	char		t;
}				t_error;

#include "stdlib.h"
#include "unistd.h"

int				check_scene_arg(char **argv, t_rt *scene, int argc);
int				init_count_struct(t_count *counter);
#endif
