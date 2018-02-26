/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:00:27 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/23 18:10:21 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	ft_block_a(t_all *all, int size1, int size2)
{
	int cmpt;

	cmpt = 0;
	while (all->b != NULL && (all->b->val > all->a->val) && (cmpt < size1))
	{
		ft_ra(all, P);
		++cmpt;
	}
	while (size2 > 0)
	{
		if (all->b == NULL)
			break ;
		else if (((all->b->val < all->a->val) &&
			(cmpt == 0 || all->b->val > all->a_end->val)) || cmpt == size1)
		{
			ft_pa(all, P);
			--size2;
			++size1;
		}
		else if (cmpt-- >= 0)
			ft_rra(all, P);
	}
	while (--cmpt >= 0)
		ft_rra(all, P);
}

void	ft_block_b(t_all *all, int size1, int size2)
{
	int cmpt;

	cmpt = 0;
	while (all->b != NULL && (all->a->val < all->b->val) && (cmpt < size1))
	{
		ft_rb(all, P);
		++cmpt;
	}
	while (size2 > 0)
	{
		if (all->b == NULL)
			break ;
		if (((all->a->val > all->b->val) &&
			(cmpt == 0 || all->a->val < all->b_end->val)) || cmpt == size1)
		{
			ft_pb(all, P);
			++size1;
			--size2;
		}
		else if (cmpt-- > 0)
			ft_rrb(all, P);
	}
	while (--cmpt >= 0)
		ft_rrb(all, P);
}

void	ft_recurtion(t_all *all, int size, int is_a)
{
	int s1;
	int s2;
	int i;

	i = 0;
	if (size <= 3)
	{
		is_a == 1 ? ft_sort_int_a(all, size) : ft_sort_int_b(all, size, size);
		return ;
	}
	s1 = size / 2;
	s2 = size / 2;
	if (size % 2 == 1)
		++s1;
	ft_recurtion(all, s2, 0);
	ft_recurtion(all, s1, 1);
	is_a == 1 ? ft_block_a(all, s1, s2) : ft_block_b(all, s2, s1);
}

int		main(int argc, char **argv)
{
	t_all	all;

	all.nb_a = 0;
	all.nb_b = 0;
	all.nb_move = 0;
	all.option = 0;
	all.move = NULL;
	all.move_end = NULL;
	all.a = NULL;
	all.a_end = NULL;
	all.b = NULL;
	all.b_end = NULL;
	if (argc == 1 || (argc == 2 && ft_strcmp(argv[1], "-v") == 0))
		return (0);
	ft_check(argc, argv, &all);
	if (all.nb_a <= 25)
		ft_algo_small(&all);
	else
		ft_recurtion(&all, all.nb_a, 1);
	ft_move(&all);
	ft_free_move(&all);
	ft_free_a(&all);
	return (0);
}
