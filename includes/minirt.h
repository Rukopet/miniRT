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
	double		first;
	double		second;
	double		third;
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
// char			*join_free(char **save, char *join, char ***line);
int				join_str(char **gnl, char **join);
int				work_with_counter_br(char **join, t_count *counter, t_rt *scene);
int				count_validate(t_count *counter, t_rt *scene);

int				free_scene(t_rt *s, int flag);
void			init_scene_struct(t_rt *s);

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

void			ft_index(int *index);
void			erros_and_exit(int flag);

#endif
