/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:05:53 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/23 10:27:18 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wall_display(t_all_tab tab, t_allp *all, int width)
{
	int i;

	i = 0;
	while (i < width / 2)
	{
		all->col = i;
		col_display(tab.touches[i], all->resw / 2 - i, tab.angles[i], all);
		i++;
	}
	i = width / 2;
	while (i < width)
	{
		all->col = i;
		col_display(tab.touches[i], i, tab.angles[i], all);
		i++;
	}
}

int		nb_obj_count(int i, t_all_tab tab)
{
	int count;

	count = 0;
	while (tab.touches_obj[i][count].p.x >= 0 &&
			tab.touches_obj[i][count].p.x >= 0)
		count++;
	count--;
	return (count);
}

void	condition(t_all_tab tab, t_allp *all, int i, int count)
{
	if (tab.touches_obj[i][count].p.x != 42 && distance(all->hugo->s,
				tab.touches_obj[i][count].p) <
			distance(all->hugo->s, tab.touches[i]))
		obj_display(tab.touches_obj[i][count],
				all->resw / 2 - i, all);
}

void	condition_b(t_all_tab tab, t_allp *all, int i, int count)
{
	if (tab.touches_obj[i][count].p.x != 42 && distance(all->hugo->s,
	tab.touches_obj[i][count].p) < distance(all->hugo->s, tab.touches[i]))
		obj_display(tab.touches_obj[i][count], i, all);
}

void	obj_display_upper(t_all_tab tab, t_allp *all, int width)
{
	int i;
	int count;

	i = 0;
	while (i < width / 2)
	{
		count = nb_obj_count(i, tab);
		while (count >= 0)
		{
			condition(tab, all, i, count);
			count--;
		}
		i++;
	}
	i = width / 2;
	while (i < all->resw)
	{
		count = nb_obj_count(i, tab);
		while (count >= 0)
		{
			condition_b(tab, all, i, count);
			count--;
		}
		i++;
	}
}
