/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:09:56 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/19 11:48:28 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	exit_map(char **map, int i, t_allp *all)
{
	while (i > 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	free_path(all);
	exit(0);
}

void	exit_parse(t_allp *all)
{
	int i;

	i = 0;
	while (i < all->ymap)
	{
		free(all->map[i]);
		i++;
	}
	free(all->map);
	free_path(all);
	exit(0);
}

void	exit_find_obj(t_allp *all)
{
	free(all->s_wall);
	free(all->tab.angles);
	free(all->tab.touches);
	free(all->tab.rayons);
	all->i_obj--;
	while (all->i_obj < 0)
	{
		free(all->tab.touches_obj[all->i_obj]);
		all->i_obj--;
	}
	exit(0);
}

void	free_path(t_allp *all)
{
	free(all->path.no);
	free(all->path.so);
	free(all->path.we);
	free(all->path.ea);
	free(all->path.s);
}

void	free_img_b(t_allp *all)
{
	int i;

	i = -1;
	if (all->s_door.img != NULL)
		mlx_destroy_image(all->mini, all->s_door.img);
	while (++i < 5)
	{
		if (all->gun[i].img != NULL)
			mlx_destroy_image(all->mini, all->gun[i].img);
	}
	i = -1;
	while (++i < 4)
	{
		if (all->wall[i].img != NULL)
			mlx_destroy_image(all->mini, all->wall[i].img);
	}
	i = -1;
	while (++i < 5)
	{
		if (all->obj[i].img != NULL)
			mlx_destroy_image(all->mini, all->obj[i].img);
	}
	if (all->hp.img != NULL)
		mlx_destroy_image(all->mini, all->hp.img);
}
