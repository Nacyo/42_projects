/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:11:00 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/09 20:32:29 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_latoi(const char *str)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\n'
			|| *str == '\n' || *str == '\f' || *str == '\r')
		str++;
	sign = (*str == '-' ? -1 : 1);
	if (sign == -1 || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		if (*str < '0' || *str > '9')
			return (result * sign);
	}
	return (result * sign);
}
