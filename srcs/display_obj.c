/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:09:08 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/23 10:26:50 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		close_obj_display(t_object obj, int col, float angle, t_allp *all)
{
	t_cold_var var;

	var.height = all->res / (distance(all->hugo->s, obj.p) * cos(angle));
	var.diff = (var.height - all->res) / 2;
	var.i = 0;
	while (var.i < all->res)
	{
		var.x = (float)(var.i + var.diff) / ((float)var.height
				/ all->obj[obj.ref - '0' - 2].h);
		if (fabs(all->hugo->v.x) >= fabs(all->hugo->v.y))
			my_mlx_pixel_put(&(all->img), col, var.i, my_mlx_pixel_get(
				&(all->obj[obj.ref - '0' - 2]), all->obj[obj.ref - '0' - 2].w *
						(obj.p.y - floor(obj.p.y)), var.x));
		else
			my_mlx_pixel_put(&(all->img), col, var.i, my_mlx_pixel_get(
				&(all->obj[obj.ref - '0' - 2]), all->obj[obj.ref - '0' - 2].w *
						(obj.p.x - floor(obj.p.x)), var.x));
		var.i++;
	}
}

void		setup_var(t_var_objd *var, t_allp *all, t_object obj)
{
	var->side = ((float)all->obj[obj.ref - '0' - 2].w / 2.0 * obj.d / 0.25);
	var->i = 0;
	var->height = all->res / (distance(all->hugo->s, obj.p));
	var->diff = (all->res - var->height) / 2;
}

void		obj_display(t_object obj, int col, t_allp *all)
{
	t_var_objd var;

	if (obj.p.x <= 0 || obj.p.y <= 0)
		return ;
	setup_var(&var, all, obj);
	while (var.i < all->res)
	{
		if (obj.p.x == 0 && obj.p.y == 0)
			break ;
		if (var.i >= var.diff && var.i <= all->res - var.diff)
		{
			var.x = floor(((float)var.i - (float)(var.diff)) /
			((float)var.height / ((float)all->obj[obj.ref - '0' - 2].h)));
			if (fabs(all->hugo->v.x) >= fabs(all->hugo->v.y))
				my_mlx_pixel_put(&(all->img), col, var.i, my_mlx_pixel_get(
&(all->obj[obj.ref - '0' - 2]), (all->obj[obj.ref - '0' - 2].w / 2) +
	var.side, var.x));
			else
				my_mlx_pixel_put(&(all->img), col, var.i, my_mlx_pixel_get(
	&(all->obj[obj.ref - '0' - 2]), (all->obj[obj.ref - '0' - 2].w / 2) +
	var.side, var.x));
		}
		var.i++;
	}
}
