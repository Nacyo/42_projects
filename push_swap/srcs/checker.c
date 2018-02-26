/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:10:30 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/22 19:37:32 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void		ft_exec(t_all *all, char *instruc)
{
	static t_f	tab[11] = {{SA, &ft_sa}, {SB, &ft_sb}, {PA, &ft_pa},
		{PB, &ft_pb}, {RA, &ft_ra}, {RB, &ft_rb}, {RR, &ft_rr},
		{RRA, &ft_rra}, {RRB, &ft_rrb}, {RRR, &ft_rrr}};
	int			i;

	i = 0;
	while (ft_strcmp(tab[i].instruc, instruc) != 0)
		++i;
	tab[i].f(all, C);
	if (all->option == 1)
		ft_affiche_move(all);
}

static int		ft_check_instruc(char *str)
{
	static char	*tab[11] = {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};
	int			i;

	i = 0;
	while (i < 11)
		if (ft_strcmp(tab[i++], str) == 0)
			return (SUCCESS);
	return (ERROR);
}

static void		ft_line(char **line)
{
	if (*line != NULL)
		free(*line);
}

static void		ft_read_instruc(t_all *all)
{
	int		i;
	char	*line;

	i = 1;
	line = NULL;
	while (i == 1)
	{
		if (line != NULL)
			free(line);
		line = NULL;
		i = get_next_line(STDIN_FILENO, &line);
		ft_error(i);
		if (i == 0)
		{
			ft_line(&line);
			break ;
		}
		if (ft_check_instruc(line) == ERROR)
		{
			ft_line(&line);
			ft_error(ERROR);
		}
		ft_exec(all, line);
	}
}

int				main(int argc, char **argv)
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
	ft_read_instruc(&all);
	ft_free_move(&all);
	if (ft_order(all.a) == SUCCESS && all.b == NULL)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	ft_free_a(&all);
	return (0);
}
