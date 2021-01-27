#include <stdlib.h>
#include <unistd.h>
#include "minirt.h"

void		next_errors(int flag, t_rt *scene)
{
	if (flag == 8)
	{
		write(2, "Error\nFunction alloc_structs_res can't alloc memory\n", 53);
		free_scene(scene, 1);
		exit(flag);
	}
	if (flag == 9)
	{
		write(2, "Error\nCan't alloc memory for structs\n", 38);
		free_scene(scene, 1);
		exit(flag);
	}
		
}

void		erros_and_exit(int flag, t_rt *scene)
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
		write(2, "Error\nBad cam value\n", 21);
	else if (flag == -1)
		write(2, "Error\nAllocation error (malloc def)", 36);
	else
		next_errors(flag, scene);
	exit(flag);
}
