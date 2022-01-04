/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namseoa <namseoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:36:04 by senam             #+#    #+#             */
/*   Updated: 2022/01/04 14:39:13 by namseoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int					ft_atoi(const char *str);
size_t				ft_strlen(char const *str);
void				ft_putnbr_fd(int n, int fd);

#endif
