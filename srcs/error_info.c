/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:23:52 by hgallien          #+#    #+#             */
/*   Updated: 2021/03/08 11:28:58 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	res_check(t_allp *all)
{
	if (all->resw < 800)
		all->resw = 800;
	if (all->res < 800)
		all->res = 800;
	if (all->res % 2 == 1)
		all->res++;
	if (all->resw % 2 == 1)
		all->resw++;
	if (all->res > 1080)
		all->res = 1080;
	if (all->resw > 1920)
		all->resw = 1920;
}

int		check_info(t_allp *all)
{
	if (all->resw <= 0 || all->res <= 0)
		return (1);
	if (all->path.no == NULL || all->path.so == NULL || all->path.ea == NULL
			|| all->path.we == NULL || all->path.s == NULL)
		return (1);
	if (all->f.touchedr == 0 || all->f.touchedb == 0 || all->f.touchedg == 0)
		return (1);
	if (all->c.touchedr == 0 || all->c.touchedb == 0 || all->c.touchedg == 0)
		return (1);
	if (all->f.red < 0 || all->f.red > 255 || all->f.blue < 0 ||
			all->f.blue > 255 || all->f.green < 0 || all->f.green > 255)
		return (1);
	if (all->c.red < 0 || all->c.red > 255 || all->c.blue < 0 ||
			all->c.blue > 255 || all->c.green < 0 || all->c.green > 255)
		return (1);
	res_check(all);
	return (0);
}
