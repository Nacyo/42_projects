/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:25:13 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/03 14:07:14 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

void	ft_initarg(t_arg *arg)
{
	arg->arg.d = 0;
	arg->height[0] = '\0';
	arg->conv = '\0';
	arg->flag.hashtag = 0;
	arg->flag.minus = 0;
	arg->flag.plus = 0;
	arg->flag.zero = 0;
	arg->flag.space = 0;
	arg->wi = 0;
	arg->preci = -1;
	arg->str = NULL;
}
