/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:26:34 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/18 16:12:31 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void		ft_ra(t_all *all, char c)
{
	t_stack *tmp;

	if (all->a == NULL || all->nb_a == 1)
		return ;
	tmp = all->a;
	all->a = all->a->next;
	all->a_end->next = tmp;
	all->a_end->next->next = NULL;
	all->a_end = tmp;
	c == P ? ft_add_move(RA, all) : 0;
}

void		ft_rb(t_all *all, char c)
{
	t_stack *tmp;

	if (all->b == NULL || all->nb_b == 1)
		return ;
	tmp = all->b;
	all->b = all->b->next;
	all->b_end->next = tmp;
	all->b_end->next->next = NULL;
	all->b_end = tmp;
	c == P ? ft_add_move(RB, all) : 0;
}

void		ft_rr(t_all *all, char c)
{
	ft_ra(all, c);
	ft_rb(all, c);
}
