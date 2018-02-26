/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validtetriminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:20:12 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/17 19:29:37 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_validtetriminos(char *src)
{
	int i;
	int col;
	int er;
	int sharp;

	sharp = 0;
	er = 0;
	i = 0;
	col = 0;
	while (src[i] && (src[i] == '.' || src[i] == '#' || src[i] == '\n') && !er)
	{
		col++;
		if (src[i] == '\n')
			if (col > 5)
				er = 1;
		if (src[i] == '\n')
			col = 0;
		if (src[i++] == '#')
			sharp++;
		if (i > 20 || sharp > 4)
			er = 1;
	}
	if (src[i] || (!src[i] && src[i - 1] != '\n') || sharp != 4)
		er = 1;
	return (er);
}
