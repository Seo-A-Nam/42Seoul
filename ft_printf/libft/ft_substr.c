/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:31:14 by senam             #+#    #+#             */
/*   Updated: 2021/09/26 15:18:45 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_substr(char const *s, unsigned int start,
	size_t size, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (size - start < len)
		len = size - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!(sub))
		return (0);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	size = ft_strlen(s);
	if (start >= size)
	{
		sub = malloc(sizeof(char));
		sub[0] = '\0';
	}
	else
		sub = make_substr(s, start, size, len);
	return (sub);
}
