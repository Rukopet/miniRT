/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 03:40:11 by egums             #+#    #+#             */
/*   Updated: 2020/11/25 03:40:16 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int			out_with_precision(char *c, int len, t_param *param)
{
	int		count;

	count = 0;
	if (*c == 0 && param->type == 'c')
	{
		ft_putchar_fd(*c, 1);
		count++;
		return (count);
	}
	while (*c && len)
	{
		ft_putchar_fd(*c, 1);
		c++;
		len--;
		count++;
	}
	return (count);
}

int			out_spaces(char sym, int len)
{
	int		count;

	count = 0;
	while (len)
	{
		write(1, &sym, 1);
		len--;
		count++;
	}
	return (count);
}

void		string_no_width(char *tmp, t_param *param, char tmp_sym)
{
	int		len;
	int		tmp_num;

	len = ft_strlen_char(tmp, param);
	if (param->width == 0 && param->precision != 0)
		param->count += out_with_precision(tmp, param->precision, param);
	if (param->width == 0 && param->precision == 0)
		param->count += ft_putstr_chars(tmp, 1, param);
	if (param->width && param->precision == 0 && param->precision_minus != 3)
	{
		param->width = (param->width < len) ? len : param->width;
		if (param->minus)
		{
			param->count += out_with_precision(tmp, param->width, param);
			param->width = param->width - len;
			param->count += out_spaces(tmp_sym, param->width);
		}
		else
		{
			tmp_num = param->width - len;
			param->count += out_spaces(tmp_sym, tmp_num);
			param->width -= tmp_num;
			param->count += out_with_precision(tmp, param->width, param);
		}
	}
}

void		string_char_out(char *string, t_param *param)
{
	char	tmp_sym;
	int		len;

	tmp_sym = (param->zero == 1) ? '0' : ' ';
	if ((param->width_minus != 0 && param->precision_minus != 0) || param->type
	== 'c')
	{
		len = ft_strlen_char(string, param);
		if (param->minus)
		{
			param->precision = (param->precision > len) ? len :
			param->precision;
			param->count += out_with_precision(string, param->precision, param);
			param->width = (param->width > param->precision) ?
					param->width - param->precision : 0;
			param->count += out_spaces(tmp_sym, param->width);
		}
		else
			ft_char_out_help(len, param, tmp_sym, string);
	}
	else
		string_no_width(string, param, tmp_sym);
}

void		take_arg(va_list args, t_param *param)
{
	char	*tmp;

	tmp = va_arg(args, char *);
	if (tmp == NULL)
	{
		string_char_out("(null)", param);
		return ;
	}
	if (param->precision_minus == 3)
	{
		ft_precision_zero(param);
		return ;
	}
	string_char_out(tmp, param);
}
