/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:33:27 by hgallien          #+#    #+#             */
/*   Updated: 2021/03/08 09:48:18 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		starting_point(char c, int i, int j, t_allp *all)
{
	all->s.x = j + 0.5;
	all->s.y = i + 0.5;
	if (c == 'N')
	{
		all->v.x = 0;
		all->v.y = -1;
	}
	else if (c == 'S')
	{
		all->v.x = 0;
		all->v.y = 1;
	}
	else if (c == 'W')
	{
		all->v.x = -1;
		all->v.y = 0;
	}
	else if (c == 'E')
	{
		all->v.x = 1;
		all->v.y = 0;
	}
}

int			is_bad_char(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (0);
	if (c == '0' || c == '1' || c == '2' || c == 'v')
		return (0);
	if (c == 'P' || c == '6')
		return (0);
	return (1);
}

int			verif_door(int i, int j, t_allp *all, int p)
{
	all->map[i][j] = '1';
	all->door[p].x = j;
	all->door[p].y = i;
	all->door_state[p] = 1;
	return (p + 1);
}

int			test_close(int x, int y, t_var_verif var, char **map)
{
	if (var.i == 0 || var.i == y - 1 || var.j == 0 || var.j == x - 1)
		return (-1);
	if (map[var.i + 1][var.j] == 'v' || map[var.i - 1][var.j] == 'v')
		return (-1);
	if (map[var.i][var.j + 1] == 'v' || map[var.i][var.j - 1] == 'v')
		return (-1);
	return (1);
}

void		test_spawn(t_var_verif *var, char **map, t_allp *all)
{
	if (var->v == 1 || var->v == -3)
	{
		var->v = -3;
		return ;
	}
	var->v = 1;
	starting_point(map[var->i][var->j], var->i, var->j, all);
	map[var->i][var->j] = '0';
}
