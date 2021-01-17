/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:19:40 by egums             #+#    #+#             */
/*   Updated: 2020/11/27 19:19:42 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int			ft_strlen_char(char *s, t_param *param)
{
	size_t			len;

	len = 0;
	if (param->type == 'c')
	{
		if (*s == 0)
			return (1);
	}
	while (*s++)
		len++;
	return (len);
}

void		check_char(va_list args, t_param *param)
{
	char	tmp;
	char	b[2];

	tmp = va_arg(args, int);
	param->type = 'c';
	b[0] = tmp;
	b[1] = '\0';
	param->precision = 1;
	string_char_out(&tmp, param);
}
