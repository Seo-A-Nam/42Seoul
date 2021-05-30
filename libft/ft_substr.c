/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:31:14 by senam             #+#    #+#             */
/*   Updated: 2021/05/13 12:34:17 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	if (start >= size)
	{
		if (!(sub = malloc(sizeof(char))))
			return (0);
	}
	else
	{
		if (size - start < len)
			len = size - start;
		if (!(sub = malloc(sizeof(char) * (len + 1))))
			return (0);
		while (i < len && s[start + i])
		{
			sub[i] = s[start + i];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
