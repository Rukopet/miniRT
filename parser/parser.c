/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:01:54 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:02:22 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	do_line_check(char **join, char *gnl, int *p)
{
	if (*gnl == 0)
	{
		p[0]++;
		free(gnl);
		return ;
	}
	p[1] += 1;
	p[0] = p[1];
	if (!(join_str(&gnl, join)))
		free_and_null(&gnl, -1);
	free(gnl);
}

int			pars_branching(t_rt *scene, int fd, t_count *counter)
{
	int		i;
	char	*gnl;
	char	*join;
	int		p[2];

	join = NULL;
	p[0] = 0;
	p[1] = 0;
	while (0 < (i = get_next_line(fd, &gnl)))
		do_line_check(&join, gnl, p);
	do_line_check(&join, gnl, p);
	if (p[0] - p[1] > 1)
		errors_and_exit(4, scene);
	i = (i == -1) ? i : get_next_line(fd, &gnl);
	if (i == -1)
		errors_and_exit(-1, scene);
	if (!(join_str(&gnl, &join)))
		return (free_and_null(&join, -1));
	free(gnl);
	if (!(work_with_counter_br(&join, counter, scene)))
		return (-1);
	return (1);
}

int			check_other(t_rt *scene, int fd)
{
	t_count	*counter;

	if (!(counter = malloc(sizeof(t_count))))
		errors_and_exit(-1, scene);
	init_count_struct(counter);
	if (-1 == (pars_branching(scene, fd, counter)))
	{
		free(counter);
		return (0);
	}
	scene->counter = counter;
	return (1);
}

int			check_scene_arg(char **argv, t_rt *scene, int argc)
{
	int		fd;
	char	*tmp;
	int		i;

	i = 0;
	fd = 0;
	while (argv[++i] != NULL)
	{
		if (0 == (ft_strncmp(argv[i], "--save", 7)))
		{
			scene->save = 1;
		}
		else
			tmp = argv[i];
	}
	scene->fn = tmp;
	if ((argc == 3 && !scene->save) || -1 == (fd = open(tmp, O_RDONLY)))
		errors_and_exit(4, scene);
	if (!(check_extention(tmp)))
		errors_and_exit(7, scene);
	if (!(check_other(scene, fd)))
		errors_and_exit(6, scene);
	close(fd);
	return (1);
}
