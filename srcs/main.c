#include "minirt.h"
#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"

// t_rt			alloc_main

int				check_argc(int argc, char **argv, t_rt *scene)
{
	if (argc < 2)
	{
		write(2, "Error\nNot enough arguments, add file name-scene\n", 49);
		return (-1);
	}
	if (argc > 3)
	{
		write(2, "Error\nToo much arguments\n", 26);
		return (-1);
	}
	if (argc == 2 && (0 == (ft_strncmp(argv[1], "--save", 7))))
	{
		write(2, "Error\nEmpty \"save\" argument, add file name-scene\n", 50);
		return (-1);
	}
	if (1 != (check_scene_arg(argv, scene)))
		return (0);
	return (1);
}
int			branching(int argc, char **argv, t_rt *scene)
{
	if (!(check_argc(argc, argv, scene)))
		return (0);
	return (1);
}
int				main(int argc, char *argv[])
{
	static t_rt	scene;

	if (!(branching(argc ,argv, &scene)))
		return (-1);
    return (0);
}