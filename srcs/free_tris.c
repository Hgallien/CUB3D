/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:59:45 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/23 11:10:21 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	exit_check_info(t_allp *all, int fd)
{
	printf("Error\ntop informations \n");
	free_path(all);
	close(fd);
	exit(0);
}

void	exit_get_info(t_allp *all)
{
	if (all->path.no != NULL)
		free(all->path.no);
	if (all->path.so != NULL)
		free(all->path.so);
	if (all->path.ea != NULL)
		free(all->path.ea);
	if (all->path.we != NULL)
		free(all->path.we);
	if (all->path.s != NULL)
		free(all->path.s);
	printf("Error\ntop informations\n");
	exit(0);
}

void	free_path_exit(t_allp *all)
{
	free_path(all);
	exit(0);
}

void	free_list(t_list *l)
{
	free(l->l);
	free(l);
}

void	exit_load(t_allp *all)
{
	int i;

	i = 0;
	free_img_b(all);
	free_path(all);
	while (i < all->ymap)
	{
		free(all->map[i]);
		i++;
	}
	free(all->map);
	exit(0);
}
