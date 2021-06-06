/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:58:56 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:59:04 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			vec_to_int_color(t_vec color)
{
	int		ret;

	ret = (int)color.x << 16 | (int)color.y << 8;
	ret += (int)color.z;
	return (ret);
}

int			check_extention(char *name)
{
	int		i;
	int		ret;

	ret = 1;
	i = ft_strlen(name);
	ret = (name[--i] == 't') ? 1 : 0;
	ret = (name[--i] == 'r') ? 1 : 0;
	ret = (name[--i] == '.') ? 1 : 0;
	return (ret);
}
