/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:29:27 by emarin            #+#    #+#             */
/*   Updated: 2017/11/20 10:18:04 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static	char	*ft_moveleft(char tetr[21])
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (!(i == 4 || !((i + 1) % 5)))
		{
			if (i == 3 || !((i + 2) % 5))
				tetr[i] = '.';
			else
				tetr[i] = tetr[i + 1];
		}
		i++;
	}
	return (tetr);
}

static	char	*ft_moveup(char tetr[21])
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i == 19)
			tetr[i] = '\n';
		else if (i > 14)
			tetr[i] = '.';
		else
			tetr[i] = tetr[i + 5];
		i++;
	}
	return (tetr);
}

static char		*ft_symbol(char tetr[21], int pos)
{
	int i;

	i = 0;
	while (i < 21)
	{
		if (tetr[i] == '#')
			tetr[i] = 'A' + pos;
		i++;
	}
	return (ft_strdup(tetr));
}

static	char	*ft_move(char tetr[21], int pos)
{
	int		i;
	int		topv;
	int		leftv;
	int		noch;

	noch = 1;
	while (noch)
	{
		topv = 1;
		i = 0;
		while (i < 4 && topv)
			if (tetr[i++] == '#')
				topv = 0;
		tetr = (topv) ? ft_moveup(tetr) : tetr;
		leftv = 1;
		i = 0;
		while (i < 20 && leftv)
		{
			leftv = (tetr[i] == '#') ? 0 : 1;
			i += 5;
		}
		tetr = (leftv) ? ft_moveleft(tetr) : tetr;
		noch = (!topv && !leftv) ? 0 : 1;
	}
	return (ft_symbol(tetr, pos));
}

char			**ft_validp(char *s, int nbt, int er, char **part)
{
	int		ij[2];
	char	tetr[21];

	ij[1] = 0;
	ij[0] = 0;
	if (!(part = (char **)malloc(sizeof(char*) * 27)))
		return (NULL);
	while (s[ij[1]] && !er && nbt < 26)
	{
		while (s[ij[1]] && ij[1] % 21 < 20)
			tetr[ij[0]++] = s[ij[1]++];
		tetr[ij[0]] = '\0';
		ij[0] = 0;
		if ((s[ij[1]] && s[ij[1]] != '\n') || (!s[ij[1]] && ij[1] % 21 < 20))
			er += 1;
		er += ft_validtetriminos(tetr);
		er = (!er) ? er + !ft_voisin(tetr) : er;
		if (!er)
			part[nbt] = ft_move(tetr, nbt);
		nbt++;
		ij[1] = (s[ij[1]] && s[ij[1] + 1]) ? ij[1] + 1 : ij[1];
	}
	er = (s[ij[1]]) ? er + 1 : er;
	part[nbt] = "\0";
	return ((!er) ? part : NULL);
}
