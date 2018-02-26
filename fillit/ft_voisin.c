/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voisin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <ynacache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:55:49 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/15 17:39:41 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_d(char *p, int i)
{
	if (p[i + 1] == '#')
		return (1);
	return (0);
}

int		ft_g(char *p, int i)
{
	if (i == 0)
		return (0);
	if (p[i - 1] == '#')
		return (1);
	return (0);
}

int		ft_b(char *p, int i)
{
	if (i > 13)
		return (0);
	if (p[i + 5] == '#')
		return (1);
	return (0);
}

int		ft_h(char *p, int i)
{
	if (i < 4)
		return (0);
	if (p[i - 5] == '#')
		return (1);
	return (0);
}

int		ft_voisin(char *p)
{
	int		i;
	int		v_j;
	int		v[4];

	i = 0;
	v_j = 0;
	while (i < 21 && v_j < 4)
	{
		if (p[i] == '#')
			v[v_j++] = ft_d(p, i) + ft_g(p, i) + ft_b(p, i) + ft_h(p, i);
		i++;
	}
	if ((v[0] != 0 && v[1] != 0 && v[2] != 0 && v[3] != 0) &&
		(v[0] >= 2 || v[1] >= 2 || v[2] >= 2 || v[3] >= 2))
		return (1);
	return (0);
}
