#include "minirt.h"
#include "libft.h"

int			count_validate(t_count *counter)
{
	if (counter->resolution >= 2)
	{
		write (2, "Error\nMultiplae resolution options\n", 36);
		return (0);
	}
	if (counter->a_light >= 2)
	{
		write (2, "Error\nMultiplae ambient light options\n", 39);
		return (0);
	}
	return (1);
}