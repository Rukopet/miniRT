/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:40:00 by egums             #+#    #+#             */
/*   Updated: 2020/12/10 07:40:03 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_int_out_help(t_param *param, char *string)
{
	check_width_len(string, param);
	if (param->minus)
	{
		if (param->sign_int == '-')
		{
			param->count += ft_putstr_int("-", 1);
			param->width--;
		}
		out_int_digits(param, string, param->minus);
	}
	else
		no_param_minus(param, string);
}

void		ft_char_out_help(int len, t_param *param, char tmp_sym,
char *string)
{
	param->precision = (param->precision > len) ? len : param->precision;
	param->width = (param->width > param->precision) ?
	param->width - param->precision : 0;
	param->count += out_spaces(tmp_sym, param->width);
	param->count += out_with_precision(string, param->precision, param);
}
