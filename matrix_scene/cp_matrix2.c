#include "minirt.h"


void 				alloc_square_fig(t_rt *scene, t_figures *fig)
{
	int				i;

	i = 0;
	if (fig->sq != NULL)
	{
		while (fig->sq[i] != NULL)
		{
			fig->sq[i]->x = scene->sq[i]->x;
			fig->sq[i]->y = scene->sq[i]->y;
			fig->sq[i]->z = scene->sq[i]->z;
			fig->sq[i]->r = scene->sq[i]->r;
			fig->sq[i]->g = scene->sq[i]->g;
			fig->sq[i]->b = scene->sq[i]->b;
			fig->sq[i]->g = scene->sq[i]->g;
			fig->sq[i]->vec_x = scene->sq[i]->vec_x;
			fig->sq[i]->vec_y = scene->sq[i]->vec_y;
			fig->sq[i]->vec_z = scene->sq[i]->vec_z;
			fig->sq[i]->side_size = scene->sq[i]->side_size;
			i++;
		}

	}
	alloc_cylinder_fig(scene, fig);
}

void 				alloc_plane_fig(t_rt *scene, t_figures *fig)
{
	int				i;

	i = 0;
	if (fig->pl != NULL)
	{
		while (fig->pl[i] != NULL)
		{
			fig->pl[i]->x = scene->pl[i]->x;
			fig->pl[i]->y = scene->pl[i]->y;
			fig->pl[i]->z = scene->pl[i]->z;
			fig->pl[i]->r = scene->pl[i]->r;
			fig->pl[i]->g = scene->pl[i]->g;
			fig->pl[i]->b = scene->pl[i]->b;
			fig->pl[i]->g = scene->pl[i]->g;
			fig->pl[i]->vec_x = scene->pl[i]->vec_x;
			fig->pl[i]->vec_y = scene->pl[i]->vec_y;
			fig->pl[i]->vec_z = scene->pl[i]->vec_z;
			i++;
		}

	}
	alloc_square_fig(scene, fig);
}

void 				alloc_sphere_fig(t_rt *scene, t_figures *fig)
{
	int				i;

	i = 0;
	if (fig->sp != NULL)
		while (fig->sp[i] != NULL)
		{
			fig->sp[i]->x = scene->sp[i]->x;
			fig->sp[i]->y = scene->sp[i]->y;
			fig->sp[i]->z = scene->sp[i]->z;
			fig->sp[i]->diameter = scene->sp[i]->diameter;
			fig->sp[i]->r = scene->sp[i]->r;
			fig->sp[i]->g = scene->sp[i]->g;
			fig->sp[i]->b = scene->sp[i]->b;
			i++;
		}
	alloc_plane_fig(scene, fig);
}

void 				alloc_light_fig(t_rt *scene, t_figures *fig)
{
	int 			i;

	i = 0;
	if (fig->light != NULL)
		while (fig->light[i] != NULL)
		{
			fig->light[i]->x = scene->light[i]->x;
			fig->light[i]->y = scene->light[i]->y;
			fig->light[i]->z = scene->light[i]->z;
			fig->light[i]->bright_rate = scene->light[i]->bright_rate;
			fig->light[i]->r = scene->light[i]->r;
			fig->light[i]->g = scene->light[i]->g;
			fig->light[i]->b = scene->light[i]->b;
			i++;
		}
	alloc_sphere_fig(scene, fig);
}

void 				alloc_figures(t_rt *scene, t_figures *fig)
{
	int 			i;

	i = 0;
	while (fig->cam[i] != NULL)
	{
		fig->cam[i]->vec_x = scene->cam[i]->vec_x;
		fig->cam[i]->vec_y = scene->cam[i]->vec_y;
		fig->cam[i]->vec_z = scene->cam[i]->vec_z;
		fig->cam[i]->x = scene->cam[i]->x;
		fig->cam[i]->y = scene->cam[i]->y;
		fig->cam[i]->z = scene->cam[i]->z;
		fig->cam[i]->fov = scene->cam[i]->fov;
		i++;
	}
	alloc_light_fig(scene, fig);
}