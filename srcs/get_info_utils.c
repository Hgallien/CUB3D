/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:59:12 by hgallien          #+#    #+#             */
/*   Updated: 2021/03/08 11:39:31 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		rm_space(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

int		get_path_s(char *line, t_allp *all)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "S ", 2))
		return (-1);
	i = i + 2;
	while (line[i] == ' ')
		i++;
	all->path.s = ft_strdup(&line[i]);
	return (1);
}

int		get_color(int *color, int i, char *line, int *touched)
{
	*color = *color * 10;
	*color = *color + line[i] - '0';
	*touched = *touched + 1;
	return (i + 1);
}

int		color_f(char *line, t_allp *all)
{
	int i;

	i = 1;
	i = rm_space(line, i);
	while (ft_isdigit(line[i]))
		i = get_color(&all->f.red, i, line, &all->f.touchedr);
	i = rm_space(line, i);
	if (line[i] != ',')
		return (-1);
	i++;
	i = rm_space(line, i);
	while (ft_isdigit(line[i]))
		i = get_color(&all->f.green, i, line, &all->f.touchedg);
	i = rm_space(line, i);
	if (line[i] != ',')
		return (-1);
	i++;
	i = rm_space(line, i);
	while (ft_isdigit(line[i]))
		i = get_color(&all->f.blue, i, line, &all->f.touchedb);
	i = rm_space(line, i);
	if (line[i] != '\0')
		return (-1);
	return (1);
}

int		color_c(char *line, t_allp *all)
{
	int i;

	i = 1;
	i = rm_space(line, i);
	while (ft_isdigit(line[i]))
		i = get_color(&all->c.red, i, line, &all->c.touchedr);
	i = rm_space(line, i);
	if (line[i] != ',')
		return (-1);
	i++;
	i = rm_space(line, i);
	while (ft_isdigit(line[i]))
		i = get_color(&all->c.green, i, line, &all->c.touchedg);
	i = rm_space(line, i);
	if (line[i] != ',')
		return (-1);
	i++;
	i = rm_space(line, i);
	while (ft_isdigit(line[i]))
		i = get_color(&all->c.blue, i, line, &all->c.touchedb);
	i = rm_space(line, i);
	if (line[i] != '\0')
		return (-1);
	return (1);
}
