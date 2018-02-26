/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:30:13 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/03 14:04:12 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	t_arg arg;

	arg.cmpt = 0;
	if (ret == NULL)
		return (ERROR);
	if (ft_parse(ret, format, ap, &arg) == ERROR)
		return (ERROR);
	return (arg.cmpt);
}
