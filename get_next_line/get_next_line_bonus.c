/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:35:46 by abarrier          #+#    #+#             */
/*   Updated: 2022/02/03 10:02:06 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	gnl_shiftbuf(char *buf)
{
	char	*nl;
	size_t	inl;

	nl = gnl_strchr(buf, '\n');
	inl = 0;
	if (nl == 0)
		buf[0] = '\0';
	else
	{
		inl = gnl_strlen(buf);
		gnl_strncpy(buf, &buf[inl], (size_t)BUFFER_SIZE);
	}
}

static void	gnl_eof(char *buf, char *line)
{
	if (!line || line[0] == '\0')
	{
		if (line)
			free(line);
		free(buf);
	}
}

static char	*gnl_line(int fd, char *buf)
{
	char	*line;
	ssize_t	letters;

	line = 0;
	letters = 0;
	line = gnl_strjoin(line, buf);
	while (!gnl_strchr(buf, '\n'))
	{
		letters = read(fd, buf, (size_t)BUFFER_SIZE);
		if (letters <= 0)
			break ;
		buf[letters] = '\0';
		line = gnl_strjoin(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (0);
	if (!buf[fd])
	{
		buf[fd] = (char *)malloc(sizeof(char) * (size_t)(BUFFER_SIZE + 1));
		if (!buf[fd])
			return (0);
		buf[fd][0] = '\0';
	}
	line = gnl_line(fd, buf[fd]);
	if (!line || line[0] == '\0')
	{
		gnl_eof(buf[fd], line);
		buf[fd] = 0;
		line = 0;
	}
	else
		gnl_shiftbuf(buf[fd]);
	return (line);
}
