/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:25:28 by hgallien          #+#    #+#             */
/*   Updated: 2021/02/15 12:14:41 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] - s2[i] == 0)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(const char *src)
{
	char *dup;

	dup = malloc(sizeof(char) * ft_strlenb(src) + 1);
	if (dup == NULL)
	{
		return (dup);
	}
	ft_strlcpyb(dup, src, ft_strlenb(src) + 1);
	return (dup);
}

size_t	ft_strlenb(const char *s)
{
	size_t x;

	x = 0;
	while (s[x])
	{
		x++;
	}
	return (x);
}

size_t	ft_strlcpyb(char *dst, const char *src, size_t dstsize)
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
	return (ft_strlenb(src));
}
