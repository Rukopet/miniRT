/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 07:01:13 by egums             #+#    #+#             */
/*   Updated: 2020/11/25 07:01:16 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int			check_zero_precision(char *string, t_param *param)
{
	if (string[0] == '0' && param->precision == 0 &&
	param->precision_minus == 3)
	{
		while (param->width != 0)
		{
			param->count += ft_putstr_int(" ", 1);
			param->width--;
		}
		free(string);
		string = NULL;
		return (1);
	}
	return (0);
}

void		out_int_digits(t_param *param, char *string, char minus)
{
	int		number;

	if (minus != -1)
	{
		number = ft_putstr_int(string, 1);
		param->count += number;
		param->width -= number;
		param->count += out_spaces(' ', param->width);
	}
}

void		no_param_minus(t_param *param, char *string)
{
	int		len;

	len = ft_strlen(string);
	if (param->zero)
	{
		if (param->sign_int == '-')
		{
			param->count += ft_putstr_int("-", 1);
			param->width--;
		}
		while (len != param->width)
		{
			write(1, "0", 1);
			param->width--;
			param->count++;
		}
		param->count += ft_putstr_int(string, 1);
	}
	else
	{
		len = (param->sign_int == '-') ? len + 1 : len;
		ft_no_minus_help(len, param, string);
	}
}

void		check_width_len(char *string, t_param *param)
{
	int		number;

	number = ft_strlen(string);
	number = (param->sign_int == '-') ? number + 1 : number;
	param->width = (param->width < number) ? number : param->width;
	param->width = (param->width < param->precision) ? param->precision :
			param->width;
}

void		digits_int_out(long int digit, t_param *param)
{
	char	*string;

	if (param->type != 'x' && param->type != 'X' && param->type != 'p')
		string = ft_itoa_base(digit, 10, &param->sign_int, param);
	else
		string = ft_itoa_base(digit, 16, &param->sign_int, param);
	if (param->type == 'p')
		check_pointer(&string, param);
	else if (check_zero_precision(string, param))
		return ;
	if (param->width_minus != 0 && param->precision_minus == 0)
		ft_int_out_help(param, string);
	else
		check_param_wd(param, string);
	free(string);
	string = NULL;
}
