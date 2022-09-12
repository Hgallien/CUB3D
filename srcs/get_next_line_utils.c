/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:39:09 by hgallien          #+#    #+#             */
/*   Updated: 2020/12/02 14:10:21 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *s)
{
	size_t x;

	x = 0;
	while (s[x])
	{
		x++;
	}
	return (x);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t x;

	if (src == NULL || dst == NULL)
		return (0);
	if (dstsize > 0)
	{
		x = 0;
		while (x < dstsize - 1 && src[x])
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	return (0);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	if (n > 0)
	{
		i = ft_strlen(dest);
		j = 0;
		while ((j < n && src[j] != '\0') && (src[j] != '\n'))
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
	}
	return (0);
}

char			*ft_strjoin(char *s1, char *s2, int x)
{
	char	*res;
	int		t;

	t = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	t = t + ft_strlen(s1) + 1;
	t = t + x;
	res = malloc(t + 1);
	if (!(res))
		return (NULL);
	res[0] = '\0';
	if (s1)
		ft_strlcat(res, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcat(res, s2, x);
	free(s1);
	return (res);
}
