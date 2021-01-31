/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:53:35 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/07/02 18:26:58 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printall(t_node **floa, t_fo str)
{
	ft_print(floa[0]);
	if (str.p != 0)
	{
		ft_putchar('.');
		ft_print(floa[1]);
	}
	else
	{
		if (str.fl & HASH)
			ft_putchar('.');
	}
}

char		ft_flag(t_fo str, int s)
{
	char	c;

	if (s == 1 || (str.fl & PLUS))
	{
		if (s == 1)
			c = '-';
		else
			c = '+';
	}
	else
		c = '\0';
	return (c);
}

int			ft_printflag(t_node **fl, t_fo t, int s)
{
	int		i[3];
	char	c;
	char	k;

	c = ' ';
	k = ft_flag(t, s);
	if ((t.fl & ZERO) && !(t.fl & MINUS))
		c = '0';
	i[2] = (t.p != 0 || (t.fl & HASH)) ? 1 : 0;
	i[0] = fn(fl[0]) + t.p + (s | ((t.fl & PLUS) >> 4) | (t.fl & SPACE)) + i[2];
	i[1] = i[0];
	if (((s == 0 && !((t.fl & PLUS))) && (t.fl & SPACE)))
		ft_putchar(' ');
	if (c == '0' && k)
		ft_putchar(k);
	while (!(MINUS & t.fl) && i[0]++ < t.w)
		ft_putchar(c);
	if (c != '0' && k)
		ft_putchar(k);
	ft_printall(fl, t);
	while (i[0]++ < t.w)
		ft_putchar(' ');
	return (MAXI(t.w, i[1]));
}
