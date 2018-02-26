/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_conv_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:39:02 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/07 16:45:45 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static int			ft_check_sz_n(t_arg *arg)
{
	if (arg->conv == 'o' || arg->conv == 'O')
		return (arg->wi + arg->flag.hashtag * (arg->wi == 0 ? 1 : 0));
	else if (arg->conv == 'p')
		return (arg->wi + (arg->wi == 0 ? 2 : 0));
	else if (ft_strchr("Ddi", arg->conv))
		return (arg->wi + (arg->wi == 0
			&& (arg->flag.plus || arg->flag.space) ? 1 : 0));
	else
		return (arg->wi);
}

int					ft_case_conv_0(char **ret, t_arg *arg)
{
	char	*new;
	int		sz_n;

	sz_n = ft_check_sz_n(arg);
	if (sz_n == 0)
		return (SUCCESS);
	if (!(new = ft_strnew(sz_n)))
		return (ERROR);
	ft_memset(new, ' ', sz_n);
	if (ft_strchr("Ddi", arg->conv) && arg->flag.plus && arg->flag.minus)
		new[0] = '+';
	else if (ft_strchr("Ddi", arg->conv) && arg->flag.plus)
		new[sz_n - 1] = '+';
	else if (arg->flag.hashtag == 1 &&
			(arg->conv == 'o' || arg->conv == 'O') && arg->flag.minus)
		new[0] = '0';
	else if (arg->flag.hashtag == 1 && (arg->conv == 'o' || arg->conv == 'O'))
		new[sz_n - 1] = '0';
	else if (arg->conv == 'p' && arg->flag.minus)
		new[0] = (new[1] -= new[1] - 'x') ? '0' : '0';
	else if (arg->conv == 'p')
		new[sz_n - 2] = (new[sz_n - 1] -= new[sz_n - 1] - 'x') ? '0' : '0';
	if (!(*ret = ft_strfreejoin(*ret, new, sz_n, arg)))
		return (ERROR);
	return (ft_free(1, ((arg->cmpt += sz_n) ? new : new)));
}
