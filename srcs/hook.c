/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:37:57 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/19 11:50:31 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		k_press(int keycode, t_allp *param)
{
	if (keycode == 14)
		open_door(param);
	if (keycode == 49)
		shoot(param);
	else if (keycode == 13)
		param->hugo->s = w_key(*(param->hugo), param->map, param);
	else if (keycode == 124)
		param->hugo->v = la_key(*(param->hugo));
	else if (keycode == 1)
		param->hugo->s = s_key(*(param->hugo), param->map, param);
	else if (keycode == 123)
		param->hugo->v = ra_key(*(param->hugo));
	else if (keycode == 0)
		param->hugo->s = a_key(*(param->hugo), param->map, param);
	else if (keycode == 2)
		param->hugo->s = d_key(*(param->hugo), param->map, param);
	else if (keycode == 53)
	{
		end(param);
	}
	return (0);
}

int		lunch_display(t_allp *all)
{
	final_display(all);
	return (0);
}
