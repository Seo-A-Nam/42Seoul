/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:43:03 by senam             #+#    #+#             */
/*   Updated: 2021/05/13 12:24:26 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_cnt(char const *s, char c)
{
	int i;
	int flag;
	int cnt;

	i = 0;
	cnt = 0;
	flag = 0;
	while (s[i])
	{
		flag = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			flag = 1;
		}
		if (flag == 1)
			cnt++;
		if (s[i])
			i++;
	}
	return (cnt);
}

static char	*ft_strndup(char const *s, int size)
{
	char	*p;
	int		i;

	i = 0;
	if (!(p = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (i < size)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static char	**free_all(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}

static char	**ft_word_split(char **p, char const *s, char c)
{
	int	i;
	int	size;
	int	index;

	i = 0;
	index = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		size = 0;
		while (s[i + size] != c && s[i + size])
			size++;
		if (size == 0)
			i++;
		else
		{
			if (!(p[index++] = ft_strndup((s + i), size)))
				return (0);
			i += size;
		}
	}
	p[index] = 0;
	return (p);
}

char		**ft_split(char const *s, char c)
{
	char	**p;
	int		cnt;

	if (*s == 0)
	{
		if (!(p = malloc(sizeof(char *))))
			return (0);
		p[0] = 0;
		return (p);
	}
	cnt = ft_get_cnt(s, c) + 1;
	if (!(p = malloc(sizeof(char *) * cnt)))
		return (0);
	if (!(p = ft_word_split(p, s, c)))
		return (free_all(p));
	return (p);
}
