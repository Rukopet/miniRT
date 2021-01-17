#include "minirt.h"
#include "ft_printf.h"
#include "mlx.h"

t_rt			alloc_main

int				check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		write(2, "Error\nnot enough arguments, add file name-scene", 48);
		return (-1)
	}
	if (argc > )
	}
}
t_rt			*branching(int argc, char **argv)
{
	t_rt		*scene;

	if (!(check_args(argc, argv, &scene)))
		return (NULL);
}
int				main(int argc, char *argv[])
{
	t_rt		*scene;
	if (!(scene = branching(argc ,argv)))
		return (-1);
    return (0);
}