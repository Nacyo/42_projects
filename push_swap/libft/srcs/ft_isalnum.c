/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:14:32 by ynacache          #+#    #+#             */
/*   Updated: 2017/11/10 21:05:07 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return ((c <= 122 && c >= 97) || (c <= 90 && c >= 65)
			|| (c <= '9' && c >= '0'));
}
