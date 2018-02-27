/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:31:35 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/13 20:12:18 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void		ft_putchars(char c)
{
	write(1, &c, 1);
}

static void		ft_put(unsigned int u)
{
	if (u >= 10)
	{
		ft_put(u / 10);
		ft_put(u % 10);
	}
	else
		ft_putchars(u + '0');
}

void			ft_putnbr(int n)
{
	unsigned int nb;

	if (n < 0)
		ft_putchars('-');
	nb = n < 0 ? (unsigned int)-n : (unsigned int)n;
	ft_put(nb);
}
