/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:32:36 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/16 14:56:15 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	hp_bar(t_allp *all, int hp)
{
	float x;
	float y;

	x = 100;
	y = 100;
	while (x < 500)
	{
		y = 100;
		while (y < 150)
		{
			if (x < 100 + 400 * ((float)hp / 100) && y > 100 && y < 149)
				my_mlx_pixel_put(&(all->img), (int)x, (int)y, 0x0000FF00);
			else
				my_mlx_pixel_put(&(all->img), (int)x, (int)y, 0x00FF0000);
			y++;
		}
		x++;
	}
}
