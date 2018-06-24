/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_str_ud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:38:11 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/05 13:40:56 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

void	ft_fill_str_ud(char **str, long long nb, int *len, t_arg *arg)
{
	t_ull tmp;

	if (ft_strchr("uU", arg->conv))
		tmp = nb;
	else
		tmp = (nb < 0) ? -(t_ull)nb : (t_ull)nb;
	while (tmp > 0 && --(*len) >= 0)
	{
		(*str)[*len] = tmp % 10 + '0';
		tmp /= 10;
	}
}
