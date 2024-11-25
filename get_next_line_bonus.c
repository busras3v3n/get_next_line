/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:50:49 by busseven          #+#    #+#             */
/*   Updated: 2024/11/25 19:38:32 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	*ft_join(char	*str, char	*joining)
{
	char	*joined;

	if (!str)
		str = ft_calloc(1, 1);
	joined = ft_strjoin(str, joining);
	if (str)
		free(str);
	return (joined);
}

int	ft_findnewline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_read_file(int fd, char	*str)
{
	int		r;
	char	*buf;

	r = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	while (r > 0 || ft_findnewline(buf) == -1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(buf);
			if (str)
				free(str);
			return (NULL);
		}
		if (r == 0)
			break ;
		buf[r] = '\0';
		str = ft_join(str, buf);
		if (ft_findnewline(buf) != -1)
			break ;
	}
	free(buf);
	return (str);
}

char	*new_buffer(char	*buffer)
{
	int		n;
	char	*new;

	if (ft_findnewline(buffer) == -1)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	else
	{
		n = ft_findnewline(buffer);
		new = ft_substr(buffer, n + 1, ft_strlen(buffer + n + 1));
		free(buffer);
		return (new);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (ft_findnewline(buffer[fd]) == -1)
		next_line = ft_substr(buffer[fd], 0, ft_strlen(buffer[fd]));
	else
		next_line = ft_substr(buffer[fd], 0, ft_findnewline(buffer[fd]) + 1);
	if (!next_line)
		return (NULL);
	if (next_line[0] == '\0')
	{
		free(next_line);
		free(buffer[fd]);
		return (NULL);
	}
	buffer[fd] = new_buffer(buffer[fd]);
	return (next_line);
}
