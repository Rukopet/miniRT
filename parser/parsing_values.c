#include "minirt.h"
#include "libft.h"

int			parse_resolution(char **line, t_rt *s)
{
	s->resolution->x = ft_atoi(line[1]);
	s->resolution->y = ft_atoi(line[2]);
	if (s->resolution->y <= 0 || s->resolution->x <= 0)
		return(write_error_withpars("Error\nBad resolution value\0"));
	if (NULL != line[3])
		return (0);
	return (1);
}

int			parse_alight(char **line, t_rt *s)
{
	s->a_light->bright_rate = ft_atof(line[1]);
	s->a_light->r = ft_atoi(line[2]);
	s->a_light->r = (s->a_light->r < 0) ? 0 : s->a_light->r;
	s->a_light->r = (s->a_light->r > 255) ? 255 : s->a_light->r;
	s->a_light->g = ft_atoi(line[3]);
	s->a_light->g = (s->a_light->g < 0) ? 0 : s->a_light->g;
	s->a_light->g = (s->a_light->g > 255) ? 255 : s->a_light->g;
	s->a_light->b = ft_atoi(line[4]);
	s->a_light->b = (s->a_light->b < 0) ? 0 : s->a_light->b;
	s->a_light->b = (s->a_light->b > 255) ? 255 : s->a_light->b;
	if (NULL != line[5])
		return (0);
	return (1);
}

int			parse_cam(char **line, t_rt *s, int *i)
{
	s->cam[i[0]]->x = ft_atof(line[1]);
	s->cam[i[0]]->y = ft_atof(line[2]);
	s->cam[i[0]]->z = ft_atof(line[3]);

	s->cam[i[0]]->vec_x = ft_atof(line[4]);
	s->cam[i[0]]->vec_y = ft_atof(line[5]);
	s->cam[i[0]]->vec_z = ft_atof(line[6]);

	s->cam[i[0]]->fov = ft_atof(line[7]);
	if (line[8] != NULL)
		return (0);
	i[0] += 1;
	return (1);
}

int			parse_light(char **line, t_rt *s, int *i)
{
	s->light[i[1]]->x = ft_atof(line[1]);
	s->light[i[1]]->y = ft_atof(line[2]);
	s->light[i[1]]->z = ft_atof(line[3]);

	s->light[i[1]]->bright_rate = ft_atof(line[4]);

	s->light[i[1]]->r = ft_atof(line[5]);
	s->light[i[1]]->g = ft_atof(line[6]);
	s->light[i[1]]->b = ft_atof(line[7]);
	if (NULL != line[8])
		return (0);
	i[1] += 1;
	return (1);
}

int			parse_sphere(char **line, t_rt *s, int *i)
{
	s->sp[i[2]]->x = ft_atof(line[1]);
	s->sp[i[2]]->y = ft_atof(line[2]);
	s->sp[i[2]]->z = ft_atof(line[3]);

	s->sp[i[2]]->diameter = ft_atof(line[4]);
	s->sp[i[2]]->r = ft_atoi(line[4]);
	s->sp[i[2]]->r = (s->sp[i[2]]->r < 0) ? 0 : s->sp[i[2]]->r;
	s->sp[i[2]]->r = (s->sp[i[2]]->r > 255) ? 255 : s->sp[i[2]]->r;

	s->sp[i[2]]->g = ft_atoi(line[5]);
	s->sp[i[2]]->g = (s->sp[i[2]]->g < 0) ? 0 : s->sp[i[2]]->g;
	s->sp[i[2]]->g = (s->sp[i[2]]->g > 255) ? 255 : s->sp[i[2]]->g;

	s->sp[i[2]]->b = ft_atoi(line[6]);
	s->sp[i[2]]->b = (s->sp[i[2]]->b < 0) ? 0 : s->sp[i[2]]->b;
	s->sp[i[2]]->b = (s->sp[i[2]]->b > 255) ? 255 : s->sp[i[2]]->b;
	i[2] += 1;
	if (NULL != line[7])
		return (0);
	return (1);
}
