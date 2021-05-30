/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:04:32 by senam             #+#    #+#             */
/*   Updated: 2021/05/11 19:52:20 by namseoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
			|| c == '\r' || c == '\f' || c == '\n')
		return (1);
	return (0);
}

static int	is_operater(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

static int	check_long_long(unsigned long long nb, int sign)
{
	if (nb > 0 && (nb - 1 > 9223372036854775807) && sign == -1)
		return (0);
	if (nb > 9223372036854775807 && sign == 1)
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	unsigned long long	nb;
	int					i;
	int					sign;
	int					ret;

	i = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (is_operater(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((ret = check_long_long(nb, sign)) != 1)
			return (ret);
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return (sign * (int)nb);
}
