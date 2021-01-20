#include "get_next_line.h"
#include "minirt.h"
#include "libft.h"
#include "fcntl.h"
#include "stdio.h"


int			count_plus(char *names, t_count *counter)
{
	if (0 == (ft_strncmp("R", names, 2)))
		counter->resolution += 1;
	else if (0 == (ft_strncmp("A", names, 2)))
		counter->a_light += 1;
	else if (0 == (ft_strncmp("c", names, 2)))
		counter->cam += 1;
	else if (0 == (ft_strncmp("l", names, 2)))
		counter->light += 1;
	else if (0 == (ft_strncmp("sp", names, 2)))
		counter->sp += 1;
	else if (0 == (ft_strncmp("pl", names, 2)))
		counter->pl += 1;
	else if (0 == (ft_strncmp("sq", names, 2)))
		counter->sq += 1;
	else if (0 == (ft_strncmp("cy", names, 2)))
		counter->cy += 1;
	else if (0 == (ft_strncmp("tr", names, 2)))
		counter->tr += 1;
	else
		return (0);	
	return (1);
}

int			check_line(char **line, t_rt *scene, t_count *counter)
{
	int		i;
	char	*names[] = {"R", "A", "c", "l", "sp", "pl",
			"sq", "cy", "tr", NULL};
	char	flag;

	i = 0;
	flag = 0;
	while (names[i] != NULL)
	{
		if (0 == (ft_strncmp(line[0], names[i], 2)))
		{
			flag = 1;
			i++;
			count_plus(names[i], counter);
		}
	}
	if (!flag)
		return (0);
	return (1);	
}

int			pars_branching(t_rt *scene, int fd, t_count *counter)
{
	int		i;
	char	*gnl;
	char	**line;
	char	*join;

	while ((i = get_next_line(fd, &gnl)))
	{
		line = ft_split(gnl, "\t\v\f\r ");
		if (!(check_line(line, scene, counter)) ||
			NULL == (join = join_free(&gnl, join, &line)))
			return (0);
	}
	if (i < 0 || -1 == (get_next_line(fd, &gnl)))
		return (0);
	line = ft_split(gnl, "\n\t\v\f ");
	if (!(check_line(line, scene, counter)) ||
		NULL == (join = join_free(&gnl, join, &line)))
		return (0);
	return (1);
}

int			check_other(t_rt *scene, int fd)
{
	t_count	*counter;

	if(!(counter = malloc(sizeof(t_count))))
		return (0);
	init_count_struct(counter);
	if (!(pars_branching(scene, fd, counter)))
	{
		free(counter);
		return (0);
	}
	// scene = alloc_pars_br(counter)
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
	while (argv[i] != NULL)
	{
		if (0 == (ft_strncmp(argv[i], "--save", 7)))
			save_flag = 1;
		else
			tmp = argv[i];		
		i++;
	}
	if ((argc == 3 && !save_flag) || -1 == (fd = open(tmp, O_RDONLY)))
	{
		write(2, "Error\nBad arguments\n", 21);
		return (0);
	}	
	if (!(check_other(scene, fd)))
		return (0);
	return (1);
	//dich
}
