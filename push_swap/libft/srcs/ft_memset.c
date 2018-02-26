/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:56:25 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/07 13:31:46 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memset(void *b, int c, size_t len)
{
	int		i;

	i = -1;
	while (++i < (int)len)
		((char*)b)[i] = (unsigned char)c;
	return (b);
}
