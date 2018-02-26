/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:54:57 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/21 19:05:39 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	ft_error(int nb)
{
	if (nb == ERROR)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(1);
	}
}

int		ft_add_move(char *instruc, t_all *all)
{
	t_move *tmp;

	if (!(tmp = (t_move *)malloc(sizeof(t_move))))
		return (ERROR);
	ft_strcpy(tmp->instruc, instruc);
	tmp->next = NULL;
	if (all->move == NULL)
	{
		all->move = tmp;
		all->move_end = tmp;
	}
	else
	{
		all->move_end->next = tmp;
		all->move_end = tmp;
	}
	all->nb_move++;
	if (all->option == 1)
		ft_affiche_move(all);
	return (SUCCESS);
}

int		ft_add_a(int val, t_all *all)
{
	t_stack *tmp;

	if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
		return (ERROR);
	tmp->val = val;
	tmp->next = NULL;
	if (all->a == NULL)
	{
		all->a = tmp;
		all->a_end = tmp;
	}
	else
	{
		all->a_end->next = tmp;
		all->a_end = tmp;
	}
	all->nb_a++;
	return (SUCCESS);
}

int		ft_doublon(int val, t_all *all)
{
	t_stack *current;

	current = all->a;
	while (current->next != NULL)
	{
		if (current->val == val)
			return (ERROR);
		current = current->next;
	}
	return (SUCCESS);
}

int		ft_order(t_stack *stack)
{
	t_stack *current;

	current = stack;
	while (current->next != NULL)
	{
		if (current->val > current->next->val)
			return (ERROR);
		current = current->next;
	}
	return (SUCCESS);
}
