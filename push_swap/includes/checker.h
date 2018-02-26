/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:52:42 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/23 18:02:38 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <libft.h>
# include <get_next_line.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR -1
# define SUCCESS 0

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

# define P 'p'
# define C 'c'

typedef struct		s_stack
{
	int				val;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_move
{
	char			instruc[4];
	struct s_move	*next;
}					t_move;

typedef struct		s_all
{
	int				nb_a;
	int				nb_b;
	int				nb_move;
	int				option;
	t_move			*move;
	t_move			*move_end;
	t_stack			*a;
	t_stack			*b;
	t_stack			*a_end;
	t_stack			*b_end;
}					t_all;

typedef struct		s_f
{
	char			instruc[4];
	void			(*f)(t_all *all, char c);
}					t_f;

void				ft_algo_small(t_all *all);
void				ft_sort_int_a(t_all *all, int size);
void				ft_sort_int_b(t_all *all, int size, int length);

void				ft_check(int ac, char **av, t_all *all);
int					ft_order(t_stack *stack);

void				ft_error(int nb);
int					ft_add_a(int val, t_all *all);
int					ft_add_move(char *m, t_all *all);
int					ft_doublon(int val, t_all *all);
void				ft_free_move(t_all *all);
int					ft_free_a(t_all *all);

void				ft_affiche_move(t_all *all);
void				ft_move(t_all *all);

void				ft_sa(t_all *all, char c);
void				ft_sb(t_all *all, char c);
void				ft_ss(t_all *all, char c);
void				ft_pa(t_all *all, char c);
void				ft_pb(t_all *all, char c);
void				ft_ra(t_all *all, char c);
void				ft_rb(t_all *all, char c);
void				ft_rr(t_all *all, char c);
void				ft_rra(t_all *all, char c);
void				ft_rrb(t_all *all, char c);
void				ft_rrr(t_all *all, char c);

#endif
