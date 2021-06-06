/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:00:04 by egums             #+#    #+#             */
/*   Updated: 2021/03/15 18:53:44 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "get_next_line.h"
# include "structs.h"
# include "inc.h"
# include <mlx.h>
# include "solve_mlx.h"
# include "vectors.h"
# include "libft.h"
# include "intersect_and_light.h"

/*
** main structure;
*/

int				check_scene_arg(char **argv, t_rt *scene, int argc);
int				init_count_struct(t_count *counter);
int				join_str(char **gnl, char **join);
int				work_with_counter_br(char **join, t_count *counter, \
		t_rt *scene);
int				count_validate(t_count *counter, t_rt *scene);
int				check_extention(char *name);

int				free_scene(t_rt *s, int flag);
void			init_scene_struct(t_rt **str);

int				parse_after_count(char **join, t_rt *scene);
char			*next_argument_check(char **join);
char			*init_values_pars(int index);
void			validator(t_rt *sc);

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
double			ft_atof_ptr(char **s);
int				ft_atoi_ptr(char **nptr);
void			check_args(char **line, int v);

void			errors_and_exit(int flag, t_rt *scene);
char			*init_values_pars(int index);

void			alloc_light(t_count *c, t_rt *scene);
void			alloc_sphere(t_count *c, t_rt *scene);
void			alloc_plane(t_count *c, t_rt *scene);
void			alloc_square(t_count *c, t_rt *scene);
void			alloc_cylinder(t_count *c, t_rt *scene);
void			alloc_triangle(t_count *c, t_rt *scene);

#endif
