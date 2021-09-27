/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:41:48 by senam             #+#    #+#             */
/*   Updated: 2021/09/26 14:42:26 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	char	c;

	c = (n % 10) + '0';
	if (n >= 10)
		ft_unsigned_putnbr_fd(n / 10, fd);
	write(fd, &c, 1);
}

void	print_unsigned_int(va_list *ap, int *printed_char)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	ft_unsigned_putnbr_fd(n, 1);
	(*printed_char) += ft_nbr_len(n, 0);
}
