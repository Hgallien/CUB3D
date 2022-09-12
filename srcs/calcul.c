/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:13:47 by hgallien          #+#    #+#             */
/*   Updated: 2021/03/08 10:59:23 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_point			proj_equation(t_line player, t_line obj)
{
	t_point		res;
	float		nby;
	float		c;

	if (player.b <= 0.0001 && player.b >= -0.0001)
		return (zero_b(player, obj));
	if (player.a >= -0.0001 && player.a <= 0.0001)
		return (zero_a(player, obj));
	if (obj.a >= -0.0001 && obj.a <= 0.0001)
	{
		res.y = (-1 * obj.c) / obj.b;
		res.x = ((player.b * res.y * -1) + (player.c * -1)) / player.a;
		return (res);
	}
	if (obj.b >= -0.0001 && obj.b <= 0.0001)
	{
		res.x = (-1 * obj.c) / obj.a;
		res.y = ((player.a * res.x * -1) + (player.c * -1)) / player.b;
		return (res);
	}
	nby = (player.b * -1) / player.a;
	c = (player.c * -1) / player.a;
	res.y = (-1 * ((c * obj.a) + obj.c)) / ((nby * obj.a) + obj.b);
	res.x = ((obj.b * res.y * -1) + (obj.c * -1)) / obj.a;
	return (res);
}

t_point			find_next_round(t_line l, t_point p)
{
	t_point rx;
	t_point ry;

	rx = next_round_x(l, p);
	ry = next_round_y(l, p);
	if (distance(p, rx) > distance(p, ry))
		return (ry);
	else
		return (rx);
}

t_object		*find_obj(t_line l, t_point p, t_vecteur vision, t_allp *all)
{
	t_object	*res;
	t_fobj_var	var;

	var = set_fobj_var(l, vision, all);
	if ((res = malloc(sizeof(t_object) * max(all->ymap, all->xmap))) == NULL)
		exit_find_obj(all);
	while (1)
	{
		var.rx = next_round_x(l, p);
		var.ry = next_round_y(l, p);
		if (l.b == 0 || (l.a != 0 && distance(p, var.rx) > distance(p, var.ry)))
		{
			if (obj_roundy(res, &var, &p, all->map))
				return (res);
		}
		else
		{
			if (obj_roundx(res, &var, &p, all->map))
				return (res);
		}
	}
	return (res);
}

t_point			find_wall(t_line l, t_point p, char **map)
{
	int		v;
	t_point	rx;
	t_point	ry;

	v = 1;
	while (v)
	{
		rx = next_round_x(l, p);
		ry = next_round_y(l, p);
		if (l.b == 0 || (l.a != 0 && distance(p, rx) > distance(p, ry)))
		{
			p = ry;
			if ((map[(int)floor(p.y) - 1][(int)floor(p.x)] == '1') ||
					(map[(int)floor(p.y)][(int)floor(p.x)] == '1'))
				v = 0;
		}
		else
		{
			p = rx;
			if ((map[(int)floor(p.y)][(int)floor(p.x) - 1] == '1') ||
					(map[(int)floor(p.y)][(int)floor(p.x)] == '1'))
				v = 0;
		}
	}
	return (p);
}
