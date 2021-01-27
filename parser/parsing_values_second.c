#include "minirt.h"
#include "libft.h"

int			write_error_withpars(const char *line)
{
	write (2, &line, ft_strlen(line));
	return (0);
}
int			parse_plane(char **line, t_rt *s, int *i)
{
	char	*tmp;

	tmp = line[1];
	s->pl[i[3]]->x = ft_atof_ptr(&tmp);
	s->pl[i[3]]->y = ft_atof_ptr(&tmp);
	s->pl[i[3]]->z = ft_atof_ptr(&tmp);
	tmp = line[2];
	s->pl[i[3]]->vec_x = ft_atof_ptr(&tmp);
	s->pl[i[3]]->vec_y = ft_atof_ptr(&tmp);
	s->pl[i[3]]->vec_z = ft_atof_ptr(&tmp);
	tmp = line[3];
	s->pl[i[3]]->r = ft_atof_ptr(&tmp);
	s->pl[i[3]]->r = (s->pl[i[3]]->r < 0) ? 0 : s->pl[i[3]]->r;
	s->pl[i[3]]->r = (s->pl[i[3]]->r > 255) ? 255 : s->pl[i[3]]->r;
	s->pl[i[3]]->g = ft_atof_ptr(&tmp);
	s->pl[i[3]]->g = (s->pl[i[3]]->g < 0) ? 0 : s->pl[i[3]]->g;
	s->pl[i[3]]->g = (s->pl[i[3]]->g > 255) ? 255 : s->pl[i[3]]->g;
	s->pl[i[3]]->b = ft_atof_ptr(&tmp);
	s->pl[i[3]]->b = (s->pl[i[3]]->b < 0) ? 0 : s->pl[i[3]]->b;
	s->pl[i[3]]->b = (s->pl[i[3]]->b > 255) ? 255 : s->pl[i[3]]->b;
	i[3] += 1;
	if (NULL != line[4])
		return (0);
	return (1);
}

int			parse_square(char **line, t_rt *s, int *i)
{
	char	*tmp;

	tmp = line[1];
	s->sq[i[4]]->x = ft_atof_ptr(&tmp);
	s->sq[i[4]]->y = ft_atof_ptr(&tmp);
	s->sq[i[4]]->z = ft_atof_ptr(&tmp);
	tmp = line[2];
	s->sq[i[4]]->vec_x = ft_atof_ptr(&tmp);
	s->sq[i[4]]->vec_y = ft_atof_ptr(&tmp);
	s->sq[i[4]]->vec_z = ft_atof_ptr(&tmp);
	s->sq[i[4]]->side_size = ft_atof(line[3]);
	tmp = line[3];
	s->sq[i[4]]->r = ft_atof_ptr(&tmp);
	s->sq[i[4]]->r = (s->sq[i[3]]->r < 0) ? 0 : s->sq[i[4]]->r;
	s->sq[i[4]]->r = (s->sq[i[3]]->r > 255) ? 255 : s->sq[i[4]]->r;
	s->sq[i[4]]->g = ft_atof_ptr(&tmp);
	s->sq[i[4]]->g = (s->sq[i[3]]->g < 0) ? 0 : s->sq[i[4]]->g;
	s->sq[i[4]]->g = (s->sq[i[3]]->g > 255) ? 255 : s->sq[i[4]]->g;
	s->sq[i[4]]->b = ft_atof_ptr(&tmp);
	s->sq[i[4]]->b = (s->sq[i[3]]->b < 0) ? 0 : s->sq[i[4]]->b;
	s->sq[i[4]]->b = (s->sq[i[3]]->b > 255) ? 255 : s->sq[i[4]]->b;
	i[4] += 1;
	if (NULL != line[4])
		return (0);
	return (1);
}

int			parse_cylinder(char **line, t_rt *s, int *i)
{
	char	*tmp;

	tmp = line[1];
	s->cy[i[5]]->x = ft_atof_ptr(&tmp);
	s->cy[i[5]]->y = ft_atof_ptr(&tmp);
	s->cy[i[5]]->z = ft_atof_ptr(&tmp);
	tmp = line[2];
	s->cy[i[5]]->vec_x = ft_atof_ptr(&tmp);
	s->cy[i[5]]->vec_y = ft_atof_ptr(&tmp);
	s->cy[i[5]]->vec_z = ft_atof_ptr(&tmp);
	s->cy[i[5]]->diameter = ft_atof(line[3]);
	s->cy[i[5]]->height = ft_atof(line[4]);
	tmp = line[5];
	s->cy[i[5]]->r = ft_atof_ptr(&tmp);
	s->cy[i[5]]->r = (s->cy[i[5]]->r < 0) ? 0 : s->cy[i[5]]->r;
	s->cy[i[5]]->r = (s->cy[i[5]]->r > 255) ? 255 : s->cy[i[5]]->r;
	s->cy[i[5]]->g = ft_atof_ptr(&tmp);
	s->cy[i[5]]->g = (s->pl[i[3]]->g < 0) ? 0 : s->cy[i[5]]->g;
	s->cy[i[5]]->g = (s->pl[i[3]]->g > 255) ? 255 : s->cy[i[5]]->g;
	s->cy[i[5]]->b = ft_atof_ptr(&tmp);
	s->cy[i[5]]->b = (s->cy[i[5]]->b < 0) ? 0 : s->cy[i[5]]->b;
	s->cy[i[5]]->b = (s->cy[i[5]]->b > 255) ? 255 : s->cy[i[5]]->b;
	i[5] += 1;
	if (NULL != line[6])
		return (0);
	return (1);
}