/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:03:50 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/12 11:22:19 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		is_door(t_point wall, t_allp *all)
{
	int i;

	i = 0;
	while (i < all->nb_door)
	{
		if (floor(wall.x) == all->door[i].x && floor(wall.y) ==
				all->door[i].y && all->door_state[i] == 1)
			return (1);
		if (floor(wall.x) - 1 == floor(all->door[i].x) && floor(wall.y) ==
				floor(all->door[i].y) && all->door_state[i] == 1)
			return (1);
		if (floor(wall.x) == all->door[i].x && floor(wall.y) - 1 ==
				all->door[i].y && all->door_state[i] == 1)
			return (1);
		i++;
	}
	return (0);
}

void	close_door_display(t_point wall, int col, float angle, t_allp *all)
{
	t_cold_var var;

	var.height = all->res / (distance(all->hugo->s, wall) * cos(angle));
	var.diff = (var.height - all->res) / 2;
	var.i = 0;
	while (var.i < all->res)
	{
		var.x = (float)(var.i + var.diff) / ((float)var.height / all->s_door.h);
		if (wall.x == floor(wall.x))
			my_mlx_pixel_put(&(all->img), col, var.i, my_mlx_pixel_get(
			&(all->s_door), all->s_door.w * (wall.y - floor(wall.y)), var.x));
		else
			my_mlx_pixel_put(&(all->img), col, var.i, my_mlx_pixel_get(
			&(all->s_door), all->s_door.w * (wall.x - floor(wall.x)), var.x));
		var.i++;
	}
}

void	cond_doord(t_point wall, int col, t_cold_var *var, t_allp *all)
{
	var->x = floor(((float)var->i - (float)(var->diff))
			/ ((float)var->height / ((float)all->s_door.h)));
	if (wall.x == floor(wall.x))
		my_mlx_pixel_put(&(all->img), col, var->i, my_mlx_pixel_get(
			&(all->s_door), all->s_door.w * (wall.y - floor(wall.y)), var->x));
	else
		my_mlx_pixel_put(&(all->img), col, var->i, my_mlx_pixel_get(
			&(all->s_door), all->s_door.w * (wall.x - floor(wall.x)), var->x));
}

void	door_col_display(t_point wall, int col, float angle, t_allp *all)
{
	t_cold_var var;

	var.height = all->res / (distance(all->hugo->s, wall) * cos(angle));
	if (var.height > all->res)
	{
		close_door_display(wall, col, angle, all);
		return ;
	}
	var.diff = (all->res - var.height) / 2;
	var.i = 0;
	while (var.i < all->res)
	{
		if (var.i < var.diff)
			my_mlx_pixel_put(&(all->img), col, var.i, all->c.t);
		else if (var.i > all->res - var.diff)
			my_mlx_pixel_put(&(all->img), col, var.i, all->f.t);
		else
			cond_doord(wall, col, &var, all);
		var.i++;
	}
}
