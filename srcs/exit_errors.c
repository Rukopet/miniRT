#include <stdlib.h>
#include <unistd.h>
#include "minirt.h"

static void	mlx_errors(int flag, t_rt *scene)
{
	if (flag == 20)
	{
		write(2, "Error\nIn begin init mlx function\n", 34);
		free_scene(scene, 1);
		exit(flag);
	}
}

void		next_errors(int flag, t_rt *scene)
{
	if (flag == 8)
	{
		write(2, "Error\nFunctionalloc_structs_res can't alloc memory\n", 53);
		free_scene(scene, 1);
		exit(flag);
	}
	else if (flag == 9)
	{
		write(2, "Error\nCan't alloc memory for structs\n", 38);
		free_scene(scene, 1);
		exit(flag);
	}
	else
		mlx_errors(flag, scene);
}

void		errors_and_exit(int flag, t_rt *scene)
{
	if (flag == 1)
		write(2, "Error\nNot enough arguments, add file name-scene\n", 49);
	else if (flag == 2)
		write(2, "Error\nToo much arguments\n", 26);
	else if (flag == 3)
		write(2, "Error\nEmpty \"save\" argument, add file name-scene\n", 50);
	else if (flag == 4)
		write(2, "Error\nBad arguments\n", 21);
	else if (flag == 5)
		write(2, "Error\nBad cam value\n", 21);
	else if (flag == 6)
		write(2, "Error\nIn begin\n", 16);
	else if (flag == 7)
		write(2, "Error\nFile must be with .rt extention\n", 39);
	else if (flag == -1)
		write(2, "Error\nAllocation error (malloc def)", 36);
	else
		next_errors(flag, scene);
	exit(flag);
}
