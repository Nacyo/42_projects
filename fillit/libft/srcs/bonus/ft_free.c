/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:47:26 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/05 11:46:35 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

int		ft_free(size_t n, ...)
{
	void	*del;
	va_list ap;

	va_start(ap, n);
	while (n-- > 0)
		free((del = va_arg(ap, void *)));
	va_end(ap);
	return (1);
}
