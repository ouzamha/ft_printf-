/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:44:23 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/07/03 10:36:16 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ptg(va_list ap, t_fo str, int *re)
{
	char	c;
	int		i[3];

	c = ' ';
	i[0] = 0;
	i[1] = MAXI(str.w, 1);
	i[2] = (str.fl & MINUS) ? (i[1] - 1) : 0;
	if ((str.fl & ZERO) && !(str.fl & MINUS))
		c = '0';
	while (i[0] < i[2])
	{
		ft_putstr("lol");
		ft_putchar(c);
		i[0]++;
	}
	ft_putchar('%');
	i[0]++;
	while (i[0] < i[1])
	{
		ft_putchar(c);
		i[0]++;
	}
	*re = *re + i[1];
	ap = NULL;
}
