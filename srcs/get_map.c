/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:17:37 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/23 10:35:35 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_list			*new_element(void)
{
	t_list *new;

	new = malloc(sizeof(t_list*) * 2);
	new->next = 0;
	return (new);
}

t_list			*cp_list(t_list *list, char *line)
{
	int		i;
	t_list	*temp;

	i = 0;
	while (list->l[i] != '\0')
	{
		line[i] = list->l[i];
		i++;
	}
	temp = list->next;
	free(list->l);
	free(list);
	return (temp);
}

char			**list_to_map(t_list *l, int x, int y, t_allp *all)
{
	char	**map;
	int		i;
	int		j;
	int		d;

	i = -1;
	if ((map = malloc(sizeof(char *) * x)) == NULL)
		free_path_exit(all);
	while (++i < x)
	{
		j = -1;
		d = -1;
		if ((map[i] = malloc(sizeof(char) * y)) == NULL)
			exit_map(map, i - 1, all);
		while (++d < y)
			map[i][d] = ' ';
		l = cp_list(l, map[i]);
		while (++j < y)
		{
			if (map[i][j] == '\0' || map[i][j] == ' ')
				map[i][j] = 'v';
		}
	}
	free_list(l);
	return (map);
}

char			**get_map(int fd, t_allp *all)
{
	int		i;
	int		max;
	t_list	*liste;
	t_list	*temp;

	i = 1;
	liste = new_element();
	max = 0;
	temp = before_get_map(fd, liste);
	while (get_next_line(fd, (&(temp->l))) == 1 && temp->l[0] != '\0')
	{
		if ((int)ft_strlenb(temp->l) > max)
			max = ft_strlenb(temp->l);
		temp->next = new_element();
		temp = temp->next;
		i++;
	}
	all->xmap = max;
	all->ymap = i;
	return (list_to_map(liste, i, max, all));
}

void			setup_var_verif(t_var_verif *var)
{
	var->p = 0;
	var->i = -1;
	var->v = -1;
}
