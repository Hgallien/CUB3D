/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_press_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:35:44 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/23 10:31:34 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_point		d_key(t_player hugo, char **map, t_allp *all)
{
	t_point		new;
	t_vecteur	v;
	t_line		l;

	new.x = hugo.s.x + (hugo.v.y * -1) * 0.1;
	new.y = hugo.s.y + hugo.v.x * 0.1;
	all->nb_hp = all->nb_hp - proc_mine(new, map);
	v.x = -hugo.v.y;
	v.y = hugo.v.x;
	equation(new, v, &l);
	new = collision(l, new, map);
	fix(&new);
	return (new);
}

void		*ft_system(void *command)
{
	system(command);
	return (NULL);
}

void		shoot(t_allp *param)
{
	t_object	*obj;
	t_point		wall;
	t_line		l;
	pthread_t	thread;

	if (param->gun_state > 4)
		return ;
	pthread_create(&thread, NULL, ft_system, "afplay gunsound.wav");
	pthread_detach(thread);
	param->gun_state = 1;
	equation(param->hugo->s, param->hugo->v, &l);
	obj = find_obj(l, param->hugo->s, param->hugo->v, param);
	wall = find_wall(l, param->hugo->s, param->map);
	if (obj[0].p.x != -42 && distance(param->hugo->s, obj[0].p)
	< distance(param->hugo->s, wall) && obj[0].ref == '2')
		param->map[(int)floor(obj[0].p.y)][(int)floor(obj[0].p.x)] = '3';
	free(obj);
}

t_point		a_key(t_player hugo, char **map, t_allp *all)
{
	t_point		new;
	t_vecteur	v;
	t_line		l;

	new.x = hugo.s.x + hugo.v.y * 0.1;
	new.y = hugo.s.y + (hugo.v.x * -1) * 0.1;
	all->nb_hp = all->nb_hp - proc_mine(new, map);
	v.x = hugo.v.y;
	v.y = -hugo.v.x;
	equation(new, v, &l);
	new = collision(l, new, map);
	fix(&new);
	return (new);
}

void		open_door(t_allp *all)
{
	t_point	new;
	int		i;

	new.x = all->hugo->s.x + (all->hugo->v.x * 0.5);
	new.y = all->hugo->s.y + (all->hugo->v.y * 0.5);
	if ((i = is_door_bis(new, all)) != -1)
	{
		all->door_state[i] = all->door_state[i] * -1;
		if (all->door_state[i] == -1)
			all->map[(int)(all->door[i].y)][(int)(all->door[i].x)] = '0';
		else
			all->map[(int)(all->door[i].y)][(int)(all->door[i].x)] = '1';
	}
}
