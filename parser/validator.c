/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:57:20 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 19:57:22 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		val_cy(t_rt *sc, int i)
{
	if (sc->cy)
	{
		while (sc->cy[++i] != NULL)
		{
			if (!(sc->cy[i]->r >= 0 && sc->cy[i]->r <= 255) || \
			!(sc->cy[i]->g >= 0 && sc->cy[i]->g <= 255) || \
			!(sc->cy[i]->b >= 0 && sc->cy[i]->b <= 255))
				errors_and_exit(11, sc);
			if (!(sc->cy[i]->vec_x >= -1.0 && sc->cy[i]->vec_x <= 1.0) || \
			!(sc->cy[i]->vec_y >= -1.0 && sc->cy[i]->vec_y <= 1.0) || \
			!(sc->cy[i]->vec_z >= -1.0 && sc->cy[i]->vec_z <= 1.0))
				errors_and_exit(12, sc);
		}
	}
}

static void		val_sq_tr(t_rt *sc, int i)
{
	if (sc->sq)
		while (sc->sq[++i] != NULL)
		{
			if (!(sc->sq[i]->r >= 0 && sc->sq[i]->r <= 255) || \
			!(sc->sq[i]->g >= 0 && sc->sq[i]->g <= 255) || \
			!(sc->sq[i]->b >= 0 && sc->sq[i]->b <= 255))
				errors_and_exit(11, sc);
			if (!(sc->sq[i]->vec_x >= -1.0 && sc->sq[i]->vec_x <= 1.0) || \
			!(sc->sq[i]->vec_y >= -1.0 && sc->sq[i]->vec_y <= 1.0) || \
			!(sc->sq[i]->vec_z >= -1.0 && sc->sq[i]->vec_z <= 1.0))
				errors_and_exit(12, sc);
		}
	i = -1;
	if (sc->tr)
	{
		while (sc->tr[++i] != NULL)
		{
			if (!(sc->tr[i]->r >= 0 && sc->tr[i]->r <= 255) || \
			!(sc->tr[i]->g >= 0 && sc->tr[i]->g <= 255) || \
			!(sc->tr[i]->b >= 0 && sc->tr[i]->b <= 255))
				errors_and_exit(11, sc);
		}
	}
	val_cy(sc, -1);
}

static void		val_sp_pl(t_rt *sc, int i)
{
	if (sc->sp)
		while (sc->sp[++i])
		{
			if (!(sc->sp[i]->r >= 0 && sc->sp[i]->r <= 255) || \
			!(sc->sp[i]->g >= 0 && sc->sp[i]->g <= 255) || \
			!(sc->sp[i]->b >= 0 && sc->sp[i]->b <= 255))
				errors_and_exit(11, sc);
		}
	i = -1;
	if (sc->pl)
		while (sc->pl[++i] != NULL)
		{
			if (!(sc->pl[i]->r >= 0 && sc->pl[i]->r <= 255) || \
			!(sc->pl[i]->g >= 0 && sc->pl[i]->g <= 255) || \
			!(sc->pl[i]->b >= 0 && sc->pl[i]->b <= 255))
				errors_and_exit(11, sc);
			if (!(sc->pl[i]->vec_x >= -1.0 && sc->pl[i]->vec_x <= 1.0) || \
			!(sc->pl[i]->vec_y >= -1.0 && sc->pl[i]->vec_y <= 1.0) || \
			!(sc->pl[i]->vec_z >= -1.0 && sc->pl[i]->vec_z <= 1.0))
				errors_and_exit(12, sc);
		}
	val_sq_tr(sc, -1);
}

static void		check_cam_light(t_rt *sc, int i)
{
	if (sc->cam)
		while (sc->cam[++i] != NULL)
		{
			if (!(sc->cam[i]->vec_x >= -1.0 && sc->cam[i]->vec_x <= 1.0) || \
			!(sc->cam[i]->vec_y >= -1.0 && sc->cam[i]->vec_y <= 1.0) || \
			!(sc->cam[i]->vec_z >= -1.0 && sc->cam[i]->vec_z <= 1.0))
				errors_and_exit(12, sc);
			if (sc->cam[i]->fov > 180)
				errors_and_exit(5, sc);
		}
	i = -1;
	if (sc->light)
	{
		while (sc->light[++i] != NULL)
		{
			if (!(sc->light[i]->b_rate >= 0.0 && sc->light[i]->b_rate <= 1.0))
				errors_and_exit(13, sc);
			if (!(sc->light[i]->r >= 0 && sc->light[i]->r <= 255) || \
			!(sc->light[i]->g >= 0 && sc->light[i]->g <= 255) || \
			!(sc->light[i]->b >= 0 && sc->light[i]->b <= 255))
				errors_and_exit(11, sc);
		}
	}
	val_sp_pl(sc, -1);
}

void			validator(t_rt *sc)
{
	if (sc->a_light)
	{
		if (!(sc->a_light->r >= 0 && sc->a_light->r <= 255) || \
		!(sc->a_light->g >= 0 && sc->a_light->g <= 255) || \
		!(sc->a_light->b >= 0 && sc->a_light->b <= 255))
			errors_and_exit(11, sc);
		if (!(sc->a_light->b_rate >= 0.0 && sc->a_light->b_rate <= 1.0))
			errors_and_exit(13, sc);
	}
	if (sc->resolution->x <= 0 || sc->resolution->y <= 0)
		errors_and_exit(4, sc);
	check_cam_light(sc, -1);
}
