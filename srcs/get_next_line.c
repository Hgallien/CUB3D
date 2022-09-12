/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:18:40 by hgallien          #+#    #+#             */
/*   Updated: 2021/01/15 11:50:30 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		testb(char *b, int debut)
{
	int i;
	int c;

	c = 0;
	i = debut;
	while (i < BUFFER_SIZE)
	{
		if (b[i] == '\n')
			return (c);
		i++;
		c++;
	}
	return (-1);
}

void	cleanb(char *b, int fin, int debut)
{
	int i;

	i = 0;
	while (i + debut < BUFFER_SIZE && i <= fin)
	{
		b[i] = '\0';
		i++;
	}
}

int		set_end(int debut, int *r, char *b)
{
	if (*r > 1)
		*r = 1;
	if (*r == 0)
	{
		cleanb(b, BUFFER_SIZE, debut);
		return (0);
	}
	if (debut >= BUFFER_SIZE)
		return (0);
	return (debut);
}

void	set_start(int *fin, int *r, char **line)
{
	*fin = 0;
	*r = 1;
	if (line != NULL)
	{
		*line = malloc(1);
		*line[0] = '\0';
	}
}

int		get_next_line(int fd, char **line)
{
	static int	debut;
	int			fin;
	static char	b[BUFFER_SIZE];
	int			r;

	set_start(&fin, &r, line);
	if (debut == 0 && BUFFER_SIZE != 0)
		r = read(fd, b, BUFFER_SIZE);
	if (line == NULL || r == -1 || BUFFER_SIZE == 0)
		return (-1);
	while (r && (fin = testb(b, debut)) == -1)
	{
		*line = ft_strjoin(*line, &b[debut], BUFFER_SIZE - debut);
		cleanb(&b[debut], BUFFER_SIZE - debut, debut);
		r = read(fd, b, BUFFER_SIZE);
		if (r == -1)
			return (r);
		debut = 0;
	}
	*line = ft_strjoin(*line, &b[debut], fin);
	cleanb(&b[debut], fin, debut);
	debut = debut + fin + 1;
	debut = set_end(debut, &r, b);
	return (r);
}
