/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:59:20 by egums             #+#    #+#             */
/*   Updated: 2020/11/14 16:59:22 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

t_param			*default_param_t(t_param *ret)
{
	ret->width = 0;
	ret->precision = 0;
	ret->minus = 0;
	ret->zero = 0;
	ret->type = 0;
	ret->pointer = NULL;
	ret->sign_int = 1;
	ret->precision_minus = 0;
	ret->width_minus = 0;
	ret->flag_null = 0;
	return (ret);
}

int				check_param(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

void			check_minus(const char *c, t_param *param)
{
	char		i;

	i = 0;
	while (*c != '%' && *c && !check_param(*c) && i != 2)
	{
		if (*c == '-')
			param->minus = 1;
		c++;
		i++;
	}
}

int				check_minus_char(char c, t_param *param)
{
	if (c == '-')
	{
		param->minus = 1;
		return (1);
	}
	return (0);
}

char			ft_param(const char *c)
{
	while (*c != '%' && *c)
	{
		if (check_param(*c))
			return (*c);
		c++;
	}
	return (0);
}
