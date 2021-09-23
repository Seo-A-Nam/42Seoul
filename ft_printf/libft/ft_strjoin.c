/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:45:15 by senam             #+#    #+#             */
/*   Updated: 2021/05/13 12:25:59 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		index;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	index = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (0);
	while (s1[i])
		str[index++] = s1[i++];
	while (s2[j])
		str[index++] = s2[j++];
	str[index] = '\0';
	return (str);
}
