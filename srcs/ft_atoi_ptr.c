#include "libft.h"

static int	ret(unsigned long answer, int minus)
{
	unsigned long	ul_max;

	ul_max = 4294967295;
	if (answer > ul_max && minus == -1)
		return (0);
	if (answer > ul_max && minus == 1)
		return (-1);
	if (minus == 1)
		return ((int)answer);
	return ((int)answer * minus);
}

int			ft_atoi_ptr(char **nptr)
{
	int				index;
	int				minus;
	unsigned long	answer;

	index = 0;
	minus = 1;
	answer = 0;
	while (**nptr == '\r' || **nptr == '\v' || **nptr == ' ' ||
			**nptr == '\n' || **nptr == '\f' || **nptr == '\t' ||
			**nptr == ',')
		(*nptr)++;
	if (**nptr == '-')
		minus = -1;
	if (**nptr == '+' || **nptr == '-')
		(*nptr)++;
	while (ft_isdigit(**nptr))
	{
		answer = answer * 10 + **nptr - '0';
		(*nptr)++;
	}
	return (ret(answer, minus));
}