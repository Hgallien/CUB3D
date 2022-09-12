/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obj_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:01:44 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/12 11:43:54 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define X 0.25

int			ry_top(t_point *p, t_fobj_var *var, t_object *res, char **map)
{
	t_line		equa_para;
	t_point		centre;

	centre.x = floor(p->x) + 0.5;
	centre.y = floor(p->y) - 0.5;
	equation(centre, var->vision, &equa_para);
	res->p = proj_equation(equa_para, var->l);
	if (res->p.x >= floor(p->x) && res->p.x <= floor(p->x) + 1 && res->p.y >=
	floor(p->y) - 1 && res->p.y <= floor(p->y) && distance(res->p, centre) <= X)
	{
		*p = res->p;
		res->d = distance(res->p, centre);
		var->nb_obj = var->nb_obj + 1;
		res->ref = map[(int)floor(res->p.y)][(int)floor(res->p.x)];
		return (1);
	}
	return (0);
}

int			ry_bottom(t_point *p, t_fobj_var *var, t_object *res, char **map)
{
	t_line		equa_para;
	t_point		centre;

	centre.x = floor(p->x) + 0.5;
	centre.y = floor(p->y) + 0.5;
	equation(centre, var->vision, &equa_para);
	res->p = proj_equation(equa_para, var->l);
	if (res->p.x >= floor(p->x) && res->p.x <= floor(p->x) + 1 && res->p.y >=
	floor(p->y) && res->p.y <= floor(p->y) + 1 && distance(res->p, centre) <= X)
	{
		*p = res->p;
		res->d = distance(res->p, centre);
		res->ref = map[(int)floor(res->p.y)][(int)floor(res->p.x)];
		var->nb_obj = var->nb_obj + 1;
		return (1);
	}
	return (0);
}

int			rx_left(t_point *p, t_fobj_var *var, t_object *res, char **map)
{
	t_line		equa_para;
	t_point		centre;

	centre.x = floor(p->x) - 0.5;
	centre.y = floor(p->y) + 0.5;
	equation(centre, var->vision, &equa_para);
	res->p = proj_equation(equa_para, var->l);
	if (res->p.x >= floor(p->x) - 1 && res->p.x <= floor(p->x) && res->p.y >=
	floor(p->y) && res->p.y <= floor(p->y) + 1 && distance(res->p, centre) <= X)
	{
		res->d = distance(res->p, centre);
		*p = res->p;
		res->ref = map[(int)floor(res->p.y)][(int)floor(res->p.x)];
		var->nb_obj = var->nb_obj + 1;
		return (1);
	}
	return (0);
}

int			rx_right(t_point *p, t_fobj_var *var, t_object *res, char **map)
{
	t_line		equa_para;
	t_point		centre;

	centre.x = floor(p->x) + 0.5;
	centre.y = floor(p->y) + 0.5;
	equation(centre, var->vision, &equa_para);
	res->p = proj_equation(equa_para, var->l);
	if (res->p.x >= floor(p->x) && res->p.x <= floor(p->x) + 1 && res->p.y >=
	floor(p->y) && res->p.y <= floor(p->y) + 1 && distance(res->p, centre) <= X)
	{
		res->d = distance(res->p, centre);
		res->ref = map[(int)floor(res->p.y)][(int)floor(res->p.x)];
		*p = res->p;
		var->nb_obj = var->nb_obj + 1;
		return (1);
	}
	return (0);
}

t_fobj_var	set_fobj_var(t_line l, t_vecteur v, t_allp *all)
{
	t_fobj_var var;

	var.all = all;
	var.l = l;
	var.vision.x = v.y * -1;
	var.vision.y = v.x;
	var.nb_obj = 0;
	return (var);
}
