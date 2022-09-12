/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:10:02 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/11 16:30:19 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_point		zero_b(t_line player, t_line obj)
{
	t_point res;

	res.x = (-1 * player.c) / player.a;
	res.y = ((obj.a * res.x * -1) + (obj.c * -1)) / obj.b;
	return (res);
}

t_point		zero_a(t_line player, t_line obj)
{
	t_point res;

	res.y = (-1 * player.c) / player.b;
	res.x = ((obj.b * res.y * -1) + (obj.c * -1)) / obj.a;
	return (res);
}
