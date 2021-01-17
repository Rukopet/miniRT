/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:32:50 by egums             #+#    #+#             */
/*   Updated: 2020/12/07 10:32:52 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

char		*ft_help_itoa(t_param *param, char *sign, int *check, long int *nb)
{
	char	*ret;

	if (*nb < 0)
	{
		*sign = '-';
		*nb *= -1;
	}
	*check = (param->type == 'p') ? 2 : 0;
	if (param->type == 'X')
		ret = ft_strdup("0123456789ABCDEF");
	else
		ret = ft_strdup("0123456789abcdef");
	return (ret);
}

void		ft_check_format_help(const char **tmp, t_param *param, char flag)
{
	if (flag == 1)
	{
		ft_putchar_fd(**tmp, 1);
		(*tmp)++;
		param->count++;
	}
	else
	{
		ft_putchar_fd(**tmp, 1);
		param->count++;
	}
}

int			ft_integers(va_list args, t_param *param)
{
	int		number;

	number = 0;
	if (param->type == 'i' || param->type == 'd')
	{
		number = va_arg(args, int);
		digits_int_out(number, param);
		return (number);
	}
	return (number);
}

void		ft_param_minus_help(t_param *param, char *flag)
{
	if (*flag == 0 && param->sign_int == '-')
	{
		param->count += ft_putstr_int("-", 1);
		param->width--;
		*flag += 1;
	}
	param->count += ft_putstr_int("0", 1);
	param->precision--;
}

void		ft_no_minus_help(int len, t_param *param, char *string)
{
	while (len != param->width)
	{
		write(1, " ", 1);
		param->width--;
		param->count++;
	}
	if (param->sign_int == '-')
	{
		param->count += ft_putstr_int("-", 1);
		param->width--;
	}
	param->count += ft_putstr_int(string, 1);
}
