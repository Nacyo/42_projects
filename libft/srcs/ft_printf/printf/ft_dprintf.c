/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:23:32 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/07 15:32:24 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	char	*str;
	int		ret;

	str = NULL;
	va_start(ap, format);
	ret = ft_vasprintf(&str, format, ap);
	va_end(ap);
	if (ret != ERROR && str != NULL)
		if (write(fd, str, ret) == ERROR)
			ret = ERROR;
	free(str);
	return (ret);
}
