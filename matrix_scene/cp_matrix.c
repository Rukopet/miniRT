#include "minirt.h"

void 				alloc_triangle_fig(t_rt *scene, t_figures *fig)
{
	int				i;

	i = 0;
	if (fig->tr != NULL)
	{
		while (fig->tr[i] != NULL)
		{
			fig->tr[i]->first_x = scene->tr[i]->first_x;
			fig->tr[i]->first_y = scene->tr[i]->first_y;
			fig->tr[i]->first_z = scene->tr[i]->first_z;
			fig->tr[i]->r = scene->tr[i]->r;
			fig->tr[i]->g = scene->tr[i]->g;
			fig->tr[i]->b = scene->tr[i]->b;
			fig->tr[i]->second_x = scene->tr[i]->second_x;
			fig->tr[i]->second_y = scene->tr[i]->second_y;
			fig->tr[i]->second_z = scene->tr[i]->second_z;
			fig->tr[i]->third_x = scene->tr[i]->third_x;
			fig->tr[i]->third_y = scene->tr[i]->third_y;
			fig->tr[i]->third_z = scene->tr[i]->third_z;
			i++;
		}
	}
}

void 				alloc_cylinder_fig(t_rt *scene, t_figures *fig)
{
	int				i;

	i = 0;
	if (fig->cy != NULL)
	{
		while (fig->cy[i] != NULL)
		{
			fig->cy[i]->x = scene->cy[i]->x;
			fig->cy[i]->y = scene->cy[i]->y;
			fig->cy[i]->z = scene->cy[i]->z;
			fig->cy[i]->r = scene->cy[i]->r;
			fig->cy[i]->g = scene->cy[i]->g;
			fig->cy[i]->b = scene->cy[i]->b;
			fig->cy[i]->g = scene->cy[i]->g;
			fig->cy[i]->vec_x = scene->cy[i]->vec_x;
			fig->cy[i]->vec_y = scene->cy[i]->vec_y;
			fig->cy[i]->vec_z = scene->cy[i]->vec_z;
			fig->cy[i]->diameter = scene->cy[i]->diameter;
			fig->cy[i]->height = scene->cy[i]->height;
			i++;
		}
	}
	alloc_triangle_fig(scene, fig);
}