/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:47:34 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/13 18:00:46 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strequ(char const *s1, char const *s2)
{
	int				i;
	unsigned char	*s3;
	unsigned char	*s4;

	i = 0;
	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s3[i] != '\0' && s4[i] != '\0' && s3[i] == s4[i])
		i++;
	return (s3[i] == s4[i] ? 1 : 0);
}
