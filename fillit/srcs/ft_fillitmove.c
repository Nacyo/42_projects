/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillitmove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:19:52 by emarin            #+#    #+#             */
/*   Updated: 2018/02/27 16:11:20 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdlib.h>

int			ft_collision(char **grid, int *ij, char *part)
{
	int i;
	int j;
	int	nbsy;
	int	er;

	ij[2] = ij[0];
	er = 0;
	nbsy = 0;
	j = 0;
	while (grid[ij[1]] && !er && j < 4)
	{
		i = 0;
		ij[0] = ij[2];
		while (grid[ij[1]][ij[0]] && !er && i < 4)
		{
			if (part[j * 5 + i] != '.' && part[j * 5 + i] != '\n' && ++nbsy)
				if (grid[ij[1]][ij[0]] != '.')
					er += 1;
			i++;
			ij[0]++;
		}
		j++;
		ij[1]++;
	}
	return ((nbsy != 4 || er != 0) ? 0 : 1);
}

char		**ft_initgrid(void)
{
	int		j;
	char	**grid;

	if (!(grid = (char **)malloc(sizeof(char*) * 5)))
		return (NULL);
	j = 0;
	while (j < 2)
	{
		grid[j] = ft_strdup("..");
		j++;
	}
	grid[j] = NULL;
	return (grid);
}

t_point		ft_getpos(char **grid, int size, char *part, t_point lastp)
{
	t_point	point;
	int		cij[3];
	int		firstloop;

	point.i = -42;
	firstloop = 1;
	lastp.j = lastp.j - 1;
	while (++(lastp.j) < size)
	{
		if (!firstloop)
			lastp.i = -1;
		firstloop = 0;
		while (++(lastp.i) < size)
		{
			cij[0] = lastp.i;
			cij[1] = lastp.j;
			if (ft_collision(grid, cij, part))
			{
				point.i = lastp.i;
				point.j = lastp.j;
				return (point);
			}
		}
	}
	return (point);
}

void		ft_place(char ***grid, char *part, t_point p)
{
	int i;
	int j;
	int ip;
	int jp;

	jp = 0;
	j = p.j;
	while ((*grid)[j] && jp < 4)
	{
		ip = 0;
		i = p.i;
		while ((*grid)[j][i] && ip < 4)
		{
			if (part[jp * 5 + ip] != '.' && part[jp * 5 + ip] != '\n')
			{
				(*grid)[j][i] = part[jp * 5 + ip];
			}
			i++;
			ip++;
		}
		jp++;
		j++;
	}
}

void		ft_remove(char ***grid, char *part, t_point p)
{
	int i;
	int j;
	int ip;
	int jp;

	jp = 0;
	j = p.j;
	while ((*grid)[j] && jp < 4)
	{
		ip = 0;
		i = p.i;
		while ((*grid)[j][i] && ip < 4)
		{
			if (part[jp * 5 + ip] != '.' && part[jp * 5 + ip] != '\n')
				(*grid)[j][i] = '.';
			i++;
			ip++;
		}
		jp++;
		j++;
	}
}
