/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reald.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 12:22:44 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/07/07 18:19:25 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long				ft_num2(va_list ap, int i)
{
	long long			j;

	if (i == -1)
		j = (long long)va_arg(ap, int);
	else if (i == 1)
		j = (long long)((char)va_arg(ap, int));
	else if (i == 0)
		j = (long long)((short)va_arg(ap, int));
	else if (i == 2)
		j = (long long)va_arg(ap, long);
	else
		j = va_arg(ap, long long);
	return (j);
}

t_stc					ft_gets(long long i, t_fo str)
{
	t_stc				s;
	unsigned long long	k[2];

	if (i == 0 && str.p == 0)
	{
		s.n = 0;
		s.string = malloc(1);
		s.string[0] = '\0';
	}
	else
	{
		k[0] = i;
		if (i < 0)
			k[0] = i * -1;
		s.n = MAXI(count(k[0], 10), str.p);
		s.string = (char *)ft_malloc(s.n + 1);
		k[1] = s.n;
		s.string[s.n] = '\0';
		while (k[1])
		{
			s.string[--k[1]] = k[0] % 10 + '0';
			k[0] = k[0] / 10;
		}
	}
	return (s);
}

t_dec					ft_dec(va_list ap, t_fo str, int *re)
{
	t_dec				d;

	d.i = ft_num2(ap, str.l);
	d.s = ft_gets(d.i, str);
	d.ad = (d.i < 0 || (str.fl & (SPACE | PLUS))) ? 1 : 0;
	d.m = MAXI((d.s).n + d.ad, str.w);
	d.c = ' ';
	if ((ZERO & str.fl) && !(MINUS & str.fl) && str.p < 0)
		d.c = '0';
	d.start = !(MINUS & str.fl) ? (d.m - (d.s).n) : 0;
	if (d.ad == 1)
	{
		if (d.i < 0)
			d.e = '-';
		else if (str.fl & PLUS)
			d.e = '+';
		else
			d.e = ' ';
	}
	d.count = 0;
	*re = *re + d.m;
	return (d);
}

void					d_string(va_list ap, t_fo str, int *re)
{
	t_dec				d;

	d = ft_dec(ap, str, re);
	if (d.c == '0' && d.ad == 1)
		ft_putchar(d.e);
	d.count += d.ad;
	while (d.count++ < d.start)
		ft_putchar(d.c);
	if (d.c == ' ' && d.ad == 1)
		ft_putchar(d.e);
	ft_putstr((d.s).string);
	d.count += (d.s).n - 1;
	while (d.count++ < d.m)
		ft_putchar(' ');
	free((d.s).string);
}
