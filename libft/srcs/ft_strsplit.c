/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:04:25 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/13 16:54:41 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_nbwords(char const *s, char c)
{
	int i;
	int result;

	i = 0;
	result = 0;
	if (*s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
			result++;
			i--;
		}
		i++;
	}
	if ((size_t)i != ft_strlen(s))
		return (1);
	return (result);
}

static int		ft_malloc_line(char **tab, char const *s, char c, int nbwords)
{
	int j;
	int i;
	int nb_letter;

	nb_letter = -1;
	i = 0;
	j = 0;
	if (nbwords == 0)
		if (!(tab[j] = (char *)malloc(1)))
			return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0' && nb_letter++)
				i++;
			if (!(tab[j] = (char *)malloc(nb_letter + 1)))
				return (0);
			nb_letter = -1;
			j++;
			i--;
		}
		i++;
	}
	return (1);
}

static void		ft_fill_line(char **tab, char const *s, char c)
{
	int j;
	int i;
	int index;

	index = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				tab[j][index] = s[i];
				i++;
				index++;
			}
			tab[j][index] = '\0';
			j++;
			index = 0;
			i--;
		}
		i++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nbwords;

	if (s == NULL)
		return (NULL);
	nbwords = ft_nbwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * nbwords + 1)))
		return (NULL);
	if (ft_malloc_line(tab, s, c, nbwords) == 0)
		return (NULL);
	tab[nbwords] = NULL;
	ft_fill_line(tab, s, c);
	return (tab);
}
