/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:58:33 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/18 16:18:07 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void		ft_rra(t_all *all, char c)
{
	t_stack *tmp;
	t_stack *curr;

	if (all->a == NULL || all->nb_a == 1)
		return ;
	tmp = all->a;
	while (all->a->next->next != NULL)
		all->a = all->a->next;
	curr = all->a;
	all->a->next = NULL;
	all->a_end->next = tmp;
	all->a = all->a_end;
	all->a_end = curr;
	c = (c == P ? ft_add_move(RRA, all) : C);
}

void		ft_rrb(t_all *all, char c)
{
	t_stack *tmp;
	t_stack *curr;

	if (all->b == NULL || all->nb_b == 1)
		return ;
	tmp = all->b;
	while (all->b->next->next != NULL)
		all->b = all->b->next;
	curr = all->b;
	all->b->next = NULL;
	all->b_end->next = tmp;
	all->b = all->b_end;
	all->b_end = curr;
	c = (c == P ? ft_add_move(RRB, all) : C);
}

void		ft_rrr(t_all *all, char c)
{
	ft_rra(all, c);
	ft_rrb(all, c);
}
