/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_utils_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:01:51 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/19 12:07:39 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		condition_spawn(char **map, int i, int j)
{
	if (map[i][j] == 'N' || map[i][j] == 'E'
			|| map[i][j] == 'W' || map[i][j] == 'S')
		return (1);
	return (0);
}

int		in_conditions(t_allp *all, int x, int y, t_var_verif *var)
{
	if (test_close(x, y, *var, all->map) == -1)
		return (-1);
	test_spawn(var, all->map, all);
	return (1);
}
