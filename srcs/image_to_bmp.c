/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_bmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:19:58 by egums             #+#    #+#             */
/*   Updated: 2021/03/14 21:20:32 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			info_header(t_rt *sc, int fd)
{
	unsigned char	*h;
	int				i[2];

	h = ft_calloc(BMP_INFO, 8);
	i[0] = sc->resolution->x;
	i[1] = sc->resolution->y;
	h[0] = (unsigned char)(BMP_INFO);
	h[4] = (unsigned char)(i[0]);
	h[5] = (unsigned char)(i[0] >> 8);
	h[6] = (unsigned char)(i[0] >> 16);
	h[7] = (unsigned char)(i[0] >> 24);
	h[8] = (unsigned char)(i[1]);
	h[9] = (unsigned char)(i[1] >> 8);
	h[10] = (unsigned char)(i[1] >> 16);
	h[11] = (unsigned char)(i[1] >> 24);
	h[12] = (unsigned char)(1);
	h[14] = (unsigned char)(sc->img->bits_per_pixel);
	write(fd, h, BMP_INFO);
	free(h);
}

static void			header(t_rt *sc, int fd)
{
	unsigned char	*h;
	int				s;

	h = ft_calloc(BMP_HEADER_S, 8);
	s = BMP_HEADER_S + BMP_INFO + (sc->img->bits_per_pixel / 8 *
			sc->resolution->x) * sc->resolution->y;
	*(h) = (unsigned char)'B';
	*(h + 1) = (unsigned char)'M';
	*(h + 2) = (unsigned char)s;
	*(h + 3) = (unsigned char)s >> 8;
	*(h + 4) = (unsigned char)s >> 16;
	*(h + 5) = (unsigned char)s >> 24;
	*(h + 10) = (unsigned char)(BMP_HEADER_S + BMP_INFO);
	write(fd, h, BMP_HEADER_S);
	free(h);
	info_header(sc, fd);
}

void				image_to_bmp(t_rt *sc)
{
	int				fd;
	int				i[2];
	unsigned int	*d;

	if (!(fd = open("image.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644)))
		errors_and_exit(-1, sc);
	header(sc, fd);
	i[0] = sc->resolution->y - 1;
	while (i[0] >= 0)
	{
		i[1] = -1;
		while (++i[1] < sc->resolution->x)
		{
			d = (unsigned int*)(sc->img->adr + sc->img->line_len * i[0] +
			(sc->img->bits_per_pixel / 8) * i[1]);
			write(fd, d, 4);
		}
		i[0]--;
	}
	close(fd);
}
