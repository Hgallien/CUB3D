/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:21:15 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/22 11:06:34 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	*ft_mlx_img(t_allp *all, char *path, int *width, int *height)
{
	void *temp;

	if ((temp = mlx_xpm_file_to_image(all->mini, path, width, height)) == NULL)
	{
		printf("Error\n with img = %s\n", path);
		exit_load(all);
	}
	return (temp);
}
