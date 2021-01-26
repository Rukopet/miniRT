#include "minirt.h"
#include "libft.h"

int			write_error_withpars(const char *line)
{
	write (2, &line, ft_strlen(line));
	return (0);
}
int			parse_plane(char **line, t_rt *s, int *i)
{
	s->pl[i[3]]->x = ft_atof(line[1]);
	s->pl[i[3]]->y = ft_atof(line[2]);
	s->pl[i[3]]->z = ft_atof(line[3]);

	s->pl[i[3]]->vec_x = ft_atof(line[4]);
	s->pl[i[3]]->vec_y = ft_atof(line[5]);
	s->pl[i[3]]->vec_z = ft_atof(line[6]);

	s->pl[i[3]]->r = ft_atoi(line[7]);
	s->pl[i[3]]->r = (s->pl[i[3]]->r < 0) ? 0 : s->pl[i[3]]->r;
	s->pl[i[3]]->r = (s->pl[i[3]]->r > 255) ? 255 : s->pl[i[3]]->r;

	s->pl[i[3]]->g = ft_atoi(line[8]);
	s->pl[i[3]]->g = (s->pl[i[3]]->g < 0) ? 0 : s->pl[i[3]]->g;
	s->pl[i[3]]->g = (s->pl[i[3]]->g > 255) ? 255 : s->pl[i[3]]->g;
	
	s->pl[i[3]]->b = ft_atoi(line[9]);
	s->pl[i[3]]->b = (s->pl[i[3]]->b < 0) ? 0 : s->pl[i[3]]->b;
	s->pl[i[3]]->b = (s->pl[i[3]]->b > 255) ? 255 : s->pl[i[3]]->b;
	i[3] += 1;
	if (NULL != line[10])
		return (0);
	return (1);
}

int			parse_square(char **line, t_rt *s, int *i)
{
	s->sq[i[4]]->x = ft_atof(line[1]);
	s->sq[i[4]]->y = ft_atof(line[2]);
	s->sq[i[4]]->z = ft_atof(line[3]);

	s->sq[i[4]]->vec_x = ft_atof(line[4]);
	s->sq[i[4]]->vec_y = ft_atof(line[5]);
	s->sq[i[4]]->vec_z = ft_atof(line[6]);

	s->sq[i[4]]->side_size = ft_atof(line[7]);
	s->sq[i[4]]->r = ft_atoi(line[7]);
	s->sq[i[4]]->r = (s->sq[i[3]]->r < 0) ? 0 : s->sq[i[4]]->r;
	s->sq[i[4]]->r = (s->sq[i[3]]->r > 255) ? 255 : s->sq[i[4]]->r;

	s->sq[i[4]]->g = ft_atoi(line[8]);
	s->sq[i[4]]->g = (s->sq[i[3]]->g < 0) ? 0 : s->sq[i[4]]->g;
	s->sq[i[4]]->g = (s->sq[i[3]]->g > 255) ? 255 : s->sq[i[4]]->g;
	
	s->sq[i[4]]->b = ft_atoi(line[9]);
	s->sq[i[4]]->b = (s->sq[i[3]]->b < 0) ? 0 : s->sq[i[4]]->b;
	s->sq[i[4]]->b = (s->sq[i[3]]->b > 255) ? 255 : s->sq[i[4]]->b;
	i[4] += 1;
	if (NULL != line[10])
		return (0);
	return (1);
}

int			parse_cylinder(char **line, t_rt *s, int *i)
{
	s->cy[i[5]]->x = ft_atof(line[1]);
	s->cy[i[5]]->y = ft_atof(line[2]);
	s->cy[i[5]]->z = ft_atof(line[3]);

	s->cy[i[5]]->vec_x = ft_atof(line[4]);
	s->cy[i[5]]->vec_y = ft_atof(line[5]);
	s->cy[i[5]]->vec_z = ft_atof(line[6]);

	s->cy[i[5]]->diameter = ft_atof(line[7]);
	s->cy[i[5]]->height = ft_atof(line[8]);
	s->cy[i[5]]->r = ft_atoi(line[8]);
	s->cy[i[5]]->r = (s->cy[i[5]]->r < 0) ? 0 : s->cy[i[5]]->r;
	s->cy[i[5]]->r = (s->cy[i[5]]->r > 255) ? 255 : s->cy[i[5]]->r;

	s->cy[i[5]]->g = ft_atoi(line[9]);
	s->cy[i[5]]->g = (s->pl[i[3]]->g < 0) ? 0 : s->cy[i[5]]->g;
	s->cy[i[5]]->g = (s->pl[i[3]]->g > 255) ? 255 : s->cy[i[5]]->g;
	
	s->cy[i[5]]->b = ft_atoi(line[10]);
	s->cy[i[5]]->b = (s->cy[i[5]]->b < 0) ? 0 : s->cy[i[5]]->b;
	s->cy[i[5]]->b = (s->cy[i[5]]->b > 255) ? 255 : s->cy[i[5]]->b;
	i[5] += 1;
	if (NULL != line[11])
		return (0);
	return (1);
}

int			parse_triangle(char **line, t_rt *s, int *i)
{
	s->tr[i[6]]->first = ft_atof(line[1]);
	s->tr[i[6]]->second = ft_atof(line[2]);
	s->tr[i[6]]->third = ft_atof(line[3]);

	s->tr[i[6]]->r = ft_atoi(line[4]);
	s->tr[i[6]]->r = (s->tr[i[6]]->r < 0) ? 0 : s->tr[i[6]]->r;
	s->tr[i[6]]->r = (s->tr[i[6]]->r > 255) ? 255 : s->tr[i[6]]->r;
	s->tr[i[6]]->g = ft_atoi(line[5]);
	s->tr[i[6]]->g = (s->tr[i[6]]->g < 0) ? 0 : s->tr[i[6]]->g;
	s->tr[i[6]]->g = (s->tr[i[6]]->g > 255) ? 255 : s->tr[i[6]]->g;
	s->tr[i[6]]->b = ft_atoi(line[6]);
	s->tr[i[6]]->b = (s->tr[i[6]]->b < 0) ? 0 : s->tr[i[6]]->b;
	s->tr[i[6]]->b = (s->tr[i[6]]->b > 255) ? 255 : s->tr[i[6]]->b;
	if (line[7] != NULL)
		return (0);
	i[6] += 1;
	return (1);
}