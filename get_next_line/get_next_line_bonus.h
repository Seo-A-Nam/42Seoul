/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:33:07 by senam             #+#    #+#             */
/*   Updated: 2021/06/10 17:33:09 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define OPEN_MAX 1024

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
int		find_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

#endif
