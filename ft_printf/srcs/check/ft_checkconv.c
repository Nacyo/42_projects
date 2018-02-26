/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 19:03:48 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/07 16:40:22 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static int	ft_length(t_arg *arg, char *str)
{
	int		i;
	int		j;
	int		count_l;
	int		count_h;

	i = -1;
	j = 0;
	count_l = 0;
	count_h = 0;
	ft_memset(arg->height, '\0', 7);
	while (str[++i] && j < 7)
	{
		if (ft_strchr("zj", str[i]))
			arg->height[j++] = str[i];
		else if (ft_strchr("l", str[i]) && count_l < 2 && ++count_l)
			arg->height[j++] = str[i];
		else if (ft_strchr("h", str[i]) && count_h < 2 && ++count_h)
			arg->height[j++] = str[i];
	}
	return (SUCCESS);
}

static void	ft_check_error_flag(t_arg *arg)
{
	if (arg->flag.zero == 1 && arg->flag.minus == 1)
		arg->flag.zero = 0;
	if (arg->flag.space == 1 && arg->flag.plus == 1)
		arg->flag.space = 0;
}

static void	ft_check_error_height(t_arg *arg)
{
	if (((ft_strchr(arg->height, 'j') || ft_strchr(arg->height, 'z') ||
			(ft_strchr(arg->height, 'l') && ft_strchr(arg->height, 'h')))
			&& (arg->conv != 'c' && arg->conv != 's'))
			|| ft_strchr(&(arg->conv), 'O'))
	{
		ft_memset(arg->height, '\0', 7);
		arg->height[0] = 'j';
	}
}

int			ft_checkconv(char **ret, t_arg *arg, va_list ap)
{
	int i;

	ft_length(arg, arg->str);
	i = -1;
	while (arg->str[++i])
		;
	arg->conv = arg->str[i - 1];
	ft_check_error_flag(arg);
	ft_check_error_height(arg);
	if (ft_forest(ret, arg, ap) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
