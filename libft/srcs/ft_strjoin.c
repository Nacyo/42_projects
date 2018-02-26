/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:34:35 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/21 17:48:20 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		k;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	k = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc(k + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		++i;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		new[i] = s2[k];
		++k;
		++i;
	}
	new[i] = '\0';
	return (new);
}
