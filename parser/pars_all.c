#include "minirt.h"
#include "get_next_line.h"
#include "libft.h"

int			parsing_values(char *names, char **line, t_rt *scene)
{
	int		index[7];

	ft_index(index);
	if (0 == (ft_strncmp("R", names, 2)))
		return(parse_resolution(line, scene));
	else if (0 == (ft_strncmp("A", names, 2)))
		return(parse_alight(line, scene));
	else if (0 == (ft_strncmp("c", names, 2)))
		return(parse_cam(line, scene, index));
	else if (0 == (ft_strncmp("l", names, 2)))
		return(parse_light(line, scene, index));
	else if (0 == (ft_strncmp("sp", names, 2)))
		return(parse_sphere(line, scene, index));
	else if (0 == (ft_strncmp("pl", names, 2)))
		return(parse_plane(line, scene, index));
	else if (0 == (ft_strncmp("sq", names, 2)))
		return(parse_square(line, scene, index));
	else if (0 == (ft_strncmp("cy", names, 2)))
		return(parse_cylinder(line, scene, index));
	else if (0 == (ft_strncmp("tr", names, 2)))
		return(parse_triangle(line, scene, index));
	else
		return (0);	
	return (1);
}

int			check_line_parse(char **line, t_rt *scene)
{
	int		i;
	char	*names[] = {"R", "A", "c", "l", "sp", "pl",
			"sq", "cy", "tr", NULL};
	char	flag;
	char	**check;
	
	i = -1;
	flag = 0;
	check = ft_split(*line, "\t\v\f\r ");
	// free_and_null(line, 0);
	while (names[++i] != NULL && **line != 0)
		if (0 == (ft_strncmp(check[0], names[i], 2)))
		{
			flag = 1;
			parsing_values(names[i], check, scene);
		}
	if (!flag && **line != 0)
		return (0);
	ft_free(check);
	return (1);	
}

int			parse_after_count(char **join, t_rt *scene)
{
	char	*arg;

	while (**join != 0)
	{
		if (!(arg = next_argument_check(join)))
			return (0);
		if (!(check_line_parse(&arg, scene)))
			return (0);
	}
	return (1);
}