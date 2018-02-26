/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:39:28 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/07 16:41:08 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static int	ft_limit(char c)
{
	if (ft_strchr("+- 0#123456789.*lhzj", c) != NULL)
		return (1);
	return (0);
}

static int	ft_checklimit(char const *format, int i, char **expression)
{
	int index;
	int nbchar;

	index = i;
	nbchar = 1;
	while (ft_limit(format[i]) == 1 && format[i] != '\0')
	{
		++i;
		++nbchar;
	}
	if (format[i] == '\0')
		return (-i);
	if ((*expression = ft_strsub(format, index, nbchar)) == NULL)
		return (ERROR);
	return (nbchar);
}

static int	ft_norminette(char **ret, t_arg *arg, int x)
{
	if (ft_strcmp(*ret, "") == 0)
		return (ERROR);
	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		if (write(STDOUT_FILENO, *ret, arg->cmpt - x) == ERROR)
			return (ERROR);
	return (ERROR);
}

static int	ft_join_carac(int *i, const char *format, char **ret, t_arg *arg)
{
	char *tmp;

	if ((tmp = ft_strsub(format, *i, 1)) == NULL)
		return (ERROR);
	if ((*ret = ft_strfreejoin(*ret, tmp, 1, arg)) == NULL)
		return (ERROR);
	arg->cmpt++;
	++(*i);
	free(tmp);
	return (SUCCESS);
}

int			ft_parse(char **ret, const char *format, va_list ap, t_arg *arg)
{
	static int	i = 0;
	static int	x = 0;
	int			nbchar;
	char		*expression;

	nbchar = ((i *= 0) && (x *= 0)) ? 1 : 1;
	if (!(*ret = ft_strnew(0)))
		return (ERROR);
	while (format[i] && i < (int)ft_strlen(format))
		if (format[i] == '%' && ++i)
		{
			if ((nbchar = ft_checklimit(format, i, &expression))
					== (int)(ft_strlen(format) + 10))
				return (ERROR);
			if (nbchar <= 0 && ((i += -nbchar) ? 1 : 1))
				continue;
			if (ft_check(ret, expression, ap, arg) == ERROR)
				return (ft_norminette(ret, arg, x));
			x = ((i += nbchar) && (nbchar -= nbchar - 1)) ? 0 : 0;
		}
		else if (i < (int)ft_strlen(format))
			if (++x && ft_join_carac(&i, format, ret, arg) == ERROR)
				return (ERROR);
	return (SUCCESS);
}
