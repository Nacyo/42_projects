/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:17:28 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/21 17:40:02 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;
	size_t			index;

	i = start;
	index = 0;
	if (s == NULL)
		return (NULL);
	if (!(new = (char *)malloc(len + 1)))
		return (NULL);
	while (index < len && s[i] != '\0')
	{
		new[index] = s[i];
		++index;
		++i;
	}
	new[index] = '\0';
	return (new);
}
