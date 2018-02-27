/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:19:52 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/13 20:22:45 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t j;
	size_t lgt_d;
	size_t lgt_s;

	lgt_d = ft_strlen(dst);
	j = 0;
	lgt_s = ft_strlen((char *)src);
	if (size <= lgt_d)
		return (size + lgt_s);
	if (size == lgt_d + 1)
		return (size + lgt_s - 1);
	while (src[j] != '\0' && size != 0 && j < size - lgt_d - 1)
	{
		dst[j + lgt_d] = ((char *)src)[j];
		j++;
	}
	dst[lgt_d + j] = '\0';
	return (lgt_d + lgt_s);
}
