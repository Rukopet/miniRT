/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:57:38 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 19:59:47 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			parse_resolution(char **line, t_rt *s)
{
	s->resolution->x = ft_atoi(line[1]);
	s->resolution->y = ft_atoi(line[2]);
	if (s->resolution->y <= 0 || s->resolution->x <= 0)
		return (write_error_withpars("Error\nBad resolution value\0"));
	if (NULL != line[3])
		return (0);
	return (1);
}

int			parse_alight(char **line, t_rt *s)
{
	char	*tmp;

	check_args(line, 3);
	tmp = line[1];
	s->a_light->b_rate = ft_atof_ptr(&tmp);
	tmp = line[2];
	s->a_light->r = ft_atoi_ptr(&tmp);
	s->a_light->g = ft_atoi_ptr(&tmp);
	s->a_light->b = ft_atoi_ptr(&tmp);
	if (NULL != line[4])
		return (0);
	return (1);
}

int			parse_cam(char **line, t_rt *s, int *i)
{
	char	*tmp;

	check_args(line, 4);
	tmp = line[1];
	s->cam[i[0]]->x = ft_atof_ptr(&tmp);
	s->cam[i[0]]->y = ft_atof_ptr(&tmp);
	s->cam[i[0]]->z = ft_atof_ptr(&tmp);
	tmp = line[2];
	s->cam[i[0]]->vec_x = ft_atof_ptr(&tmp);
	s->cam[i[0]]->vec_y = ft_atof_ptr(&tmp);
	s->cam[i[0]]->vec_z = ft_atof_ptr(&tmp);
	tmp = line[3];
	s->cam[i[0]]->fov = ft_atoi_ptr(&tmp);
	s->cam[i[0]]->tran_mat = NULL;
	if (line[4] != NULL)
		return (0);
	i[0] += 1;
	return (1);
}

int			parse_light(char **line, t_rt *s, int *i)
{
	char	*tmp;

	check_args(line, 4);
	tmp = line[1];
	s->light[i[1]]->x = ft_atof_ptr(&tmp);
	s->light[i[1]]->y = ft_atof_ptr(&tmp);
	s->light[i[1]]->z = ft_atof_ptr(&tmp);
	tmp = line[2];
	s->light[i[1]]->b_rate = ft_atof_ptr(&tmp);
	tmp = line[3];
	s->light[i[1]]->r = ft_atoi_ptr(&tmp);
	s->light[i[1]]->g = ft_atoi_ptr(&tmp);
	s->light[i[1]]->b = ft_atoi_ptr(&tmp);
	if (NULL != line[4])
		return (0);
	i[1] += 1;
	return (1);
}

int			parse_sphere(char **line, t_rt *s, int *i)
{
	char	*tmp;

	check_args(line, 4);
	tmp = line[1];
	s->sp[i[2]]->x = ft_atof_ptr(&tmp);
	s->sp[i[2]]->y = ft_atof_ptr(&tmp);
	s->sp[i[2]]->z = ft_atof_ptr(&tmp);
	tmp = line[2];
	s->sp[i[2]]->diameter = ft_atof_ptr(&tmp);
	tmp = line[3];
	s->sp[i[2]]->r = ft_atoi_ptr(&tmp);
	s->sp[i[2]]->g = ft_atoi_ptr(&tmp);
	s->sp[i[2]]->b = ft_atoi_ptr(&tmp);
	i[2] += 1;
	if (NULL != line[4])
		return (0);
	return (1);
}
