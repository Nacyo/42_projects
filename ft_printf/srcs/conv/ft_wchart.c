/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:31:47 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/07 16:39:05 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

int			ft_strlenw(wchar_t wch)
{
	if (wch <= 0x7F && wch >= 0)
		return (1);
	if (wch <= 0x7FF && wch >= 0)
		return (2);
	if (wch <= 0xFFFF && wch >= 0)
		return (3);
	if (wch <= 0x10FFFF && wch >= 0)
		return (4);
	else
		return (ERROR);
}

int			ft_put_width(char **tab, t_arg *arg, int *i, int nbb)
{
	size_t size;

	size = nbb;
	*i = 0;
	if ((arg->flag).minus == 0 && arg->wi > nbb)
		*i = arg->wi - nbb;
	if (arg->wi > nbb)
		size = arg->wi;
	if (!(*tab = ft_strnew(size)))
		return (ERROR);
	ft_memset(*tab, ' ', size);
	return (SUCCESS);
}

int			ft_add_conv_bigc(char **ret, t_arg *arg)
{
	int		nb;
	wint_t	wch;

	wch = (wint_t)arg->arg.c;
	nb = ft_strlenw(wch);
	if (nb == ERROR)
		return (ERROR);
	else if ((wch <= 56319 && wch >= 55296) ||
			(wch >= 0xDB80 && wch <= 0xDBFF) ||
			(wch >= 0xDC00 && wch <= 0xDFFF))
		return (ERROR);
	else if ((MB_CUR_MAX == 1 && wch >= 128 && wch <= 255) || nb == 1)
		return (ft_print_oneb(ret, wch, arg));
	else if (MB_CUR_MAX == 1 && wch > 255)
		return (ERROR);
	else if (nb == 2)
		return (ft_print_twob(ret, wch, arg));
	else if (nb == 3)
		return (ft_print_treeb(ret, wch, arg));
	else if (nb == 4)
		return (ft_print_fourb(ret, wch, arg));
	return (ERROR);
}
