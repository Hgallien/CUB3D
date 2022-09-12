/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:56:12 by hgallien          #+#    #+#             */
/*   Updated: 2021/03/08 10:59:05 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	if ((unsigned int)color >= 0xff000000)
		return ;
	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			my_mlx_pixel_get(t_data *data, int x, int y)
{
	char *dst;

	if (y > data->h - 1)
		y = data->h - 1;
	if (x > data->w - 1)
		x = data->w - 1;
	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void		find_touches(t_allp *all, t_player hugo, char **map)
{
	int i;

	i = 0;
	while (i < all->resw)
	{
		all->i_obj = i;
		all->tab.touches[i] = find_wall(
				all->tab.rayons[i], hugo.s, map);
		all->s_wall[i] = find_side(
				all->tab.touches[i], all->tab.rayons[i]);
		all->tab.touches_obj[i] = find_obj(
				all->tab.rayons[i], hugo.s, hugo.v, all);
		i++;
	}
}

void		calc_rayons_touches(t_player hugo, char **map, t_allp *all)
{
	int		i;
	float	angle;

	angle = (45 / 57.2958) / (float)all->resw;
	i = 0;
	while (i < all->resw / 2)
	{
		equation(hugo.s, vec_f_angle(hugo.v, -angle * i),
				&all->tab.rayons[i]);
		all->tab.angles[i] = angle * i;
		i++;
	}
	i = 0;
	while (i < all->resw / 2)
	{
		equation(hugo.s, vec_f_angle(hugo.v, angle * i),
				&all->tab.rayons[all->resw / 2 + i]);
		all->tab.angles[all->resw / 2 + i] = -angle * i;
		i++;
	}
	find_touches(all, hugo, map);
}

void		final_display(t_allp *all)
{
	static int	timer;

	malloc_land(&all->tab, all->resw, all);
	equation(all->hugo->s, all->hugo->v, &(all->hugo->l));
	calc_rayons_touches(*(all->hugo), all->map, all);
	all->img.img = mlx_new_image(all->mini, all->resw, all->res);
	all->img.addr = mlx_get_data_addr(all->img.img,
			&(all->img.bits_per_pixel),
			&(all->img.line_length), &(all->img.endian));
	all->img.h = all->res;
	all->img.w = all->resw;
	wall_display(all->tab, all, all->resw);
	obj_display_upper(all->tab, all, all->resw);
	hp_bar(all, all->nb_hp);
	mlx_put_image_to_window(
			all->mini, all->minik, all->img.img, 0, 0);
	handle_gun(all);
	mlx_destroy_image(all->mini, all->img.img);
	timer = explosion(all, timer);
	free_land(all);
}
