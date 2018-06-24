/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 12:43:30 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/07 15:39:41 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_2_H
# define FT_PRINTF_2_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <ft_printf_struct.h>
# include <ft_printf.h>

# define SUCCESS 0
# define ERROR -1
# define END 1

int			ft_conv_s(char **ret, t_arg *arg);
int			ft_conv_p(char **ret, t_arg *arg);
int			ft_conv_d(char **ret, t_arg *arg);
int			ft_conv_o(char **ret, t_arg *arg);
int			ft_conv_u(char **ret, t_arg *arg);
int			ft_conv_x(char **ret, t_arg *arg);
int			ft_conv_c(char **ret, t_arg *arg);
int			ft_conv_n(char **ret, t_arg *arg);
int			ft_conv_modulo(char **ret, t_arg *arg);
int			ft_conv_invalid(char **ret, t_arg *arg);

int			ft_add_conv_s(char **ret, t_arg *arg);
int			ft_put_width(char **tab, t_arg *arg, int *i, int nbb);
int			ft_print_twob(char **ret, unsigned int wch, t_arg *arg);
int			ft_print_treeb(char **ret, unsigned int wch, t_arg *arg);
int			ft_print_fourb(char **ret, unsigned int wch, t_arg *arg);
int			ft_print_oneb(char **ret, unsigned int wch, t_arg *arg);
int			ft_case_conv_0(char **ret, t_arg *arg);
void		ft_fill_str_ud(char **str, long long nb, int *len, t_arg *arg);
int			ft_init_conv_bigs(char **ret, t_arg *arg);
int			ft_length_cs(t_arg *argi);
char		ft_getheight(t_arg *arg);
int			ft_add_conv_bigc(char **ret, t_arg *arg);
int			ft_checknull_bigs(char **ret, t_arg *arg, char **str, wchar_t **x);
int			ft_add_conv_bigs(char **ret, t_arg *arg, wchar_t *x, int cmpt);
int			ft_strlenw_bigs(wchar_t wch);
char		**ft_strw_cpy(char **str, int start, char *tmp);
void		ft_check_nbcar(t_arg *arg, int *nbcar, wchar_t *x, int *strl);
int			ft_init_conv_bigs(char **ret, t_arg *arg);
int			ft_strlenw(wchar_t wch);

int			ft_forest(char **ret, t_arg *arg, va_list ap);
int			ft_checkconv(char **ret, t_arg *arg, va_list ap);
void		ft_initarg(t_arg *arg);
int			ft_check(char **ret, char *str, va_list ap, t_arg *arg);
int			ft_parse(char **retour, const char *format, va_list ap, t_arg *arg);

char		*ft_strfreejoin(char *s1, const char *s2, int size_s2, t_arg *arg);

#endif
