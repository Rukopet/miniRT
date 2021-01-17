/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 02:18:32 by egums             #+#    #+#             */
/*   Updated: 2020/11/26 02:18:33 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		check_precision_len(char *string, t_param *param)
{
	int		number;

	number = ft_strlen(string);
	param->precision = (param->precision <= number) ? number : param->precision;
	if (param->precision_minus == 1 && param->zero == 1)
	{
		param->precision = param->width - number;
		if (param->sign_int == '-' && param->width > 0)
			param->precision--;
	}
}

void		if_param_minus(t_param *param, char *string)
{
	int		len;

	len = ft_strlen(string);
	param->width -= param->precision;
	if (param->sign_int == '-')
	{
		param->count += ft_putstr_int("-", 1);
		param->width--;
	}
	while (param->precision != len)
	{
		param->count += ft_putstr_int("0", 1);
		param->precision--;
	}
	len = ft_putstr_int(string, 1);
	param->count += len;
	while (param->width > 0)
	{
		param->count += ft_putstr_int(" ", 1);
		param->width--;
	}
}

void		else_param_minus(t_param *param, char *string)
{
	int		len;
	char	flag;

	len = ft_strlen(string);
	flag = 0;
	while (param->precision != param->width)
	{
		flag++;
		if (param->precision == param->width - 1 &&
			param->sign_int == '-')
		{
			param->count += ft_putstr_int("-", 1);
			param->width--;
			break ;
		}
		else
			param->count += ft_putstr_int(" ", 1);
		param->width--;
	}
	while (param->precision != len)
		ft_param_minus_help(param, &flag);
	param->count += ft_putstr_int(string, 1);
}

void		check_param_donly(t_param *param, char *string)
{
	int		len;

	len = ft_strlen(string);
	check_precision_len(string, param);
	if (param->sign_int == '-')
		param->count += ft_putstr_int("-", 1);
	while (len != param->precision)
	{
		param->count += ft_putstr_int("0", 1);
		param->precision--;
	}
	param->count += ft_putstr_int(string, 1);
}

void		check_param_wd(t_param *param, char *string)
{
	int		len;

	len = ft_strlen(string);
	if (param->width_minus != 0 && param->precision_minus != 0)
	{
		check_precision_len(string, param);
		check_width_len(string, param);
		if (param->minus)
			if_param_minus(param, string);
		else
			else_param_minus(param, string);
	}
	else
	{
		check_param_donly(param, string);
	}
}
