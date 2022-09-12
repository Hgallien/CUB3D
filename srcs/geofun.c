/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geofun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:58:26 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/15 15:15:05 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_vecteur	vec_f_angle(t_vecteur oldv, float angle)
{
	t_vecteur newv;

	newv.x = (cos(angle) * oldv.x + (sin(angle) * -1) * oldv.y);
	newv.y = (sin(angle) * oldv.x + cos(angle) * oldv.y);
	return (newv);
}

void		equation(t_point p, t_vecteur v, t_line *l)
{
	l->a = v.y;
	l->b = -v.x;
	l->c = (l->a * p.x + (l->b * p.y)) * -1;
}

t_point		next_round_x(t_line l, t_point p)
{
	t_point res;

	if (l.b > 0)
	{
		if (p.x == floor(p.x))
			res.x = floor(p.x) - 1;
		else
			res.x = floor(p.x);
	}
	else
	{
		if (p.x == ceil(p.x))
			res.x = ceil(p.x) + 1;
		else
			res.x = ceil(p.x);
	}
	if (l.b == 0)
		res.y = p.y;
	else
		res.y = (l.a * res.x + l.c) / (-1 * l.b);
	if (l.a < 0 && res.y > p.y)
		res.y = floor(res.y);
	if (l.a > 0 && res.y < p.y)
		res.y = ceil(res.y);
	return (res);
}

t_point		next_round_y(t_line l, t_point p)
{
	t_point res;

	if (l.a < 0)
	{
		if (p.y == ceil(p.y))
			res.y = ceil(p.y) - 1;
		else
			res.y = floor(p.y);
	}
	else
	{
		if (p.y == floor(p.y))
			res.y = floor(p.y) + 1;
		else
			res.y = ceil(p.y);
	}
	if (l.a == 0)
		res.x = p.x;
	else
		res.x = (l.b * res.y + l.c) / (-1 * l.a);
	if (l.b < 0 && res.x < p.x)
		res.x = ceil(res.x);
	if (l.b > 0 && res.x > p.x)
		res.x = floor(res.x);
	return (res);
}

t_point		x_or_y(t_point o, t_point rx, t_point ry)
{
	if (distance(o, rx) > distance(o, ry))
		return (ry);
	else
		return (rx);
}
