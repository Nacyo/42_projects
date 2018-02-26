/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:29:34 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/13 18:16:35 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *current;
	t_list *new;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = ft_lstnew(f(lst)->content, f(lst)->content_size);
	current = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		current->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		current = current->next;
	}
	return (new);
}
