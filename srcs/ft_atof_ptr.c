/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:20:53 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 21:25:29 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int			check_e(char ***s)
{
	int				sign;
	int				i;
	char			c;

	(**s)++;
	i = 0;
	sign = 1;
	c = ***s;
	if (c == '+')
		c = (***s)++;
	else if (c == '-')
	{
		c = ***s;
		(**s)++;
		sign = -1;
	}
	while (ft_isdigit(c))
	{
		i = i * 10 + (c - '0');
		c = ***s;
		(**s)++;
	}
	return (i * sign);
}

static double		check_after_dot(char ***s, int *e)
{
	double			a;

	(**s)++;
	a = 0.0;
	while (***s != 0 && ft_isdigit(***s))
	{
		a += a * 10.0 + (***s - '0');
		*e -= 1;
		(**s)++;
	}
	return (a);
}

static double		ret_answ(char ***s, double *a, int e)
{
	if (***s == '.')
		*a += check_after_dot(s, &e);
	if (***s == 'e' || ***s == 'E')
		e += check_e(s);
	while (e > 0)
	{
		*a *= 10.0;
		e--;
	}
	while (e < 0)
	{
		*a *= 0.1;
		e++;
	}
	return (*a);
}

double				ft_atof_ptr(char **s)
{
	double			a;
	int				i[3];

	a = 0.0;
	i[1] = 1;
	i[2] = 0;
	if (**s == ',')
		(*s)++;
	if (**s != '-' && **s != '+' && !ft_isdigit(**s))
		errors_and_exit(10, NULL);
	if ((*i = (int)**s) != '\0' && (*i == '-'))
	{
		*(i + 1) = -1;
		(*s)++;
	}
	while ((*i = (int)**s) != '\0' && ft_isdigit(**s))
	{
		a = a * 10.0 + (*i - '0');
		(*s)++;
	}
	if (!ft_isdigit(**s) && **s != '.' && (**s == '.' && \
	!ft_isdigit(**(s + 1))))
		errors_and_exit(4, NULL);
	return (ret_answ(&s, &a, i[2]) * i[1]);
}
