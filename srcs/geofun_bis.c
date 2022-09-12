/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geofun_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:14:27 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/15 15:15:08 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float		distance(t_point a, t_point b)
{
	if (a.x == b.x)
	{
		return (sqrt(pow(a.y - b.y, 2)));
	}
	else if (a.y == b.y)
	{
		return (sqrt(pow(a.x - b.x, 2)));
	}
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}
