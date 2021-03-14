/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:23:59 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 21:28:48 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				check_argc(int argc, char **argv, t_rt *scene)
{
	if (argc < 2)
		errors_and_exit(1, scene);
	if (argc > 3)
		errors_and_exit(2, scene);
	if (argc == 2 && (0 == (ft_strncmp(argv[1], "--save", 7))))
		errors_and_exit(3, scene);
	if (1 != (check_scene_arg(argv, scene, argc)))
		return (0);
	return (1);
}

int				branching(int argc, char **argv, t_rt *scene)
{
	if (!(check_argc(argc, argv, scene)))
		return (0);
	begin_mlx_work(scene);
	return (1);
}

int				main(int argc, char *argv[])
{
	t_rt		*scene;

	init_scene_struct(&scene);
	if (!(branching(argc, argv, scene)))
		return (-1);
	return (0);
}
