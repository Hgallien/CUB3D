/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obj_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:25:39 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/23 10:29:48 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		oob(t_point *p, t_object *res, t_fobj_var var)
{
	if (p->x <= 1 || p->x >= var.all->xmap
		|| p->y <= 1 || p->y >= var.all->ymap)
	{
		p->x = -42;
		p->y = -42;
		res[var.nb_obj].p = *p;
		res[var.nb_obj].ref = -42;
		return (1);
	}
	return (0);
}

int		obj_roundy(t_object *res, t_fobj_var *var, t_point *p, char **map)
{
	*p = var->ry;
	if (oob(p, res, *var))
		return (1);
	if (var->l.a >= 0 && (map[(int)floor(p->y)][(int)floor(p->x)] >= '2'
		&& map[(int)floor(p->y)][(int)floor(p->x)] <= '6'))
		ry_bottom(p, var, &(res[var->nb_obj]), map);
	else if (var->l.a <= 0 && (map[(int)floor(p->y) - 1][(int)floor(p->x)]
		>= '2' && map[(int)floor(p->y) - 1][(int)floor(p->x)] <= '6'))
		ry_top(p, var, &(res[var->nb_obj]), map);
	return (0);
}

int		obj_roundx(t_object *res, t_fobj_var *var, t_point *p, char **map)
{
	*p = var->rx;
	if (oob(p, res, *var))
		return (1);
	if (var->l.b <= 0 && (map[(int)floor(p->y)][(int)floor(p->x)]
	>= '2' && map[(int)floor(p->y)][(int)floor(p->x)] <= '6'))
		rx_right(p, var, &(res[var->nb_obj]), map);
	else if (var->l.b >= 0 && (map[(int)floor(p->y)][(int)floor(p->x) - 1]
	>= '2' && map[(int)floor(p->y)][(int)floor(p->x) - 1] <= '6'))
		rx_left(p, var, &(res[var->nb_obj]), map);
	return (0);
}
