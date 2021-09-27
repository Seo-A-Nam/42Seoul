/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:03:50 by senam             #+#    #+#             */
/*   Updated: 2021/09/26 15:09:54 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (is_charset(set, s1[start]) && s1[start])
		start++;
	return (start);
}

static size_t	get_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1) - 1;
	while (is_charset(set, s1[end]) && end >= 0)
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	index;
	size_t	start;
	size_t	end;
	size_t	size;

	if (*set == 0)
		return (ft_strdup(s1));
	start = get_start(s1, set);
	if (start == ft_strlen(s1))
		size = 1;
	else
	{
		end = get_end(s1, set);
		size = end - start + 2;
	}
	index = 0;
	p = malloc(sizeof(char) * size);
	if (!(p))
		return (0);
	while (start <= end && s1[start])
		p[index++] = s1[start++];
	p[index] = '\0';
	return (p);
}
