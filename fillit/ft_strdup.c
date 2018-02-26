/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:31:37 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/10 20:56:13 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen_static(const char *s1)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	i = 0;
	if (!(result = (char *)malloc(ft_strlen_static(s1) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
