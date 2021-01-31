/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 04:16:57 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/07/07 18:16:05 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long long		ft_tyo(va_list ap, int i)
{
	unsigned long long	j;

	if (i == -1)
		j = (unsigned long long)va_arg(ap, unsigned int);
	else if (i == 1)
		j = (unsigned long long)((unsigned char)va_arg(ap, unsigned int));
	else if (i == 0)
		j = (unsigned long long)((unsigned short)va_arg(ap, unsigned int));
	else if (i == 2)
		j = (unsigned long long)va_arg(ap, unsigned long);
	else
		j = va_arg(ap, unsigned long long);
	return (j);
}

int						count(unsigned long long i, int base)
{
	int					j;

	j = 1;
	while ((i = i / base))
		j++;
	return (j);
}

t_stc					t_tl(unsigned long long i, t_fo str, int base)
{
	int					c;
	t_stc				stc;
	int					m;

	c = count(i, base);
	if ((str.fl & HASH) && base == 8)
		c++;
	stc.n = MAXI(c, str.p);
	m = stc.n;
	stc.string = (char *)ft_malloc(m + 1);
	stc.string[m] = '\0';
	while (--m >= 0)
	{
		stc.string[m] = i % base + '0';
		i /= base;
	}
	return (stc);
}

t_stc					t_tu(unsigned long long i, t_fo str, int base)
{
	t_stc				stc;

	if (i == 0)
	{
		stc.n = MAXI(1, str.p);
		stc.string = (char *)ft_malloc(stc.n + 1);
		if (str.p == 0 && !(str.fl & HASH))
		{
			stc.n = 0;
			stc.string[0] = '\0';
		}
		else
		{
			stc.string[stc.n] = '\0';
			ft_memset(stc.string, '0', stc.n);
		}
		return (stc);
	}
	else
		return (t_tl(i, str, base));
}

void					ou_string(va_list ap, t_fo str, int *re, int base)
{
	unsigned long long	i;
	t_stc				s;
	int					j[4];

	i = ft_tyo(ap, str.l);
	s = t_tu(i, str, base);
	j[3] = -16;
	if (str.p < 0 && !(MINUS & str.fl) && (ZERO & str.fl))
		j[3] = 0;
	j[0] = MAXI(str.w, s.n);
	j[1] = !(MINUS & str.fl) ? (j[0] - s.n) : 0;
	j[2] = 0;
	while (j[2] < j[1])
	{
		ft_putchar(j[3] + '0');
		j[2]++;
	}
	ft_putstr(s.string);
	j[2] += s.n;
	while (j[2]++ < j[0])
		ft_putchar(j[3] + '0');
	free(s.string);
	*re = *re + j[0];
}
