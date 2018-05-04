/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 18:59:06 by mxiong            #+#    #+#             */
/*   Updated: 2018/05/03 16:57:34 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_read(char **buf, char **line)
{
	char    *tmp;
	char	*buf_cpy;

	buf_cpy = *buf;
	if ((tmp = ft_strchr(*buf, '\n')))
	{
		*line = ft_strsub(*buf, 0 , tmp - *buf);
		*buf = ft_strdup(tmp + 1);
		free(buf_cpy);
		*buf_cpy = '\0';
		tmp = NULL;
		return (1);
	}
	return (0);
}

static char	*read_byte(const int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;
	int		bytes_read;

	str = ft_strnew(BUFF_SIZE + 1);
	while ((bytes_read = read(fd, buf, BUFF_SIZE)))
	{
		if (bytes_read < 0)
			return (0);
		buf[bytes_read] = '\0';
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
		*tmp = '\0';
	}
	return (str);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf[9999];

	if (fd < 0 || fd > 9999 || !line)
		return (-1);
	if (!buf[fd] && !(buf[fd] = read_byte(fd)))
		return (-1);
	if (buf[fd] && check_read(&buf[fd], line))
		return (1);
	if (buf[fd] == NULL || buf[fd][0] == '\0')
		return (0);
	*line = buf[fd];
	buf[fd] = NULL;
	return (1);
}
