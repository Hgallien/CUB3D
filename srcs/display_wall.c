/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:12:13 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/22 11:06:02 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	close_display(t_point wall, int col, float angle, t_allp *all)
{
	t_cold_var var;

	var.height = all->res / (distance(all->hugo->s, wall) * cos(angle));
	var.diff = (var.height - all->res) / 2;
	var.i = 0;
	while (var.i < all->res)
	{
		var.x = (float)(var.i + var.diff) / ((float)var.height /
				all->wall[all->s_wall[all->col]].h);
		if (wall.x == floor(wall.x))
			my_mlx_pixel_put(&(all->img), col, var.i, my_mlx_pixel_get(
	&(all->wall[all->s_wall[all->col]]), all->wall[all->s_wall[all->col]].w
				* (wall.y - floor(wall.y)), var.x));
		else
			my_mlx_pixel_put(&(all->img), col, var.i, my_mlx_pixel_get(
	&(all->wall[all->s_wall[all->col]]), all->wall[all->s_wall[all->col]].w
				* (wall.x - floor(wall.x)), var.x));
		var.i++;
	}
}

void	setup_col_dis(t_point wall, t_allp *all, float angle, t_cold_var *var)
{
	var->i = 0;
	var->height = all->res / (distance(all->hugo->s, wall) * cos(angle));
	var->diff = (all->res - var->height) / 2;
}

void	col_cond(t_point wall, int col, t_cold_var *var, t_allp *all)
{
	var->x = floor(((float)var->i - (float)(var->diff))
	/ ((float)var->height / ((float)all->wall[all->s_wall[all->col]].h)));
	if (wall.x == floor(wall.x))
		my_mlx_pixel_put(&(all->img), col, var->i, my_mlx_pixel_get(
		&(all->wall[all->s_wall[all->col]]), all->wall[all->s_wall[all->col]].w
			* (wall.y - floor(wall.y)), var->x));
	else
		my_mlx_pixel_put(&(all->img), col, var->i,
	my_mlx_pixel_get(&(all->wall[all->s_wall[all->col]]),
	all->wall[all->s_wall[all->col]].w * (wall.x - floor(wall.x)), var->x));
}

void	col_display(t_point wall, int col, float angle, t_allp *all)
{
	t_cold_var var;

	setup_col_dis(wall, all, angle, &var);
	if (is_door(wall, all))
	{
		door_col_display(wall, col, angle, all);
		return ;
	}
	if (var.height > all->res)
	{
		close_display(wall, col, angle, all);
		return ;
	}
	while (var.i < all->res)
	{
		if (var.i < var.diff)
			my_mlx_pixel_put(&(all->img), col, var.i, all->c.t);
		else if (var.i > all->res - var.diff)
			my_mlx_pixel_put(&(all->img), col, var.i, all->f.t);
		else
			col_cond(wall, col, &var, all);
		var.i++;
	}
}

int		find_side(t_point p, t_line l)
{
	if (p.x == floor(p.x))
	{
		if (l.b > 0)
			return (1);
		else
			return (2);
	}
	else
	{
		if (l.a > 0)
			return (3);
		else
			return (0);
	}
	return (-1);
}
