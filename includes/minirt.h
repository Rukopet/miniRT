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

#include <inc.h>

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
	double		bright_rate;
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
	int			fov;
}				t_cam;

typedef struct	s_light
{
	double		x;
	double		y;
	double		z;
	double		bright_rate;
	int			r;
	int			g;
	int			b;
	double 		distance;
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
	double 		distance;
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
	double 		distance;
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
	double 		distance;
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
	double 		distance;
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

	double 		distance;
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

typedef struct	s_vp
{
	double 		x;
	double		y;
	double		x_iter;
	double 		y_iter;
}				t_vp;

typedef struct	s_data
{
	void		*mlx;
	void 		*win;
	double 		angle_x;
	double 		angle_y;
	double 		angle_z;
	double		x_res_ratio;
	t_vec 		*v_cdir;
	t_vec		color_t;
	t_vec 		*vec_matrix;
}				t_data;

typedef struct	s_rt
{
	t_count 	*counter;
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
}				t_rt;

typedef struct	s_figures
{
	t_cam		**cam;
	t_light		**light;
	t_sp		**sp;
	t_pl		**pl;
	t_sq		**sq;
	t_cy		**cy;
	t_tr		**tr;
}				t_figures;

#include "mlx.h"
#include "solve_mlx.h"
#include "vectors.h"
#include "get_next_line.h"
#include "libft.h"
#include "intersect_and_light.h"

/*
** main structure;
*/


int				check_scene_arg(char **argv, t_rt *scene, int argc);
int				init_count_struct(t_count *counter);
// char			*join_free(char **save, char *join, char ***line);
int				join_str(char **gnl, char **join);
int				work_with_counter_br(char **join, t_count *counter, t_rt *scene);
int				count_validate(t_count *counter, t_rt *scene);

int				free_scene(t_rt *s, int flag);
void			init_scene_struct(t_rt **str);

int				parse_after_count(char **join, t_rt *scene);
char			*next_argument_check(char **join);

int				write_error_withpars(const char *line);
int				parse_resolution(char **line, t_rt *s);
int				parse_alight(char **line, t_rt *s);
int				parse_cam(char **line, t_rt *s, int *i);
int				parse_light(char **line, t_rt *s, int *i);
int				parse_sphere(char **line, t_rt *s, int *i);
int				parse_plane(char **line, t_rt *s, int *i);
int				parse_square(char **line, t_rt *s, int *i);
int				parse_cylinder(char **line, t_rt *s, int *i);
int				parse_triangle(char **line, t_rt *s, int *i);
double 			ft_atof(char *s);
double			ft_atof_ptr(char **s);
int				ft_atoi_ptr(char **nptr);

void			ft_index(int *index);
void			errors_and_exit(int flag, t_rt *scene);

void			alloc_light(t_count *c, t_rt *scene);
void			alloc_sphere(t_count *c, t_rt *scene);
void			alloc_plane(t_count *c, t_rt *scene);
void			alloc_square(t_count *c, t_rt *scene);
void			alloc_cylinder(t_count *c, t_rt *scene);
void			alloc_triangle(t_count *c, t_rt *scene);

#endif
