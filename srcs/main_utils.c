/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:43:32 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/23 16:40:14 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	setup_img(t_allp *all)
{
	int i;

	i = -1;
	all->s_door.img = NULL;
	while (++i < 5)
		all->gun[i].img = NULL;
	i = -1;
	while (++i < 4)
		all->wall[i].img = NULL;
	i = -1;
	while (++i < 5)
		all->obj[i].img = NULL;
	all->hp.img = NULL;
}

void	test_dot(char *s, int i)
{
	if (i < 4)
	{
		printf("Error\nBad map extension\n");
		exit(0);
	}
	if (s[i - 1] != 'b')
	{
		printf("Error\nBad map extension\n");
		exit(0);
	}
	if (s[i - 2] != 'u')
	{
		printf("Error\nBad map extension\n");
		exit(0);
	}
	if (s[i - 3] != 'c')
	{
		printf("Error\nBad map extension\n");
		exit(0);
	}
}

void	test_mapname(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	test_dot(s, i);
}
