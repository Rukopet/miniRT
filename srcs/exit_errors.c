#include <stdlib.h>
#include <unistd.h>

void		erros_and_exit(int flag)
{
	if (flag == 1)
		write(2, "Error\nNot enough arguments, add file name-scene\n", 49);
	if (flag == 2)
		write(2, "Error\nToo much arguments\n", 26);
	if (flag == 3)
		write(2, "Error\nEmpty \"save\" argument, add file name-scene\n", 50);
	if (flag == 4)
		write(2, "Error\nBad arguments\n", 21);
	if (flag == -1)
		write(2, "Error\nAllocation error (malloc def)", 36);
	exit(flag);
}
