/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:03:43 by senam             #+#    #+#             */
/*   Updated: 2021/05/13 11:20:27 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(int n, int cnt)
{
	if (n == 0 && cnt != 0)
		return (cnt);
	return (ft_nbr_len(n / 10, cnt + 1));
}

static int	ft_power_len(int n)
{
	int	gop;

	gop = 1;
	while (n--)
		gop *= 10;
	return (gop);
}

static char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_itoa(int n)
{
	char	*p;
	int		len;
	int		i;

	len = ft_nbr_len(n, 0);
	if (n < 0)
		len++;
	p = malloc(sizeof(char) * (len + 1));
	if (!(p))
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(p, "-2147483648"));
	i = 0;
	if (n < 0)
	{
		p[i++] = '-';
		n *= -1;
	}
	while (i < len)
	{
		p[i] = ((n / ft_power_len(len - 1 - i)) % 10) + '0';
		i++;
	}
	p[i] = '\0';
	return (p);
}
