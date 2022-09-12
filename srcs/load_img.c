/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:50:14 by hgallien          #+#    #+#             */
/*   Updated: 2021/03/08 09:56:02 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		load_bonus_bis(t_allp *all)
{
	all->obj[1].img = ft_mlx_img(all, "./texture/explosion1.xpm",
			&all->obj[1].w, &all->obj[1].h);
	all->obj[1].addr = mlx_get_data_addr(all->obj[1].img,
			&(all->obj[1].bits_per_pixel), &(all->obj[1].line_length),
			&(all->obj[1].endian));
	all->obj[2].img = ft_mlx_img(all, "./texture/explosion2.xpm",
			&all->obj[2].w, &all->obj[2].h);
	all->obj[2].addr = mlx_get_data_addr(all->obj[2].img,
			&(all->obj[2].bits_per_pixel), &(all->obj[2].line_length),
			&(all->obj[2].endian));
	all->obj[3].img = ft_mlx_img(all, "./texture/explosion3.xpm",
			&all->obj[3].w, &all->obj[3].h);
	all->obj[3].addr = mlx_get_data_addr(all->obj[3].img,
			&(all->obj[3].bits_per_pixel), &(all->obj[3].line_length),
			&(all->obj[3].endian));
	all->gun[0].img = ft_mlx_img(all, "./texture/gun1.xpm",
			&all->gun[0].w, &all->gun[0].h);
	all->gun[0].addr = mlx_get_data_addr(all->gun[0].img,
			&(all->gun[0].bits_per_pixel), &(all->gun[0].line_length),
			&(all->gun[0].endian));
	all->gun[1].img = ft_mlx_img(all, "./texture/gun2.xpm",
			&all->gun[1].w, &all->gun[1].h);
	all->gun[1].addr = mlx_get_data_addr(all->gun[1].img,
			&(all->gun[1].bits_per_pixel), &(all->gun[1].line_length),
			&(all->gun[1].endian));
}

void		load_all(t_allp *all)
{
	load_bonus(all);
	load_bonus_bis(all);
	load_wall(all);
	load_obj(all);
}

void		load_bonus(t_allp *all)
{
	all->gun[2].img = ft_mlx_img(all, "./texture/gun3.xpm",
			&all->gun[2].w, &all->gun[2].h);
	all->gun[2].addr = mlx_get_data_addr(all->gun[2].img,
			&(all->gun[2].bits_per_pixel), &(all->gun[2].line_length),
			&(all->gun[3].endian));
	all->gun[3].img = ft_mlx_img(all, "./texture/gun4.xpm",
			&all->gun[3].w, &all->gun[3].h);
	all->gun[3].addr = mlx_get_data_addr(all->gun[3].img,
			&(all->gun[3].bits_per_pixel), &(all->gun[3].line_length),
			&(all->gun[3].endian));
	all->gun[4].img = ft_mlx_img(all, "./texture/gun5.xpm",
			&all->gun[4].w, &all->gun[4].h);
	all->gun[4].addr = mlx_get_data_addr(all->gun[4].img,
			&(all->gun[4].bits_per_pixel), &(all->gun[4].line_length),
			&(all->gun[4].endian));
	all->hp.img = mlx_new_image(all->mini, 600, 200);
	all->hp.addr = mlx_get_data_addr(all->hp.img,
			&all->hp.bits_per_pixel, &all->hp.line_length, &all->hp.endian);
}

void		load_wall(t_allp *all)
{
	all->wall[0].img = ft_mlx_img(all, all->path.no,
			&(all->wall[0].w), &(all->wall[0].h));
	all->wall[0].addr = mlx_get_data_addr(all->wall[0].img,
	&(all->wall[0].bits_per_pixel), &(all->wall[0].line_length),
	&(all->wall[0].endian));
	all->wall[1].img = ft_mlx_img(all, all->path.we,
	&(all->wall[1].w), &(all->wall[1].h));
	all->wall[1].addr = mlx_get_data_addr(all->wall[1].img,
	&(all->wall[1].bits_per_pixel), &(all->wall[1].line_length),
	&(all->wall[1].endian));
	all->wall[2].img = ft_mlx_img(all, all->path.ea,
	&(all->wall[2].w), &(all->wall[2].h));
	all->wall[2].addr = mlx_get_data_addr(all->wall[2].img,
		&(all->wall[2].bits_per_pixel), &(all->wall[2].line_length),
	&(all->wall[2].endian));
	all->wall[3].img = ft_mlx_img(all, all->path.so,
	&(all->wall[3].w), &(all->wall[3].h));
	all->wall[3].addr = mlx_get_data_addr(all->wall[3].img,
	&(all->wall[3].bits_per_pixel), &(all->wall[3].line_length),
	&(all->wall[3].endian));
}

void		load_obj(t_allp *all)
{
	all->s_door.img = ft_mlx_img(all, "./texture/door.xpm",
	&(all->s_door.w), &(all->s_door.h));
	all->s_door.addr = mlx_get_data_addr(all->s_door.img,
	&(all->s_door.bits_per_pixel), &(all->s_door.line_length),
	&(all->s_door.endian));
	all->obj[4].img = ft_mlx_img(all,
	"./texture/rigo_mine.xpm", &all->obj[4].w, &all->obj[4].h);
	all->obj[4].addr = mlx_get_data_addr(all->obj[4].img,
	&(all->obj[4].bits_per_pixel), &(all->obj[4].line_length),
	&(all->obj[4].endian));
	all->obj[0].img = ft_mlx_img(all,
	all->path.s, &all->obj[0].w, &all->obj[0].h);
	all->obj[0].addr = mlx_get_data_addr(all->obj[0].img,
	&(all->obj[0].bits_per_pixel), &(all->obj[0].line_length),
	&(all->obj[0].endian));
}
