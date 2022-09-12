/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:46:10 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/26 10:16:01 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_list	*before_get_map(int fd, t_list *liste)
{
	char	*line;

	while (get_next_line(fd, &line) == 1 && line[0] == '\0')
	{
		free(line);
	}
	liste->l = line;
	liste->next = new_element();
	return (liste->next);
}

int		after_get_map(int fd)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] != '\0')
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	free(line);
	return (1);
}

void	wrong_file(int fd)
{
	if (fd < 0)
	{
		printf("Error\nWrong file\n");
		exit(0);
	}
}
