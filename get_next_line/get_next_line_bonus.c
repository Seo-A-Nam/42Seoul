/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:32:13 by senam             #+#    #+#             */
/*   Updated: 2021/06/10 17:32:14 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		error_return(char **backup)
{
	if (*backup)
	{
		free(*backup);
		*backup = 0;
	}
	return (-1);
}

int		get_one_line(char **backup, char **line, int nl_idx)
{
	char	*tmp;

	(*backup)[nl_idx] = '\0';
	if (!(*line = ft_strdup(*backup)))
		return (error_return(backup));
	if (!(tmp = ft_strdup(*backup + nl_idx + 1)))
		return (error_return(backup));
	free(*backup);
	*backup = tmp;
	tmp = 0;
	return (1);
}

int		get_all(char **backup, char **line)
{
	int		nl_idx;

	if (*backup && ((nl_idx = find_newline(*backup)) >= 0))
		return (get_one_line(backup, line, nl_idx));
	else if (*backup)
	{
		*line = ft_strdup(*backup);
		free(*backup);
		*backup = 0;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			nl_idx;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!backup[fd])
	{
		if (!(backup[fd] = malloc(sizeof(char))))
			return (-1);
		backup[fd][0] = '\0';
	}
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if (!(backup[fd] = ft_strjoin(backup[fd], buf)))
			return (-1);
		if ((nl_idx = find_newline(backup[fd])) >= 0)
			return (get_one_line(&backup[fd], line, nl_idx));
	}
	if (read_size < 0)
		return (error_return(&backup[fd]));
	return (get_all(&backup[fd], line));
}
