/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:13:20 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/16 12:11:27 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_after_angles(int *tab)
{
	free(tab);
	exit(0);
}

void	free_after_touches_obj(t_all_tab *tab, int *s_wall)
{
	free(s_wall);
	free(tab->angles);
	exit(0);
}

void	free_while(int i, t_all_tab *tab, int *s_wall)
{
	while (i > 0)
	{
		free(tab->touches_obj[i]);
		i--;
	}
	free(tab->touches_obj);
	free(s_wall);
	free(tab->angles);
	free(tab->touches);
	free(tab->rayons);
	exit(0);
}

void	free_after_touches(int *s_wall, t_all_tab *tab)
{
	free(s_wall);
	free(tab->angles);
	free(tab->touches_obj);
	exit(0);
}

void	free_after_rayons(int *s_wall, t_all_tab *tab)
{
	free(s_wall);
	free(tab->angles);
	free(tab->touches_obj);
	free(tab->touches);
	exit(0);
}
