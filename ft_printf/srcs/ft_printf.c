/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:17:43 by egums             #+#    #+#             */
/*   Updated: 2020/11/13 17:26:29 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

int				check_iteration_out(const char *format, va_list args, t_param
*param)
{
	if (*format == '%')
	{
		string_char_out("%", param);
		format++;
		return (0);
	}
	else if (*format == 's')
		take_arg(args, param);
	else if (*format == 'd' || *format == 'i')
		take_int_args(args, param);
	else if (*format == 'c')
		check_char(args, param);
	else if (*format == 'u')
		take_int_args(args, param);
	else if (*format == 'x' || *format == 'X')
		take_int_args(args, param);
	else if (*format == 'p')
		take_int_args(args, param);
	else
		return (1);
	return (0);
}

int				check_iteration_params(const char *format, va_list args,
		t_param *param)
{
	char		*tmp;

	tmp = (char *)format;
	param->type = ft_param(tmp);
	check_minus(format, param);
	check_zero(format, param);
	check_width(format, args, param);
	check_precision(format, args, param);
	while (!check_param(*tmp))
		tmp++;
	param->pointer = tmp;
	return (0);
}

int				check_format(const char *format, va_list args, t_param *param)
{
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			check_iteration_params(format + 1, args, param);
			if (check_iteration_out(param->pointer, args, param))
				return (1);
			format = param->pointer;
			param = default_param_t(param);
		}
		else
		{
			if (*format == '%')
				ft_check_format_help(&format, param, 1);
			else
				ft_check_format_help(&format, param, 2);
		}
		if (!*format)
			break ;
		format++;
	}
	return (param->count);
}

int				ft_printf(const char *format, ...)
{
	va_list			args;
	static t_param	param;
	int				ret;

	default_param_t(&param);
	param.count = 0;
	va_start(args, format);
	ret = check_format(format, args, &param);
	va_end(args);
	return (ret);
}
