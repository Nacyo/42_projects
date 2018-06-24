/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:20:19 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/05 15:08:06 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	int		ret;

	str = NULL;
	va_start(ap, format);
	ret = ft_vasprintf(&str, format, ap);
	va_end(ap);
	if (ret != ERROR && str != NULL)
		if (write(STDOUT_FILENO, str, ret) == ERROR)
			ret = ERROR;
	free(str);
	return (ret);
}
