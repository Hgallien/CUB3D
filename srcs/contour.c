/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contour.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:08:05 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/23 10:25:15 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	contour(char **map, int x, int y, t_allp *all)
{
	if (y < all->ymap - 1 && map[y + 1][x] == '2')
		map[y + 1][x] = '3';
	if (y > 0 && map[y - 1][x] == '2')
		map[y - 1][x] = '3';
	if (x < all->xmap - 1 && map[y][x + 1] == '2')
		map[y][x + 1] = '3';
	if (x > 0 && map[y][x - 1] == '2')
		map[y][x - 1] = '3';
	if (y < all->ymap - 1 && x < all->xmap - 1
		&& map[y + 1][x + 1] == '2')
		map[y + 1][x + 1] = '3';
	if (y > 0 && x > 0 && map[y - 1][x - 1] == '2')
		map[y - 1][x - 1] = '3';
	if (y > 0 && x < all->xmap - 1 && map[y - 1][x + 1] == '2')
		map[y - 1][x + 1] = '3';
	if (y < all->ymap - 1 && x > 0 && map[y + 1][x - 1] == '2')
		map[y + 1][x - 1] = '3';
}

void	contour_hp(int x, int y, t_allp *all)
{
	if (y < all->ymap - 1 && y + 1 == floor(all->hugo->s.y)
			&& x == floor(all->hugo->s.x))
		all->nb_hp = all->nb_hp - 25;
	if (y > 0 && y - 1 == floor(all->hugo->s.y)
			&& x == floor(all->hugo->s.x))
		all->nb_hp = all->nb_hp - 25;
	if (x < all->xmap - 1 && y == floor(all->hugo->s.y)
			&& x - 1 == floor(all->hugo->s.x))
		all->nb_hp = all->nb_hp - 25;
	if (x > 0 && y == floor(all->hugo->s.y) && x - 1 ==
			floor(all->hugo->s.x))
		all->nb_hp = all->nb_hp - 25;
	if (y < all->ymap - 1 && x < all->xmap - 1 && y + 1 ==
			floor(all->hugo->s.y) && x + 1 == floor(all->hugo->s.x))
		all->nb_hp = all->nb_hp - 25;
	if (y > 0 && x > 0 && y - 1 == floor(all->hugo->s.y) && x - 1 ==
			floor(all->hugo->s.x))
		all->nb_hp = all->nb_hp - 25;
	if (y > 0 && x < all->xmap - 1 && y - 1 == floor(all->hugo->s.y)
			&& x + 1 == floor(all->hugo->s.x))
		all->nb_hp = all->nb_hp - 25;
	if (y < all->ymap - 1 && x > 0 && y + 1 == floor(all->hugo->s.y)
			&& x - 1 == floor(all->hugo->s.x))
		all->nb_hp = all->nb_hp - 25;
}
