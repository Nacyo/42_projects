/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:58:18 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/21 13:40:12 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void		ft_sa(t_all *all, char c)
{
	t_stack *tmp;
	t_stack *next;

	if (all->a == NULL || all->nb_a == 1)
		return ;
	else
	{
		tmp = all->a;
		next = all->a->next->next;
		all->a = all->a->next;
		all->a->next = tmp;
		all->a->next->next = next;
		if (all->nb_a == 2)
			all->a_end = all->a->next;
	}
	c == P ? ft_add_move(SA, all) : 0;
}

void		ft_sb(t_all *all, char c)
{
	t_stack *tmp;
	t_stack *next;

	if (all->b == NULL || all->nb_b == 1)
		return ;
	else
	{
		tmp = all->b;
		next = all->b->next->next;
		all->b = all->b->next;
		all->b->next = tmp;
		all->b->next->next = next;
		if (all->nb_b == 2)
			all->b_end = all->b->next;
	}
	c == P ? ft_add_move(SB, all) : 0;
}

void		ft_ss(t_all *all, char c)
{
	ft_sa(all, c);
	ft_sb(all, c);
}
