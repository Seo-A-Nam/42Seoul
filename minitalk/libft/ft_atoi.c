/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namseoa <namseoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:04:32 by senam             #+#    #+#             */
/*   Updated: 2022/01/04 18:08:15 by namseoa          ###   ########.fr       */
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

int	ft_atoi(const char *str)
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
		ret = check_long_long(nb, sign);
		if (ret != 1)
			return (ret);
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (sign * (int)nb);
}
