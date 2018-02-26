/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloctab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <ynacache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:37:10 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/17 18:24:55 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_realloctab(char **grid, int nt)
{
	int		i;
	char	**new;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	if (!(new = (char **)malloc(sizeof(char *) * (nt + 1))))
		return (NULL);
	i = 0;
	while (i < nt)
	{
		new[i] = ft_strnew(nt + 1);
		new[i] = ft_memset(new[i], '.', nt);
		new[i][nt] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}
