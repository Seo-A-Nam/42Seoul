/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:44:41 by senam             #+#    #+#             */
/*   Updated: 2021/05/04 18:30:38 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dest);
	if (dstsize <= len)
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (src[i] && len + i + 1 < dstsize)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (ft_strlen(src) + len);
}
