/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 12:45:51 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/07 15:40:42 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H

typedef unsigned long long	t_ull;
typedef long long			t_ll;

typedef union				u_type
{
	long long				d;
	t_ull					u;
	void					*p;
	char					*s;
	unsigned int			c;
	int						*n;
}							t_type;

typedef struct				s_flag
{
	int						hashtag;
	int						minus;
	int						plus;
	int						zero;
	int						space;
}							t_flag;

typedef struct				s_arg
{
	char					*str;
	t_type					arg;
	char					height[7];
	char					conv;
	t_flag					flag;
	int						wi;
	int						preci;
	int						cmpt;
}							t_arg;

#endif
