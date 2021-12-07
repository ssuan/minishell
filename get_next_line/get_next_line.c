/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:56:11 by suan              #+#    #+#             */
/*   Updated: 2021/08/03 00:01:45 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char **backup, char **line)
{
	char	*pos;
	char	*tmp;
	int		len;

	pos = ft_strchr_gnl(*backup, '\n');
	*pos = 0;
	*line = ft_strdup_gnl(*backup);
	len = ft_strlen_gnl(pos + 1);
	if (!len)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	tmp = ft_strdup_gnl(pos + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

static int	return_all(char **backup, char **line)
{
	if (*backup && ft_strchr_gnl(*backup, '\n'))
		return (get_line(backup, line));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup_gnl("");
	return (0);
}

static int	read_file(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_byte;

	read_byte = BUFFER_SIZE;
	while (read_byte > 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		buf[read_byte] = 0;
		backup[fd] = ft_strjoin_gnl(backup[fd], buf);
		if (ft_strchr_gnl(backup[fd], '\n'))
			return (get_line(&backup[fd], line));
	}
	if (read_byte == -1)
		return (-1);
	return (return_all(&backup[fd], line));
}

int	get_next_line(int fd, char **line)
{
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	return (read_file(fd, line));
}
