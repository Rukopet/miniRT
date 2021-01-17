/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_zero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:14:42 by egums             #+#    #+#             */
/*   Updated: 2020/11/29 20:14:46 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision_zero(t_param *param)
{
	while (param->width != 0)
	{
		param->count += ft_putstr_chars(" ", 1, param);
		param->width--;
	}
}
