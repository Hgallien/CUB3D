/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:27:08 by hgallien          #+#    #+#             */
/*   Updated: 2021/03/08 11:29:16 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			parsing(t_allp *all, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	wrong_file(fd);
	if (get_info(all, fd))
		exit_get_info(all);
	if (check_info(all))
	{
		exit_check_info(all, fd);
		printf("Error\ntop inforation\n");
		return (-1);
	}
	all->map = get_map(fd, all);
	if (verif_map(all->xmap, all->ymap, all->map, all) <= -1
			|| after_get_map(fd) == -1)
	{
		close(fd);
		printf("Error\nbad map\n");
		return (-1);
	}
	close(fd);
	return (1);
}

int			verif_map(int x, int y, char **map, t_allp *all)
{
	t_var_verif var;

	setup_var_verif(&var);
	while (++var.i < y)
	{
		var.j = -1;
		while (++var.j < x)
		{
			if (is_bad_char(map[var.i][var.j]))
				return (-1);
			if (map[var.i][var.j] == 'P')
				all->nb_door = verif_door(var.i, var.j, all, all->nb_door);
			if (condition_spawn(map, var.i, var.j))
			{
				if (in_conditions(all, x, y, &var) == -1)
					return (-1);
			}
			if (map[var.i][var.j] == '0' || map[var.i][var.j] == '2')
			{
				if (test_close(x, y, var, map) == -1)
					return (-1);
			}
		}
	}
	return (1 * var.v);
}

int			get_info_split(t_allp *all, char *line)
{
	if (line[0] == 'R')
	{
		if (get_first_line(line, all) == -1)
			return (-1);
	}
	else if (line[0] == 'N')
	{
		if (get_path_no(line, all) == -1)
			return (-1);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (get_path_so(line, all) == -1)
			return (-1);
	}
	else if (line[0] == 'W')
	{
		if (get_path_we(line, all) == -1)
			return (-1);
	}
	return (1);
}

int			get_info_splitb(t_allp *all, char *line)
{
	if (line[0] == 'E')
	{
		if (get_path_ea(line, all) == -1)
			return (-1);
	}
	else if (line[0] == 'S' && line[1] != 'O')
	{
		if (get_path_s(line, all) == -1)
			return (-1);
	}
	else if (line[0] == 'F')
	{
		if (color_f(line, all) == -1)
			return (-1);
	}
	else if (line[0] == 'C')
	{
		if (color_c(line, all) == -1)
			return (-1);
	}
	return (1);
}

int			get_info(t_allp *all, int fd)
{
	char	*line;
	int		i;

	while (all->nb_path < 8 && get_next_line(fd, &line) == 1)
	{
		if (line[0] != '\0')
		{
			all->nb_path++;
			i = rm_space(line, 0);
			if (get_info_split(all, &line[i]) == -1)
			{
				free(line);
				return (-1);
			}
			else if (get_info_splitb(all, &line[i]) == -1)
			{
				free(line);
				return (-1);
			}
		}
		free(line);
	}
	return (0);
}
