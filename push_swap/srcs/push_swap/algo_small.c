/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 13:25:34 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/21 13:39:21 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	ft_sort_f(t_all *all, int pos)
{
	while (pos--)
		ft_ra(all, P);
	if (all->nb_a != 2)
		ft_pb(all, P);
}

void	ft_sort_b(t_all *all, int pos)
{
	pos = all->nb_a - pos;
	while (pos--)
		ft_rra(all, P);
	if (all->nb_a != 2)
		ft_pb(all, P);
}

void	ft_sort_3_int(t_all *all)
{
	t_stack *tmp;

	tmp = all->a;
	if (tmp->val < tmp->next->val && tmp->next->val > tmp->next->next->val)
		ft_rra(all, P);
	while (ft_order(all->a) == ERROR)
	{
		ft_sa(all, P);
		if (ft_order(all->a) == ERROR)
			ft_rra(all, P);
	}
}

void	ft_algo_small(t_all *all)
{
	int		min;
	int		i;
	int		pos;
	t_stack	*tmp;

	while (ft_order(all->a) == ERROR && all->a != NULL && all->a->next != NULL)
	{
		i = 0;
		pos = 0;
		tmp = all->a;
		min = tmp->val;
		while (tmp->next && ++i)
		{
			tmp = tmp->next;
			if (tmp->val < min && (pos = i))
				min = tmp->val;
		}
		if (all->nb_a == 3)
			ft_sort_3_int(all);
		if (all->nb_a != 3)
			(pos <= all->nb_a / 2) ? ft_sort_f(all, pos) : ft_sort_b(all, pos);
	}
	while (all->b != NULL)
		ft_pa(all, P);
}
