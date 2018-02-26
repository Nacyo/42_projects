/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 13:25:48 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/21 13:25:50 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int		ft_sorted_3(t_stack *stack)
{
	if (stack->val < stack->next->val)
		if (stack->next->val < stack->next->next->val)
			return (SUCCESS);
	return (ERROR);
}

static int		ft_inv_sorted_3(t_stack *stack)
{
	if (stack->val > stack->next->val)
		if (stack->next->val > stack->next->next->val)
			return (SUCCESS);
	return (ERROR);
}

void			ft_sort_int_a(t_all *all, int size)
{
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (all->a->val > all->a->next->val)
			ft_sa(all, P);
	}
	else if (size == 3)
	{
		while (ft_sorted_3(all->a) == ERROR)
		{
			if (all->a->val > all->a->next->val)
				ft_sa(all, P);
			if (ft_sorted_3(all->a) == ERROR)
			{
				ft_pb(all, P);
				ft_sa(all, P);
				ft_pa(all, P);
			}
		}
	}
}

void			ft_sort_int_b(t_all *all, int size, int length)
{
	while (length-- > 0)
		ft_pb(all, P);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (all->b->val < all->b->next->val)
			ft_sb(all, P);
	}
	else if (size == 3)
	{
		while (ft_inv_sorted_3(all->b) == ERROR)
		{
			if (all->b->val < all->b->next->val)
				ft_sb(all, P);
			if (ft_inv_sorted_3(all->b) == ERROR)
			{
				ft_pa(all, P);
				ft_sb(all, P);
				ft_pb(all, P);
			}
		}
	}
}
