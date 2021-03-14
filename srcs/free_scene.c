/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:23:24 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 21:28:07 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		free_struct(void **s)
{
	while (s != NULL)
	{
		free(*s);
		*s = NULL;
		s++;
	}
	free(s);
	s = NULL;
}

void		free_res_al(void *s)
{
	free(s);
	s = NULL;
}

int			free_scene(t_rt *s, int flag)
{
	if (NULL != s->resolution)
		free_res_al((void*)s->resolution);
	if (NULL != s->a_light)
		free_res_al((void*)s->a_light);
	if (NULL != s->cam)
		free_struct((void**)s->cam);
	if (NULL != s->light)
		free_struct((void**)s->light);
	if (NULL != s->sp)
		free_struct((void**)s->sp);
	if (NULL != s->pl)
		free_struct((void**)s->pl);
	if (NULL != s->sq)
		free_struct((void**)s->sq);
	if (NULL != s->cy)
		free_struct((void**)s->cy);
	if (NULL != s->tr)
		free_struct((void**)s->tr);
	if (flag == 0)
		return (0);
	return (1);
}

void		check_resolution(t_rt *sc, void *mlx)
{
	int		x;
	int		y;

	mlx_get_screen_size(mlx, &x, &y);
	sc->resolution->x = (x < sc->resolution->x) ? x : sc->resolution->x;
	sc->resolution->y = (y < sc->resolution->y) ? y : sc->resolution->y;
}
