/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:38:19 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/07 13:56:36 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_abs_range(int min, int max)
{
	if (max < 0 && min < 0)
		return (-max - min);
	return (max - min);
}

int	*ft_range(int min, int max)
{
	int *tab;
	int i;
	int j;

	i = min;
	j = 0;
	if (min >= max)
	{
		tab = NULL;
		return (tab);
	}
	if (!(tab = (int *)malloc(sizeof(int) * ft_abs_range(min, max))))
		return (NULL);
	while (i != max)
	{
		tab[j] = i;
		i++;
		j++;
	}
	return (tab);
}
