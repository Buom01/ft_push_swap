/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:08:10 by badam             #+#    #+#             */
/*   Updated: 2021/12/08 19:40:56 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_init(int fd, char **line, int *join_state)
{
	if (fd < 0 || !line || !BUFFER_SIZE)
		return (-1);
	*line = malloc(sizeof(char));
	if (!*line)
		return (-1);
	**line = '\0';
	*join_state = 1;
	return (1);
}

int	gnl_finish(int eof, char **line)
{
	if (eof == -1)
	{
		free(*line);
		*line = NULL;
	}
	if (eof > 0)
		return (1);
	else
		return (eof);
}

size_t	ft_strlen(const char *str)
{
	char	*end;

	end = (char *)str;
	while (*end)
		end++;
	return ((const char *)end - str);
}
