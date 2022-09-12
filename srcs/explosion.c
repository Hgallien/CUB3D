/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explosion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:34:19 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/23 10:28:49 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	state_one(t_allp *all, int timer, t_var_ex *var)
{
	if (timer % 5 == 0 && timer == 0)
		contour_hp(var->uj, var->ui, all);
	if (timer % 5 == 0 && timer != 0)
		all->map[var->ui][var->uj] = '4';
	var->verif = 1;
}

void	state_two(t_allp *all, int timer, t_var_ex *var)
{
	if (timer % 10 == 0 && timer != 0)
		all->map[var->ui][var->uj] = '5';
	var->verif = 1;
}

void	state_three(t_allp *all, int timer, t_var_ex *var)
{
	contour(all->map, var->uj, var->ui, all);
	if (timer % 15 == 0 && timer != 0)
		all->map[var->ui][var->uj] = '0';
	var->verif = 1;
}

int		explosion(t_allp *all, int timer)
{
	t_var_ex var;

	var.ui = 0;
	var.verif = 0;
	while (var.ui < all->ymap)
	{
		var.uj = 0;
		while (var.uj < all->xmap)
		{
			if (all->map[var.ui][var.uj] == '3')
				state_one(all, timer, &var);
			if (all->map[var.ui][var.uj] == '4')
				state_two(all, timer, &var);
			else if (all->map[var.ui][var.uj] == '5')
				state_three(all, timer, &var);
			var.uj++;
		}
		var.ui++;
	}
	if (var.verif == 1)
		timer++;
	if (var.verif == 0)
		timer = 0;
	return (timer);
}
