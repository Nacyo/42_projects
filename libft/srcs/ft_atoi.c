/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:47:47 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/23 11:05:13 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int sign;
	int result;

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
