/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:03:07 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:03:15 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	pars(char **line, t_rt *s, int *i)
{
	char	*tmp;

	tmp = line[4];
	s->tr[i[6]]->r = ft_atof_ptr(&tmp);
	s->tr[i[6]]->g = ft_atof_ptr(&tmp);
	s->tr[i[6]]->b = ft_atof_ptr(&tmp);
}

int			parse_triangle(char **line, t_rt *s, int *i)
{
	char	*tmp;

	tmp = line[1];
	s->tr[i[6]]->first_x = ft_atof_ptr(&tmp);
	s->tr[i[6]]->first_y = ft_atof_ptr(&tmp);
	s->tr[i[6]]->first_z = ft_atof_ptr(&tmp);
	tmp = line[2];
	s->tr[i[6]]->second_x = ft_atof_ptr(&tmp);
	s->tr[i[6]]->second_y = ft_atof_ptr(&tmp);
	s->tr[i[6]]->second_z = ft_atof_ptr(&tmp);
	tmp = line[3];
	s->tr[i[6]]->third_x = ft_atof_ptr(&tmp);
	s->tr[i[6]]->third_y = ft_atof_ptr(&tmp);
	s->tr[i[6]]->third_z = ft_atof_ptr(&tmp);
	pars(line, s, i);
	if (line[5] != NULL)
		return (0);
	i[6] += 1;
	return (1);
}
