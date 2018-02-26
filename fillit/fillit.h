/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:17:18 by emarin            #+#    #+#             */
/*   Updated: 2017/11/18 11:06:11 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include "libft.h"

typedef struct	s_point
{
	int i;
	int j;
}				t_point;

int				ft_voisin(char *p);
char			**ft_validp(char *s, int nbt, int er, char **part);
int				ft_validtetriminos(char *srcs);
char			**ft_fillit(char **parts);
void			ft_lstpushback(t_list **alst, t_list *new);
void			ft_printlstpoint(t_list *lst);
char			**ft_realloctab(char **grid, int nt);
char			ft_backtrack(char ***grid, char **parts, int size, int c);
int				ft_collision(char **grid, int *ij, char *part);
char			**ft_initgrid(void);
t_point			ft_getpos(char **grid, int size, char *part, t_point lastp);
void			ft_place(char ***grid, char *part, t_point p);
void			ft_remove(char ***grid, char *part, t_point p);

#endif
