/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:59:56 by egums             #+#    #+#             */
/*   Updated: 2021/01/12 20:00:09 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_strchr_r(const char *s, int c)
{
	int				index;

	index = 0;
	if (!s)
		return (0);
	while (s[index] != 0)
	{
		if (s[index] == c)
			return (1);
		index++;
	}
	return (0);
}
