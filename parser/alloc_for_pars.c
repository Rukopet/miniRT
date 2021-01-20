#include "minirt.h"
#include "libft.h"
#include "get_next_line.h"


char		*join_free(char **save, char *join, char ***line)
{
	char	*tmp;
	
	tmp = join;
	if (NULL == (join = ft_strjoin(*save, tmp)))
		return (NULL);
	free_and_null(&tmp, 0);
	free_and_null(save, 0);
	ft_free(*line);
	return (join);
}