/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:38:12 by ynacache          #+#    #+#             */
/*   Updated: 2018/02/27 16:12:35 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_read(char **argv, char **buf)
{
	int nb;
	int fd;
	int o_read;

	nb = 0;
	o_read = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	nb = read(fd, *buf, 676);
	o_read += nb;
	if (nb == -1)
		return (0);
	while (nb != 0)
	{
		nb = read(fd, *buf, 676);
		if (nb == -1)
			return (0);
		o_read += nb;
		if (o_read > 676)
			return (0);
	}
	if (close(fd) == -1)
		return (0);
	(*buf)[o_read] = '\0';
	return (1);
}

int		ft_err(char *str)
{
	ft_putstr(str);
	return (0);
}

int		main(int argc, char **argv)
{
	char	*buf;
	char	**p;
	char	**grid;
	int		i;

	p = NULL;
	buf = ft_strnew(677);
	if (argc != 2)
		return (ft_err("usage: fillit source_file\n"));
	if ((ft_read(argv, &buf) == 0) || !buf[0])
		return (ft_err("error\n"));
	if ((p = ft_validp(buf, 0, 0, p)) == NULL)
		return (ft_err("error\n"));
	if (NULL == (grid = ft_fillit(p)))
		return (ft_err("error\n"));
	i = 0;
	while (p[i][0])
		free(p[i++]);
	free(p);
	i = 0;
	while (grid[i])
		free(grid[i++]);
	free(grid);
	return (0);
}
