/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:16:24 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/21 13:31:09 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void		ft_null(t_stack **a, t_stack **b, t_stack **a_end)
{
	*a = *b;
	*a_end = *b;
	*b = (*b)->next;
	(*a_end)->next = NULL;
}

void		ft_pa(t_all *all, char c)
{
	t_stack *tmp;

	if (all->b == NULL)
		return ;
	if (all->a == NULL)
		ft_null(&all->a, &all->b, &all->a_end);
	else
	{
		tmp = all->a;
		all->a = all->b;
		all->b = all->b->next;
		all->a->next = tmp;
	}
	if (all->nb_b == 1)
		all->b_end = all->b;
	all->nb_b--;
	all->nb_a++;
	if (all->nb_b == 0)
	{
		all->b = NULL;
		all->b_end = NULL;
	}
	c == P ? ft_add_move(PA, all) : 0;
}

void		ft_pb(t_all *all, char c)
{
	t_stack *tmp;

	if (all->a == NULL)
		return ;
	if (all->b == NULL)
		ft_null(&all->b, &all->a, &all->b_end);
	else
	{
		tmp = all->b;
		all->b = all->a;
		all->a = all->a->next;
		all->b->next = tmp;
	}
	if (all->nb_a == 1)
		all->a_end = all->a;
	all->nb_b++;
	all->nb_a--;
	if (all->nb_a == 0)
	{
		all->a = NULL;
		all->a_end = NULL;
	}
	c == P ? ft_add_move(PB, all) : 0;
}
