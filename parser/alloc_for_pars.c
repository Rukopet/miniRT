#include "minirt.h"
#include "libft.h"

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

int			check_line(char **line, t_count *counter)
{
	int		i;
	char	*names;
	char	flag;
	char	**check;

	i = -1;
	flag = 0;
	check = ft_split(*line, "\t\v\f\r ");
	while (++i != 9)
	{
		names = init_values_pars(i);
		if (0 == (ft_strncmp(check[0], names, 2)))
		{
			flag = 1;
			count_plus(names, counter);
		}
	}

	if (!flag)
		return (0);
	ft_free(check);
	// free(*check);
	return (1);	
}

char		*next_argument_check(char **join)
{
	char	*begin;
	char	*ret;
	char	*line_check;
	int		i;
	int		len;

	begin = *join;
	i = -1;
	if (!(line_check = malloc(len = ft_strlen_n(begin, 1) + 1)))
		return (NULL);
	line_check[len] = 0;
	while (*begin != '\n' && *begin)
		line_check[++i] = *begin++;
	if(!(ret = malloc(len = ft_strlen_n(begin, 0) + 1)))
		return (NULL);
	ret[len] = 0;
	begin = (*begin == '\n') ? begin + 1 : begin;
	ft_memcpy(ret, begin, len);
	free_and_null(join, 0);
	*join = ret;
	return (line_check);
}

int			work_with_counter_br(char **join, t_count *counter, t_rt *scene)
{
	char	*arg;
	char	*begin;

	begin = ft_strdup(*join);
	while (**join != 0)
	{
		if (!(arg = next_argument_check(join)))
			return (0);
		if (**join == 0)
			break ;
		if (!(check_line(&arg, counter)))
			return (0);
		// if (!(parse_all(scene, counter)))
		// 	return (free_scene(scene, 0));
	}
	if (!count_validate(counter, scene))
		return (0);
	if (!parse_after_count(&begin, scene))
		return (0);
	
	// print_counter(counter);
	return (1);
}
int			join_str(char **gnl, char **join)
{
	char	*tmp;

	tmp = *gnl;
	if (!(*gnl = ft_strjoin(tmp, "\n")))
		return (0);
	free_and_null(&tmp, 0);
	tmp = *join;
	if (!(*join = ft_strjoin(tmp, *gnl)))
		return (0);
	free_and_null(&tmp, 0);
	return (1);
}