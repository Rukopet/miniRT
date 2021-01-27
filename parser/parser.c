#include "get_next_line.h"
#include "minirt.h"
#include "libft.h"
#include "fcntl.h"
#include "stdio.h"

int			pars_branching(t_rt *scene, int fd, t_count *counter)
{
	int		i;
	char	*gnl;
	char	*join;

	while (0 < (i = get_next_line(fd, &gnl )))
		if (!(join_str(&gnl, &join)))
			return (free_and_null(&gnl, -1));
	i = (i == -1) ?  i : get_next_line(fd, &gnl);
	if (i == -1)
		return (free_and_null(&join, -1));
	if (!(join_str(&gnl, &join)))
		return (free_and_null(&join, -1));
		if (!work_with_counter_br(&join, counter, scene))
			return (-1);
	return (1);

	// while ((i = get_next_line(fd, &gnl)))
	// {
	// 	line = ft_split(gnl, "\t\v\f\r ");
	// 	if (!(check_line(line, scene, counter)) ||
	// 		NULL == (join = join_free(&gnl, join, &line)))
	// 		return (0);
	// }
	// if (i < 0 || -1 == (get_next_line(fd, &gnl)))
	// 	return (0);
	// line = ft_split(gnl, "\n\t\v\f ");
	// if (!(check_line(line, scene, counter)) ||
	// 	NULL == (join = join_free(&gnl, join, &line)))
	// 	return (0);
}

int			check_other(t_rt *scene, int fd)
{
	t_count	*counter;

	if(!(counter = malloc(sizeof(t_count))))
		erros_and_exit(-1, scene);
	init_count_struct(counter);
	if (-1 == (pars_branching(scene, fd, counter)))
	{
		free(counter);
		return (0);
	}
	free(counter);
	return (1);
}

int			check_scene_arg(char **argv, t_rt *scene, int argc)
{
	int		fd;
	char	save_flag;
	char	*tmp;
	int		i;

	i = 1;
	save_flag = 0;
	fd = 0;
	while (argv[i] != NULL)
	{
		if (0 == (ft_strncmp(argv[i], "--save", 7)))
			save_flag = 1;
		else
			tmp = argv[i];		
		i++;
	}
	if ((argc == 3 && !save_flag) || -1 == (fd = open(tmp, O_RDONLY)))
		erros_and_exit(4, scene);
	if (!(check_other(scene, fd)))
		erros_and_exit(6, scene);
	return (1);
	//dich
}
