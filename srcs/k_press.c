/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_press.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:33:14 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/23 10:31:17 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_point		w_key(t_player hugo, char **map, t_allp *all)
{
	t_point	new;
	t_line	l;

	new.x = hugo.s.x + hugo.v.x * 0.1;
	new.y = hugo.s.y + hugo.v.y * 0.1;
	all->nb_hp = all->nb_hp - proc_mine(new, map);
	equation(new, hugo.v, &l);
	new = collision(l, new, map);
	fix(&new);
	return (new);
}

t_point		s_key(t_player hugo, char **map, t_allp *all)
{
	t_point		new;
	t_line		l;
	t_vecteur	v;

	new.x = hugo.s.x - hugo.v.x * 0.1;
	new.y = hugo.s.y - hugo.v.y * 0.1;
	all->nb_hp = all->nb_hp - proc_mine(new, map);
	v.x = -hugo.v.x;
	v.y = -hugo.v.y;
	equation(new, v, &l);
	new = collision(l, new, map);
	fix(&new);
	return (new);
}

t_vecteur	la_key(t_player hugo)
{
	t_vecteur new;

	new = vec_f_angle(hugo.v, 5 / 57.2958);
	return (new);
}

t_vecteur	ra_key(t_player hugo)
{
	t_vecteur new;

	new = vec_f_angle(hugo.v, -5 / 57.2958);
	return (new);
}

int			end(t_allp *all)
{
	mlx_destroy_window(all->mini, all->minik);
	free_img_b(all);
	free_path(all);
	exit(0);
	return (0);
}
