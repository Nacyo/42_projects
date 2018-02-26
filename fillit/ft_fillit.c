/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <ynacache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:14:29 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/18 11:52:43 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	affgrid(char **grid)
{
	int		index;

	index = 0;
	while (grid[index])
	{
		ft_putstr(grid[index]);
		ft_putchar('\n');
		index++;
	}
}

char	ft_callrealoc(int *size, char **parts, char ***grid)
{
	(*size)++;
	*grid = ft_realloctab(*grid, *size);
	return (ft_backtrack(grid, parts, *size, 0));
}

char	ft_backtrack(char ***grid, char **parts, int size, int c)
{
	t_point	point;

	point.i = -1;
	point.j = 0;
	point = ft_getpos(*grid, size, parts[c], point);
	if (point.i == -42)
		return ((c == 0) ? ft_callrealoc(&size, parts, grid) : '0');
	if (!parts[c + 1][0])
	{
		ft_place(grid, parts[c], point);
		return ('1');
	}
	else
	{
		while (point.i != -42)
		{
			ft_place(grid, parts[c], point);
			if ('1' == ft_backtrack(grid, parts, size, c + 1))
				return ('1');
			ft_remove(grid, parts[c], point);
			point = ft_getpos(*grid, size, parts[c], point);
		}
		return ((c == 0) ? ft_callrealoc(&size, parts, grid) : '0');
	}
	return ('1');
}

char	**ft_fillit(char **parts)
{
	char	**grid;

	if (!(grid = ft_initgrid()))
		return (NULL);
	ft_backtrack(&grid, parts, 2, 0);
	affgrid(grid);
	return (grid);
}
