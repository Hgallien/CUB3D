/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:41:21 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/23 10:30:44 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		is_door_bis(t_point wall, t_allp *all)
{
	int i;

	i = 0;
	while (i < all->nb_door)
	{
		if (floor(wall.x) == all->door[i].x && floor(wall.y) == all->door[i].y)
			return (i);
		if (floor(wall.x) - 1 == floor(all->door[i].x)
			&& floor(wall.y) == floor(all->door[i].y))
			return (i);
		if (floor(wall.x) == all->door[i].x &&
				floor(wall.y) - 1 == all->door[i].y)
			return (i);
		i++;
	}
	return (-1);
}

int		proc_mine(t_point new, char **map)
{
	int v;

	v = 0;
	if (map[(int)floor(new.y - 0.16)][(int)floor(new.x)] == '6')
	{
		map[(int)floor(new.y - 0.16)][(int)floor(new.x)] = '3';
		return (25);
	}
	if (map[(int)floor(new.y)][(int)floor(new.x - 0.16)] == '6')
	{
		map[(int)floor(new.y)][(int)floor(new.x - 0.16)] = '3';
		return (25);
	}
	if (map[(int)floor(new.y + 0.16)][(int)floor(new.x)] == '6')
	{
		map[(int)floor(new.y + 0.16)][(int)floor(new.x)] = '3';
		return (25);
	}
	if (map[(int)floor(new.y)][(int)floor(new.x + 0.16)] == '6')
	{
		map[(int)floor(new.y)][(int)floor(new.x + 0.16)] = '3';
		return (25);
	}
	return (0);
}

void	fix(t_point *new)
{
	if (fabs(new->x - floor(new->x)) < 0.0001)
		new->x = floor(new->x) + 0.0001;
	if (fabs(new->y - floor(new->y)) < 0.0001)
		new->y = floor(new->y) + 0.0001;
	if (fabs(new->x - floor(new->x)) > 0.999)
		new->x = floor(new->x) + 0.99;
	if (fabs(new->y - floor(new->y)) > 0.999)
		new->y = floor(new->y) + 0.99;
}
