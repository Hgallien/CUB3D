/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:32:33 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/15 14:43:35 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	handle_gun(t_allp *all)
{
	if (all->gun_state > 4)
		mlx_put_image_to_window(all->mini, all->minik, all->gun[0].img,
				all->resw / 2 - all->gun[0].w / 3, all->res - all->gun[0].h);
	else
		mlx_put_image_to_window(all->mini, all->minik,
				all->gun[all->gun_state].img, all->resw / 2 - all->gun[0].w / 3,
				all->res - all->gun[0].h);
	if (all->gun_state > 0)
	{
		if (all->gun_state == 15)
			all->gun_state = 0;
		else
			all->gun_state++;
	}
}
