#include "minirt.h"
#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"

void			begin_mlx_work(t_rt *scene)
{
	void		*mlx;
	void		*mlx_win;

	if (NULL == (mlx = mlx_init()))
		erros_and_exit(20, scene);
	mlx_win = mlx_new_window(mlx, scene->resolution->x, scene->resolution->y, "miniRT21");
	mlx_loop(mlx);
}

int				check_argc(int argc, char **argv, t_rt *scene)
{
	if (argc < 2)
		erros_and_exit(1, scene);
	if (argc > 3)
		erros_and_exit(2, scene);
	if (argc == 2 && (0 == (ft_strncmp(argv[1], "--save", 7))))
		erros_and_exit(3, scene);
	if (1 != (check_scene_arg(argv, scene, argc)))
		return (0);
	return (1);
}

int			branching(int argc, char **argv, t_rt *scene)
{
	if (!(check_argc(argc, argv, scene)))
		return (0);
	begin_mlx_work(scene);
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