/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:05:56 by hgallien          #+#    #+#             */
/*   Updated: 2021/03/12 11:20:19 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "mlx.h"
#include <pthread.h>

void		setup_allp(t_allp *all)
{
	all->nb_hp = 100;
	all->nb_door = 0;
	all->nb_path = 0;
	all->res = 0;
	all->resw = 0;
	all->f.red = 0;
	all->i_obj = 0;
	all->gun_state = 0;
	setup_img(all);
	all->f.blue = 0;
	all->f.green = 0;
	all->c.red = 0;
	all->c.touchedr = 0;
	all->c.touchedg = 0;
	all->c.touchedb = 0;
	all->f.touchedb = 0;
	all->f.touchedg = 0;
	all->f.touchedr = 0;
	all->c.blue = 0;
	all->c.green = 0;
	all->path.no = NULL;
	all->path.so = NULL;
	all->path.we = NULL;
	all->path.ea = NULL;
	all->path.s = NULL;
}

int			handle_arg(int ag, char *av[], t_allp *all)
{
	all->save = 0;
	if (ag == 1)
	{
		printf("Error\nno map\n");
		return (-1);
	}
	if (ag == 2)
		test_mapname(av[1]);
	if (ag == 3)
	{
		if (ft_strncmp(av[2], "--save", 100) != 0)
		{
			printf("Error\nonly second argument possible is --save\n");
			return (-1);
		}
		else
			all->save = 1;
	}
	if (ag > 3)
	{
		printf("Error\nToo many arguments\n");
		return (-1);
	}
	return (1);
}

void		lunch_bit(t_allp *all)
{
	final_display(all);
	bmp_setup(all);
	free_img_b(all);
	free_path(all);
	exit(0);
}

void		setup_var_main(t_allp *all, t_player *hugo)
{
	all->f.t = all->f.blue + all->f.green * 16 * 16 + all->f.red * 65536;
	all->c.t = all->c.blue + all->c.green * 16 * 16 + all->c.red * 65536;
	hugo->s = all->s;
	hugo->v = all->v;
}

int			main(int ag, char *av[])
{
	t_allp		all;
	t_player	hugo;

	if (handle_arg(ag, av, &all) != 1)
		return (0);
	setup_allp(&all);
	if (parsing(&all, av[1]) < 0)
		exit_parse(&all);
	setup_var_main(&all, &hugo);
	all.hugo = &hugo;
	all.mini = mlx_init();
	all.minik = mlx_new_window(all.mini, all.resw, all.res, "cub3D");
	load_all(&all);
	equation(all.hugo->s, all.hugo->v, &all.hugo->l);
	if (all.save == 1)
	{
		lunch_bit(&all);
		return (0);
	}
	mlx_hook(all.minik, 2, 1l << 0, &k_press, &all);
	mlx_hook(all.minik, 17, 0, &end, &all);
	mlx_loop_hook(all.mini, &lunch_display, &all);
	mlx_loop(all.mini);
}
