/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:35:12 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/13 12:19:04 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_size(unsigned int n)
{
	int				size;
	unsigned int	dup;

	size = 1;
	dup = n;
	while (dup > 9)
	{
		dup = dup / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int				i;
	char			*new;
	unsigned int	u;

	u = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	i = ft_size(u);
	if (n < 0)
		i++;
	if (!(new = (char *)malloc(i + 1)))
		return (NULL);
	new[i] = '\0';
	i--;
	if (n < 0)
		new[0] = '-';
	while (u > 9)
	{
		new[i] = (u % 10) + '0';
		u = u / 10;
		i--;
	}
	new[i] = u + '0';
	return (new);
}
