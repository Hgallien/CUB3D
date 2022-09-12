/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   penismap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:43:55 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/26 10:15:40 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		write_number(int fd, int nb, int n_oct)
{
	char buff;

	while (--n_oct >= 0)
	{
		buff = nb & 0xff;
		nb = nb >> 8;
		write(fd, &buff, 1);
	}
}

void		bmp_header_file(int fd, t_allp *all)
{
	int		t;

	t = (all->res * all->resw * 3) + 40 + 14;
	write(fd, "BM", 2);
	write_number(fd, t, 4);
	write_number(fd, 0, 2);
	write_number(fd, 0, 2);
	write_number(fd, 54, 4);
}

void		bmp_header_img(int fd, t_allp *all)
{
	write_number(fd, 40, 4);
	write_number(fd, all->resw, 4);
	write_number(fd, all->res, 4);
	write_number(fd, 1, 2);
	write_number(fd, 24, 2);
	write_number(fd, 0, 4);
	write_number(fd, all->res * all->resw * 3, 4);
	write_number(fd, 0, 4);
	write_number(fd, 0, 4);
	write_number(fd, 0, 4);
	write_number(fd, 0, 4);
}

void		bmp_by_pixel(int fd, t_allp *all)
{
	int i;
	int j;

	j = all->res - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < all->resw)
		{
			write_number(fd, my_mlx_pixel_get(&all->img, i, j), 3);
			i++;
		}
		j--;
	}
}

void		bmp_setup(t_allp *all)
{
	int fd;

	fd = open("result.bmp", O_CREAT | O_RDWR, 0666);
	bmp_header_file(fd, all);
	bmp_header_img(fd, all);
	bmp_by_pixel(fd, all);
	close(fd);
}
