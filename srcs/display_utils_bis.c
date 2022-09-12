/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:26:01 by hgallien          #+#    #+#             */
/*   Updated: 2021/03/08 11:00:11 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_land(t_allp *all)
{
	int j;

	j = 0;
	free(all->tab.angles);
	free(all->s_wall);
	free(all->tab.touches);
	free(all->tab.rayons);
	while (j < all->resw)
	{
		free(all->tab.touches_obj[j]);
		j++;
	}
	free(all->tab.touches_obj);
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	malloc_land(t_all_tab *tab, int width, t_allp *all)
{
	int i;

	i = 0;
	if ((all->s_wall = malloc(sizeof(int) * width)) == NULL)
		exit(0);
	if ((tab->angles = malloc(sizeof(float) * width)) == NULL)
		free_after_angles(all->s_wall);
	if ((tab->touches_obj = malloc(sizeof(t_point*) * width)) == NULL)
		free_after_touches_obj(tab, all->s_wall);
	if ((tab->touches = malloc(sizeof(t_point) * width)) == NULL)
		free_after_touches(all->s_wall, tab);
	if ((tab->rayons = malloc(sizeof(t_line) * width)) == NULL)
		free_after_rayons(all->s_wall, tab);
}
