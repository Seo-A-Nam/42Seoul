/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:01:38 by senam             #+#    #+#             */
/*   Updated: 2021/05/11 19:52:49 by namseoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = malloc(size * (count));
	if (ptr == 0)
		return ((void *)ptr);
	i = 0;
	while (i < size * count)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
