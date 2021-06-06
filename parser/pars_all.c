/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:12:23 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 12:23:02 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char				*init_values_pars(int index)
{
	if (index == 0)
		return ("R");
	if (index == 1)
		return ("A");
	if (index == 2)
		return ("c");
	if (index == 3)
		return ("l");
	if (index == 4)
		return ("sp");
	if (index == 5)
		return ("pl");
	if (index == 6)
		return ("sq");
	if (index == 7)
		return ("cy");
	if (index == 8)
		return ("tr");
	else
		return (NULL);
}

int					parsing_values(char *names, char **line, t_rt *scene)
{
	static int		index[6] = {0, 0, 0, 0, 0, 0};

	if (0 == (ft_strncmp("R", names, 2)))
		return (parse_resolution(line, scene));
	else if (0 == (ft_strncmp("A", names, 2)))
		return (parse_alight(line, scene));
	else if (0 == (ft_strncmp("c", names, 2)))
		return (parse_cam(line, scene, index));
	else if (0 == (ft_strncmp("l", names, 2)))
		return (parse_light(line, scene, index));
	else if (0 == (ft_strncmp("sp", names, 3)))
		return (parse_sphere(line, scene, index));
	else if (0 == (ft_strncmp("pl", names, 3)))
		return (parse_plane(line, scene, index));
	else if (0 == (ft_strncmp("sq", names, 3)))
		return (parse_square(line, scene, index));
	else if (0 == (ft_strncmp("cy", names, 3)))
		return (parse_cylinder(line, scene, index));
	else if (0 == (ft_strncmp("tr", names, 3)))
		return (parse_triangle(line, scene, index));
	else
		return (0);
}

int					check_line_parse(char **line, t_rt *scene)
{
	int				i;
	char			*names;
	char			flag;
	char			**check;

	i = -1;
	flag = 0;
	check = ft_split(*line, "\t\v\f\r ");
	while (++i != 9 && **line != 0)
	{
		names = init_values_pars(i);
		if (0 == (ft_strncmp(check[0], names, 2)))
		{
			flag = 1;
			parsing_values(names, check, scene);
			break ;
		}
	}
	if (!flag && **line != 0)
		return (0);
	ft_free(check);
	return (1);
}

int					parse_after_count(char **join, t_rt *scene)
{
	char			*arg;

	while (**join != 0)
	{
		if (!(arg = next_argument_check(join)))
			return (0);
		if (!(check_line_parse(&arg, scene)))
			return (0);
		free(arg);
	}
	validator(scene);
	return (1);
}
