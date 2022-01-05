/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_textws.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namseoa <namseoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:26:19 by namseoa           #+#    #+#             */
/*   Updated: 2022/01/05 12:29:45 by namseoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*handle_notslash(char *str, char *result, int *slash, int *i)
{
	if ((*slash) == 1)
	{
		(*slash) = 0;
		(*result++) = 92;
	}
	(*result++) = str[*i];
	(*i)++;
	return (result);
}

static char	*handle_slash(char *str, char *result, int *slash, int *i)
{
	(*slash) = 0;
	if (str[*i] == 't')
		(*result++) = '\t';
	else if (str[*i] == 'n')
		(*result++) = '\n';
	else if (str[*i] == 'v')
		(*result++) = '\v';
	else if (str[*i] == 'r')
		(*result++) = '\r';
	else if (str[*i] == 'f')
		(*result++) = '\f';
	else if (str[*i] == 92)
	{
		(*result++) = 92;
		(*slash) = 1;
	}
	else
	{
		(*result++) = 92;
		(*result++) = str[*i];
	}
	(*i)++;
	return (result);
}

static void	convert_str(char *str, char *result, int len)
{
	int	i;
	int	slash;

	i = 0;
	slash = 0;
	while (i < len)
	{
		if (str[i] == 92 && slash == 0)
		{
			slash = 1;
			i++;
			continue ;
		}
		else if (slash == 1)
			result = handle_slash(str, result, &slash, &i);
		if (str[i] != 92)
			result = handle_notslash(str, result, &slash, &i);
	}
	if (slash == 1)
		(*result++) = str[len - 1];
	*result = '\0';
}

int	get_count(char *str, int len)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < len)
	{
		if (str[i - 1] == 92)
		{
			if ((str[i] == 't') || (str[i] == 'n')
				|| (str[i] == 'v') || (str[i] == 'r') || (str[i] == 'f'))
				count++;
		}
		i++;
	}
	return (count);
}

char	*ft_convert_textws(char *str)
{
	int		len;
	int		count;
	char	*result;

	len = ft_strlen(str);
	count = get_count(str, len);
	if (count == 0)
		return (ft_strdup(str));
	result = (char *)malloc(sizeof(char) * (len - count));
	if (!(result))
		return (NULL);
	convert_str(str, result, len);
	return (result);
}
