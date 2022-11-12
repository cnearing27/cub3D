/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:32:21 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:32:22 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(int fd, char *buf, int *fd_read)
{
	*fd_read = (int)read(fd, buf, BUFFER_SIZE);
	return (*fd_read);
}

static int	ft_line(char **ostatok, char **line)
{
	char	*ptrn;
	char	*tmp;

	ptrn = NULL;
	tmp = NULL;
	ptrn = ft_strchr(*ostatok, '\n');
	if (ptrn)
	{
		*ptrn = '\0';
		tmp = *ostatok;
		*line = ft_strdup(tmp);
		ptrn++;
		*ostatok = ft_strdup(ptrn);
		ft_free(&tmp);
	}
	else
	{
		tmp = *line;
		*line = ft_strdup(*ostatok);
		ft_free(ostatok);
		return (0);
	}
	return (1);
}

static int	ft_exit(char **ostatok, char **line, int fd_read)
{
	if (fd_read == 0)
	{
		if (*ostatok)
			return (ft_line(ostatok, line));
		else
			*line = ft_strdup("");
		return (0);
	}
	else
		return (ft_line(ostatok, line));
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			fd_read;
	static char	*ostatok;
	char		*tmp;

	if ((read(fd, 0, 0) < 0) || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((ft_read(fd, buf, &fd_read)) > 0)
	{
		buf[fd_read] = '\0';
		if (ostatok == NULL)
			ostatok = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(ostatok, buf);
			ft_free(&ostatok);
			ostatok = tmp;
			tmp = NULL;
		}
		if (ft_strchr(ostatok, '\n'))
			break ;
	}
	ft_free(&buf);
	return (ft_exit(&ostatok, line, fd_read));
}
