/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bigs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:07:33 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/06 18:59:00 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

int			ft_checknull_bigs(char **ret, t_arg *arg, char **str, wchar_t **x)
{
	arg->conv = 's';
	ft_memset(arg->height, '\0', 7);
	arg->arg.s = NULL;
	free(*str);
	if (ft_add_conv_s(ret, arg) == ERROR)
		return (ERROR);
	if (*x != NULL)
		return (ERROR);
	return (SUCCESS);
}

int			ft_strlenw_bigs(wchar_t wch)
{
	if (MB_CUR_MAX == 1 && wch >= 128 && wch <= 255)
		return (1);
	if (wch <= 0x7F)
		return (1);
	if (wch <= 0x7FF)
		return (2);
	if (wch <= 0xFFFF)
		return (3);
	if (wch <= 0x10FFFF)
		return (4);
	else
		return (ERROR);
}

char		**ft_strw_cpy(char **str, int start, char *tmp)
{
	int k;

	k = 0;
	while ((*str)[start] && tmp[k])
		(*str)[start++] = tmp[k++];
	return (str);
}

void		ft_check_nbcar(t_arg *arg, int *nbcar, wchar_t *x, int *strl)
{
	int k;

	k = 0;
	*nbcar = 0;
	if (arg->preci == -1)
		arg->preci = *strl;
	while (arg->preci > *nbcar && x[k])
		*nbcar += ft_strlenw_bigs(x[k++]);
	if (*nbcar > *strl || *nbcar > arg->preci)
		*nbcar -= ft_strlenw_bigs(x[--k]);
	if (arg->wi == 0 && arg->preci != 0 && *nbcar != arg->preci)
		*strl = *nbcar;
	else if (arg->wi < arg->preci && *nbcar < arg->wi && *strl >= arg->wi)
		*strl = arg->wi;
	else if (arg->wi < arg->preci && *nbcar < arg->preci && *strl <= arg->preci)
		*strl = *nbcar;
}

int			ft_init_conv_bigs(char **ret, t_arg *arg)
{
	wchar_t	*x;
	int		cmpt;
	char	*str;

	str = NULL;
	x = (wchar_t *)(arg->arg.p);
	cmpt = 0;
	if (x == NULL)
		return (ft_checknull_bigs(ret, arg, &str, &x));
	if (arg->cmpt != 0)
	{
		cmpt = arg->cmpt;
		arg->cmpt = 0;
	}
	return (ft_add_conv_bigs(ret, arg, x, cmpt));
}
