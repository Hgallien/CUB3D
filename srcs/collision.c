/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:39:27 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/23 10:24:10 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_point		coll_a_neg(t_point s, char **map)
{
	t_point p;

	p.y = ceil(s.y - 1) + 0.15;
	p.x = s.x;
	if (map[(int)floor(p.y)][(int)floor(p.x + 0.15)] != '0')
		p.x = ceil(p.x) - 0.15;
	if (map[(int)floor(p.y)][(int)floor(p.x - 0.15)] != '0')
		p.x = floor(p.x) + 0.15;
	return (p);
}

t_point		coll_a_pos(t_point s, char **map)
{
	t_point p;

	p.y = ceil(s.y) - 0.15;
	p.x = s.x;
	if (map[(int)floor(p.y)][(int)floor(p.x + 0.15)] != '0')
		p.x = ceil(p.x) - 0.15;
	if (map[(int)floor(p.y)][(int)floor(p.x - 0.15)] != '0')
		p.x = floor(p.x) + 0.15;
	return (p);
}

t_point		coll_b_pos(t_point s, char **map)
{
	t_point p;

	p.x = floor(s.x) + 0.15;
	p.y = s.y;
	if (map[(int)floor(p.y - 0.15)][(int)floor(p.x)] != '0')
		p.y = floor(p.y) + 0.15;
	if (map[(int)floor(p.y + 0.15)][(int)floor(p.x)] != '0')
		p.y = floor(p.y) - 0.15;
	return (p);
}

t_point		coll_b_neg(t_point s, char **map)
{
	t_point p;

	p.x = ceil(s.x) - 0.15;
	p.y = s.y;
	if (map[(int)floor(p.y - 0.15)][(int)floor(p.x)] != '0')
		p.y = floor(p.y) + 0.15;
	if (map[(int)floor(p.y + 0.15)][(int)floor(p.x)] != '0')
		p.y = floor(p.y) - 0.15;
	return (p);
}

t_point		collision(t_line l, t_point s, char **map)
{
	if (l.a <= 0)
	{
		if (map[(int)floor(s.y - 0.15)][(int)floor(s.x)] != '0')
			return (coll_a_neg(s, map));
	}
	if (l.a >= 0)
	{
		if (map[(int)floor(s.y + 0.15)][(int)floor(s.x)] != '0')
			return (coll_a_pos(s, map));
	}
	if (l.b >= 0)
	{
		if (map[(int)floor(s.y)][(int)floor(s.x - 0.15)] != '0')
			return (coll_b_pos(s, map));
	}
	if (l.b <= 0)
	{
		if (map[(int)floor(s.y)][(int)floor(s.x + 0.15)] != '0')
		{
			return (coll_b_neg(s, map));
		}
	}
	return (s);
}
