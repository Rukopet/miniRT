/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:01:07 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 20:01:29 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			init_count_struct(t_count *counter)
{
	counter->resolution = 0;
	counter->a_light = 0;
	counter->cam = 0;
	counter->light = 0;
	counter->sp = 0;
	counter->pl = 0;
	counter->sq = 0;
	counter->cy = 0;
	counter->tr = 0;
	return (1);
}

void		init_scene_struct(t_rt **str)
{
	t_rt	*s;

	if (!(s = malloc(sizeof(t_rt))))
		errors_and_exit(-1, s);
	s->counter = NULL;
	s->d = NULL;
	s->resolution = NULL;
	s->a_light = NULL;
	s->cam = NULL;
	s->light = NULL;
	s->sp = NULL;
	s->pl = NULL;
	s->sq = NULL;
	s->cy = NULL;
	s->tr = NULL;
	s->save = 0;
	*str = s;
}
