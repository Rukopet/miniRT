/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_values_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:00:08 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:00:34 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			write_error_withpars(const char *line)
{
	write(2, &line, ft_strlen(line));
	return (0);
}

void		check_args(char **line, int v)
{
	int		i;

	i = 0;
	while (line[i] != NULL)
		i++;
	if (i != v)
		errors_and_exit(4, NULL);
}

int			parse_plane(char **line, t_rt *s, int *i)
{
	char	*tmp;

	check_args(line, 4);
	tmp = line[1];
	s->pl[i[3]]->x = ft_atof_ptr(&tmp);
	s->pl[i[3]]->y = ft_atof_ptr(&tmp);
	s->pl[i[3]]->z = ft_atof_ptr(&tmp);
	tmp = line[2];
	s->pl[i[3]]->vec_x = ft_atof_ptr(&tmp);
	s->pl[i[3]]->vec_y = ft_atof_ptr(&tmp);
	s->pl[i[3]]->vec_z = ft_atof_ptr(&tmp);
	tmp = line[3];
	s->pl[i[3]]->r = ft_atof_ptr(&tmp);
	s->pl[i[3]]->g = ft_atof_ptr(&tmp);
	s->pl[i[3]]->b = ft_atof_ptr(&tmp);
	i[3] += 1;
	if (NULL != line[4])
		return (0);
	return (1);
}

int			parse_square(char **line, t_rt *s, int *i)
{
	char	*tmp;

	check_args(line, 5);
	tmp = line[1];
	s->sq[i[4]]->x = ft_atof_ptr(&tmp);
	s->sq[i[4]]->y = ft_atof_ptr(&tmp);
	s->sq[i[4]]->z = ft_atof_ptr(&tmp);
	tmp = line[2];
	s->sq[i[4]]->vec_x = ft_atof_ptr(&tmp);
	s->sq[i[4]]->vec_y = ft_atof_ptr(&tmp);
	s->sq[i[4]]->vec_z = ft_atof_ptr(&tmp);
	tmp = line[3];
	s->sq[i[4]]->side_size = ft_atof_ptr(&tmp);
	tmp = line[4];
	s->sq[i[4]]->r = ft_atoi_ptr(&tmp);
	s->sq[i[4]]->g = ft_atoi_ptr(&tmp);
	s->sq[i[4]]->b = ft_atoi_ptr(&tmp);
	i[4] += 1;
	if (NULL != line[5])
		return (0);
	return (1);
}

int			parse_cylinder(char **line, t_rt *s, int *i)
{
	char	*tmp;

	check_args(line, 6);
	tmp = line[1];
	s->cy[i[5]]->x = ft_atof_ptr(&tmp);
	s->cy[i[5]]->y = ft_atof_ptr(&tmp);
	s->cy[i[5]]->z = ft_atof_ptr(&tmp);
	tmp = line[2];
	s->cy[i[5]]->vec_x = ft_atof_ptr(&tmp);
	s->cy[i[5]]->vec_y = ft_atof_ptr(&tmp);
	s->cy[i[5]]->vec_z = ft_atof_ptr(&tmp);
	tmp = line[3];
	s->cy[i[5]]->diameter = ft_atof_ptr(&tmp);
	tmp = line[4];
	s->cy[i[5]]->height = ft_atof_ptr(&tmp);
	tmp = line[5];
	s->cy[i[5]]->r = ft_atoi_ptr(&tmp);
	s->cy[i[5]]->g = ft_atoi_ptr(&tmp);
	s->cy[i[5]]->b = ft_atoi_ptr(&tmp);
	i[5] += 1;
	if (NULL != line[6])
		return (0);
	return (1);
}
