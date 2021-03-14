#include "minirt.h"

static void 		header(t_rt *sc)
{

}

void				image_to_bmp(t_rt *sc)
{
	int				fd;
	int				i[2];
	unsigned int	*d;

	if ((fd = open(sc->fn, O_CREAT | O_WRONLY | O_TRUNC, 0644)))
		errors_and_exit(-1, sc);
//	*i = sc->
//	header(sc);

//	close(fd);
}