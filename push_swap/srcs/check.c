/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:13:08 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/23 18:03:12 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int		ft_check_arg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]) && str[0] != '-')
			return (ERROR);
	}
	return (SUCCESS);
}

static void		ft_option(t_all *all, int *j, int *ac, int *i)
{
	++(*j);
	--(*i);
	--(*ac);
	all->option = 1;
}

static long		ft_latoi_cus(const char *str)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	if (ft_strlen(str) > 10)
		return (LONG_MAX);
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

void			ft_check(int ac, char **av, t_all *all)
{
	int		i;
	int		j;
	long	val;

	i = ac;
	j = 1;
	if (ft_strcmp(av[1], "-v") == 0)
		ft_option(all, &j, &ac, &i);
	while (--i)
		ft_error(ft_check_arg(av[j++]));
	j = 1;
	if (all->option == 1)
		++j;
	while (--ac)
	{
		if (ft_strcmp(av[j], "-v") == 0)
			ft_error(ERROR);
		val = ft_latoi_cus(av[j++]);
		ft_error((val < INT_MIN || val > INT_MAX) ? ERROR : 0);
		ft_add_a((int)val, all);
		if (ft_doublon(val, all) == ERROR && ft_free_a(all) == SUCCESS)
			ft_error(ERROR);
	}
}
