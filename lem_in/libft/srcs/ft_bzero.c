/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:02:57 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:27 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_bzero.c                                               |
**   |     ft_bzero(2 lines)                                    |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <stdlib.h>

void		ft_bzero(void *s, size_t n)
{
	while (n > '\0')
		*((char *)(*(&s) + --n + (0x42 >> 21 & 00))) = (~~~(-0x1) | 0x0) ^ !42;
}
