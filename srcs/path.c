/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:07:37 by hgallien          #+#    #+#             */
/*   Updated: 2021/03/08 11:36:14 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		get_first_line(char *line, t_allp *all)
{
	int i;

	i = 1;
	if (line[i] != ' ')
		return (-1);
	i = rm_space(line, i);
	if (ft_isdigit(line[i]) == 0)
		return (-1);
	while (ft_isdigit(line[i]))
	{
		add_res(&all->resw, line[i++]);
	}
	i = rm_space(line, i);
	if (ft_isdigit(line[i]) == 0)
		return (-1);
	while (ft_isdigit(line[i]))
	{
		add_res(&all->res, line[i++]);
	}
	i = rm_space(line, i);
	if (line[i] != '\0')
		return (-1);
	if (all->resw > 0 && all->res > 0)
		return (1);
	return (-1);
}

int		get_path_no(char *line, t_allp *all)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "NO ", 3))
		return (-1);
	i = i + 3;
	while (line[i] == ' ')
		i++;
	all->path.no = ft_strdup(&line[i]);
	return (1);
}

int		get_path_so(char *line, t_allp *all)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "SO ", 3))
		return (-1);
	i = i + 3;
	while (line[i] == ' ')
		i++;
	all->path.so = ft_strdup(&line[i]);
	return (1);
}

int		get_path_we(char *line, t_allp *all)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "WE ", 3))
		return (-1);
	i = i + 3;
	while (line[i] == ' ')
		i++;
	all->path.we = ft_strdup(&line[i]);
	return (1);
}

int		get_path_ea(char *line, t_allp *all)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "EA ", 3))
		return (-1);
	i = i + 3;
	while (line[i] == ' ')
		i++;
	all->path.ea = ft_strdup(&line[i]);
	return (1);
}
