/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:34:40 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/10 20:56:53 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	size_t i;

	i = 0;
	while (*(s1 + i))
		i++;
	while (*s2 && len--)
	{
		*(s1 + i) = *(char *)s2;
		i++;
		s2++;
	}
	*(s1 + i) = '\0';
	return (s1);
}
