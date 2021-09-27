/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:42:31 by senam             #+#    #+#             */
/*   Updated: 2021/09/26 14:42:53 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(va_list *ap, int *printed_char)
{
	(void)(ap);
	write(1, &"%", 1);
	(*printed_char)++;
}

void	print_pointer(va_list *ap, int *printed_char)
{
	char				base[16];
	unsigned long int	n;

	write(1, &"0x", 2);
	(*printed_char) += 2;
	init_hex_lower_base(base);
	n = va_arg(*ap, unsigned long int);
	print_base(n, 16, base, printed_char);
}
