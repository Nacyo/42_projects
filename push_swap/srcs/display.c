/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 13:24:49 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/23 18:02:26 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	ft_affiche_move(t_all *all)
{
	t_stack *tmp;

	tmp = all->a;
	ft_putstr(">>>>>>>> A <<<<<<<\n");
	while (all->a != NULL)
	{
		ft_putnbr(all->a->val);
		ft_putstr("\n");
		all->a = all->a->next;
	}
	ft_putstr(">>>>>>>><<<<<<<\n");
	all->a = tmp;
	tmp = all->b;
	ft_putstr(">>>>>>>> B <<<<<<<\n");
	while (all->b != NULL)
	{
		ft_putnbr(all->b->val);
		ft_putstr("\n");
		all->b = all->b->next;
	}
	ft_putstr(">>>>>>>><<<<<<<\n");
	all->b = tmp;
}

void	ft_move(t_all *all)
{
	t_move	*tmp;

	tmp = all->move;
	while (all->move != NULL)
	{
		ft_putstr(all->move->instruc);
		ft_putstr("\n");
		all->move = all->move->next;
	}
	all->move = tmp;
}

void	ft_free_move(t_all *all)
{
	t_move *next;

	while (all->move)
	{
		next = all->move->next;
		free(all->move);
		all->move = next;
	}
}

int		ft_free_a(t_all *all)
{
	t_stack *next;

	while (all->a)
	{
		next = all->a->next;
		free(all->a);
		all->a = next;
	}
	while (all->b)
	{
		next = all->b->next;
		free(all->b);
		all->b = next;
	}
	return (SUCCESS);
}
