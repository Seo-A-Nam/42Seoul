/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:04:25 by senam             #+#    #+#             */
/*   Updated: 2021/06/07 20:16:53 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define OPEN_MAX 1024

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
int		find_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

#endif
