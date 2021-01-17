/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:14:04 by egums             #+#    #+#             */
/*   Updated: 2020/11/22 18:14:58 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			ft_putstr_int(char *s, int fd)
{
	int		count;

	count = 0;
	if (!s)
		return (count);
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
		count++;
	}
	return (count);
}

int			ft_putstr_chars(char *s, int fd, t_param *param)
{
	int		count;

	count = 0;
	if (s[0] == '\0' && param->type == 'c')
	{
		ft_putchar_fd(s[0], fd);
		count++;
		return (count);
	}
	if (!s)
		return (count);
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
		count++;
	}
	return (count);
}

static int	ft_itoa_base_count(long int nb, int base, t_param *param)
{
	int		i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		nb = nb / base;
		i++;
	}
	if (param->type == 'p')
		i = i + 2;
	return (i);
}

char		*ft_itoa_base(long int nb, int base, char *sign, t_param *param)
{
	char	*ret;
	char	*numbers;
	int		i;
	int		check;

	numbers = ft_help_itoa(param, sign, &check, &nb);
	i = ft_itoa_base_count(nb, base, param);
	if (!(ret = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	ret[i--] = '\0';
	while (i >= check)
	{
		ret[i--] = numbers[nb % base];
		nb = nb / base;
	}
	if (check == 2)
	{
		ret[0] = '0';
		ret[1] = 'x';
	}
	free(numbers);
	return (ret);
}
