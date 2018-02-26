/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:53:51 by ynacache          #+#    #+#             */
/*   Updated: 2018/01/05 11:46:27 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	ft_abs(int nb)
{
	return ((nb < 0) ? -(unsigned int)nb : (unsigned int)nb);
}