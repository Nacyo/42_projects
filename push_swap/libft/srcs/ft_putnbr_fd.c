/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:24:59 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/13 17:55:53 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_putchar_fds(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putfd(unsigned int u, int fd)
{
	if (u >= 10)
	{
		ft_putfd(u / 10, fd);
		ft_putfd(u % 10, fd);
	}
	else
	{
		ft_putchar_fds(u + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int nb;

	if (n < 0)
		ft_putchar_fds('-', fd);
	nb = n < 0 ? (unsigned int)-n : (unsigned int)n;
	ft_putfd(nb, fd);
}
