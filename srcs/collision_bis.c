/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:39:46 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/11 16:41:14 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	colli_x(t_point p, char **map)
{
	if (p.x - floor(p.x) < 0.3 &&
			map[(int)floor(p.y)][(int)floor(p.x - 0.3)] != '0')
		return (floor(p.x) + 0.3);
	if (p.x - floor(p.x) > 0.7 &&
			map[(int)floor(p.y)][(int)floor(p.x + 0.3)] != '0')
		return (floor(p.x + 0.3) - 0.3);
	return (p.x);
}

float	colli_y(t_point p, char **map)
{
	if (map[(int)floor(p.y - 0.3)][(int)floor(p.x)])
		return (floor(p.y) + 0.3);
	else if (map[(int)floor(p.y + 0.3)][(int)floor(p.x)])
		return (floor(p.y + 0.3) - 0.3);
	return (p.y);
}
