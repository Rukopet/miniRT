/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:00:14 by egums             #+#    #+#             */
/*   Updated: 2021/03/15 19:00:16 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_res
{
	int			x;
	int			y;
}				t_res;

typedef struct	s_al
{
	double		b_rate;
	int			r;
	int			g;
	int			b;
}				t_al;

typedef struct	s_cam
{
	double		x;
	double		y;
	double		z;
	double		vec_x;
	double		vec_y;
	double		vec_z;
	double		**tran_mat;
	int			fov;
}				t_cam;

typedef struct	s_light
{
	double		x;
	double		y;
	double		z;
	double		b_rate;
	int			r;
	int			g;
	int			b;
}				t_light;

typedef struct	s_sp
{
	double		x;
	double		y;
	double		z;
	double		diameter;
	int			r;
	int			g;
	int			b;
}				t_sp;

typedef struct	s_pl
{
	double		x;
	double		y;
	double		z;
	double		vec_x;
	double		vec_y;
	double		vec_z;
	int			r;
	int			g;
	int			b;
}				t_pl;

typedef struct	s_sq
{
	double		x;
	double		y;
	double		z;
	double		vec_x;
	double		vec_y;
	double		vec_z;
	double		side_size;
	int			r;
	int			g;
	int			b;
}				t_sq;

typedef struct	s_cy
{
	double		x;
	double		y;
	double		z;
	double		vec_x;
	double		vec_y;
	double		vec_z;
	double		diameter;
	double		height;
	int			r;
	int			g;
	int			b;
}				t_cy;

typedef struct	s_tr
{
	double		first_x;
	double		first_y;
	double		first_z;

	double		second_x;
	double		second_y;
	double		second_z;

	double		third_x;
	double		third_y;
	double		third_z;

	int			r;
	int			g;
	int			b;

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

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	double		x_res_ratio;
	t_vec		*vec_matrix;
}				t_data;

typedef struct	s_img
{
	void		*img;
	char		*adr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
}				t_img;

typedef struct	s_rt
{
	t_count		*counter;
	t_data		*d;
	t_res		*resolution;
	t_al		*a_light;
	t_cam		**cam;
	t_light		**light;
	t_sp		**sp;
	t_pl		**pl;
	t_sq		**sq;
	t_cy		**cy;
	t_tr		**tr;
	t_img		*img;
	int			cam1;
	short		save;
	char		*fn;
}				t_rt;

typedef struct	s_d
{
	double		d1;
	double		d2;
}				t_d;

typedef struct	s_limits
{
	int			prev_x;
	int			prev_y;
	int			x;
	int			y;
	t_rt		*scene;
	t_cam		*cam;
}				t_limits;

typedef struct	s_angles
{
	double		angle_x;
	double		angle_y;
	double		angle_z;
}				t_angles;

typedef struct	s_dist
{
	int			index;
	int			fig_index;
	double		distance;
	double		quad1;
}				t_dist;

typedef struct	s_triangle
{
	t_vec		normal;
	t_vec		*vec;
	t_vec		p[3];
	double		s;
	t_pl		pl;
	t_vec		ab_s;
	t_vec		ac_s;
	t_vec		bc_s;

}				t_triangle;

typedef struct	s_c
{
	double		a;
	double		b;
	double		c;
	double		tmp;
	t_vec		orient;
	t_vec		norm_ori;
	t_vec		vpr_p;
	t_vec		vpr_cyl;
	t_vec		point;
	t_vec		*vec;
}				t_c;

#endif
