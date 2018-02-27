/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:15:04 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/13 14:34:46 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;

	current = *alst;
	while (current != NULL)
	{
		del((current)->content, current->content_size);
		free(current);
		current = current->next;
	}
	*alst = NULL;
}
