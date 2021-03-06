/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:43:19 by senam             #+#    #+#             */
/*   Updated: 2021/09/26 14:44:44 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_base(unsigned long int n, int base_len,
		char *base, int *printed_char)
{
	if (n == 0)
		return ;
	convert_base(n / base_len, base_len, base, printed_char);
	write(1, &base[n % base_len], 1);
	(*printed_char)++;
}

void	print_base(unsigned long int n, int base_len,
		char *base, int *printed_char)
{
	if (n == 0)
	{
		write(1, &base[0], 1);
		(*printed_char)++;
		return ;
	}
	convert_base(n, base_len, base, printed_char);
}
