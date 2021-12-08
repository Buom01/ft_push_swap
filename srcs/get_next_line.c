/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:06:05 by badam             #+#    #+#             */
/*   Updated: 2021/12/08 20:23:56 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	buff_strip_used(size_t len, char *buffer)
{
	size_t	i;
	int		same_line;

	same_line = 1;
	i = 0;
	if (len < BUFFER_SIZE && (buffer[len] == '\n' || buffer[len] == '\r'))
	{
		len++;
		same_line = 0;
	}
	while (i + len < BUFFER_SIZE)
	{
		buffer[i] = buffer[i + len];
		i++;
	}
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
	return (same_line);
}

static size_t	buff_curnt_line_len(char *buffer)
{
	size_t	len;

	len = 0;
	while (len < BUFFER_SIZE && *buffer && *buffer != '\r' && *buffer != '\n')
	{
		len++;
		buffer++;
	}
	return (len);
}

static int	line_joinbuff(char **line, char *buffer, size_t len)
{
	size_t	newlen;
	char	*newline;
	char	*newlinecpy;
	char	*linecpy;

	newlen = ft_strlen(*line) + len + 1;
	newline = malloc(newlen * sizeof(char));
	if (!newline)
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	newlinecpy = newline;
	linecpy = *line;
	while (*linecpy)
		*(newlinecpy++) = *(linecpy++);
	while (len && len--)
		*(newlinecpy++) = *(buffer++);
	*newlinecpy = '\0';
	free(*line);
	*line = newline;
	return (1);
}

static int	joinline(char **line, char *buffer)
{
	size_t	bufflen;

	bufflen = buff_curnt_line_len(buffer);
	if (bufflen)
		if (!line_joinbuff(line, buffer, bufflen))
			return (-1);
	return (buff_strip_used(bufflen, buffer));
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE];
	int			prefill;
	int			eof;
	int			join_state;

	eof = gnl_init(fd, line, &join_state);
	if (eof != 1)
		return (eof);
	prefill = (BUFFER_SIZE && *buffer != 0);
	if (!prefill)
		eof = read(fd, buffer, BUFFER_SIZE);
	while (prefill || (join_state && eof > 0))
	{
		join_state = joinline(line, buffer);
		if (join_state == -1)
			return (-1);
		prefill = 0;
		if (join_state)
			eof = read(fd, buffer, BUFFER_SIZE) > 0;
	}
	return (gnl_finish(eof, line));
}
