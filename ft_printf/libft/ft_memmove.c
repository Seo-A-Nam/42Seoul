/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:52:48 by senam             #+#    #+#             */
/*   Updated: 2021/05/24 12:52:56 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*psrc;
	unsigned char	*pdst;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (src == dst)
		return (dst);
	else if (src > dst)
	{
		while (len--)
			*(pdst++) = *(psrc++);
	}
	else
	{
		psrc += len - 1;
		pdst += len - 1;
		while (len--)
			*(pdst--) = *(psrc--);
	}
	return (dst);
}
