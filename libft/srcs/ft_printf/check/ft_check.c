/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:02:08 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/07 16:44:45 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static int	ft_checkflag(t_arg *arg, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '+')
			arg->flag.plus = 1;
		else if (str[i] == '#')
			arg->flag.hashtag = 1;
		else if (str[i] == '-')
			arg->flag.minus = 1;
		else if (str[i] == ' ')
			arg->flag.space = 1;
		else if ((str[i] == '0' && i == 0) ||
				(str[i] == '0' && (str[i - 1] < '0' || str[i - 1] > '9')
				&& str[i - 1] != '.'))
			arg->flag.zero = 1;
	}
	return (SUCCESS);
}

static int	ft_checkwidth2(t_arg *arg, char *str, int *i)
{
	if ((*i == 0) || (!ft_isdigit(str[*i - 1])
				&& (str[*i - 1] != '.')))
	{
		arg->wi = ft_atoi(str + *i);
		return (1);
	}
	else if (ft_isdigit(str[*i - 1]))
	{
		while (*i >= 1 && ft_isdigit(str[*i - 1]))
			--(*i);
		if (*i == 0 || str[*i - 1] != '.')
		{
			arg->wi = ft_atoi(str + *i);
			return (1);
		}
	}
	return (0);
}

static int	ft_checkwidth(t_arg *arg, char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (--i >= 0)
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			if (ft_checkwidth2(arg, str, &i) == 1)
				break ;
		}
	}
	return (SUCCESS);
}

static int	ft_checkprecision(t_arg *arg, char *str)
{
	int		i;

	i = ft_strlen(str);
	while (--i >= 0)
	{
		if (str[i] == '.')
		{
			if (str[++i] >= '0' && str[i] <= '9')
				arg->preci = ft_atoi((str + i));
			else
				arg->preci = 0;
			break ;
		}
	}
	return (SUCCESS);
}

/*
** call functions to get arg, and check if expression is valid
** check str if expression is not the first, need to free it
** init & validity are in ft_init
*/

int			ft_check(char **ret, char *str, va_list ap, t_arg *arg)
{
	ft_initarg(arg);
	if (str != NULL)
		free(arg->str);
	if (ft_checkflag(arg, str) == ERROR && ft_free(1, str))
		return (ERROR);
	if (ft_checkwidth(arg, str) == ERROR && ft_free(1, str))
		return (ERROR);
	if (ft_checkprecision(arg, str) == ERROR && ft_free(1, str))
		return (ERROR);
	if (!(arg->str = ft_strdup(str)) && ft_free(1, str))
		return (ERROR);
	if (ft_checkconv(ret, arg, ap) == ERROR && ft_free(2, str, arg->str))
		return (ERROR);
	ft_free(2, arg->str, str);
	return (SUCCESS);
}
