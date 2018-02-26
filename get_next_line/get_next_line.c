/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:29:33 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/22 19:05:05 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <fcntl.h>

static int		ft_isline(char **stock, int nbread)
{
	int i;

	i = 0;
	while ((*stock)[i])
	{
		if ((*stock)[i] == '\n')
			return (1);
		++i;
	}
	if (nbread == 0 && ft_strlen(*stock) != 0)
		return (1);
	if (nbread == 0 && ft_strlen(*stock) == 0)
		return (2);
	return (0);
}

static char		*ft_line(char **str)
{
	char	*line;
	size_t	i;
	char	*tmp;

	i = 0;
	while ((*str)[i] != '\n' && i < ft_strlen(*str))
		++i;
	if ((*str)[i] != '\n')
	{
		if (!(line = ft_strnew(ft_strlen(*str))))
			return (NULL);
		line = ft_strcpy(line, *str);
		(*str)[0] = '\0';
		return (line);
	}
	if (!(line = ft_strsub(*str, 0, i)))
		return (NULL);
	if (!(tmp = ft_strsub(*str, i + 1, ft_strlen(*str))))
		return (NULL);
	free(*str);
	*str = tmp;
	return (line);
}

static int		ft_verif(char **stock, int nbread, char **line, int fd)
{
	while (ft_isline(stock, nbread) == 0)
		return (get_next_line(fd, line));
	if (ft_isline(stock, nbread) == 1)
	{
		if (!(*line = ft_line(stock)))
			return (-1);
		return (1);
	}
	return (0);
}

static int		ft_init(char **stock, char **buf)
{
	char *tmp;

	if (*stock == NULL)
	{
		if (!(*stock = ft_strnew(ft_strlen(*buf))))
			return (-1);
		*stock = ft_strcpy(*stock, *buf);
	}
	else
	{
		if (!(tmp = ft_strjoin(*stock, *buf)))
			return (-1);
		free(*stock);
		*stock = tmp;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		*buf;
	static char	*stock = NULL;
	int			nbread;
	int			result;

	if (fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	if (!(buf = (char *)malloc(BUFF_SIZE + 1)))
		return (-1);
	nbread = read(fd, buf, BUFF_SIZE);
	if (nbread == -1)
		return (-1);
	buf[nbread] = '\0';
	if (ft_init(&stock, &buf) == -1)
		return (-1);
	free(buf);
	result = ft_verif(&stock, nbread, line, fd);
	if (result == 0 && stock != NULL)
		free(stock);
	return (result);
}
