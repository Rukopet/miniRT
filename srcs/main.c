#include "minirt.h"
#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"

int				check_argc(int argc, char **argv, t_rt *scene)
{
	if (argc < 2)
		erros_and_exit(1);
	if (argc > 3)
		erros_and_exit(2);
	if (argc == 2 && (0 == (ft_strncmp(argv[1], "--save", 7))))
		erros_and_exit(3);
	if (1 != (check_scene_arg(argv, scene, argc)))
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

	init_scene_struct(&scene);
	if (!(branching(argc ,argv, &scene)))
		return (-1);
    return (0);
}