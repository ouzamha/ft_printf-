/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 07:27:50 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/07/07 18:19:49 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_sh					nz(unsigned long long i, t_fo str, char *b, char *join)
{
	t_sh				s;
	int					si;

	s.h = 0;
	s.c = MAXI(count(i, 16), str.p);
	si = s.c;
	if (str.fl & HASH)
	{
		if (!(str.fl & MINUS) && (str.p < 0) && (str.fl & ZERO))
			s.h = 2;
		else
			s.c += 2;
	}
	s.string = (char *)ft_malloc(s.c + 1);
	s.string[s.c] = '\0';
	if (s.c != si)
		ft_memcpy(s.string, join, 2);
	str.l = s.c - si;
	while (--si >= 0)
	{
		s.string[si + str.l] = b[i % 16];
		i /= 16;
	}
	return (s);
}

t_sh					shex(unsigned long long i, t_fo str, char *b, char *jo)
{
	t_sh				s;

	if (i == 0)
	{
		s.h = 0;
		if (str.p == 0)
		{
			s.c = 0;
			s.string = malloc(1);
			s.string[0] = '\0';
			return (s);
		}
		s.c = MAXI(1, str.p);
		s.string = malloc(s.c + 1);
		s.string[s.c] = '\0';
		ft_memset(s.string, '0', s.c);
		return (s);
	}
	else
		return (nz(i, str, b, jo));
}

void					hex(va_list ap, t_fo str, int *re, char *b)
{
	unsigned long long	i;
	t_sh				s;
	int					m[2];
	char				c;

	c = ' ';
	i = ft_tyo(ap, str.l);
	s = shex(i, str, b, "0x");
	if ((str.fl & ZERO) && !(str.fl & MINUS) && str.p < 0)
		c = '0';
	m[1] = MAXI(str.w, s.c + s.h);
	m[0] = (MINUS & str.fl) ? 0 : (m[1] - s.c);
	str.l = s.h;
	if (s.h == 2)
		ft_putstr("0x");
	while (str.l++ < m[0])
		ft_putchar(c);
	ft_putstr(s.string);
	str.l = str.l + s.c;
	while (str.l++ <= m[1])
		ft_putchar(' ');
	free(s.string);
	*re = *re + m[1];
}

void					heupx(va_list ap, t_fo str, int *re, char *b)
{
	unsigned long long	i;
	t_sh				s;
	int					m[2];
	char				c;

	c = ' ';
	i = ft_tyo(ap, str.l);
	s = shex(i, str, b, "0X");
	if ((str.fl & ZERO) && !(str.fl & MINUS) && str.p < 0)
		c = '0';
	m[1] = MAXI(str.w, s.c + s.h);
	m[0] = (MINUS & str.fl) ? 0 : (m[1] - s.c);
	str.l = s.h;
	if (s.h == 2)
		ft_putstr("0X");
	while (str.l++ < m[0])
		ft_putchar(c);
	ft_putstr(s.string);
	str.l = str.l + s.c;
	while (str.l++ <= m[1])
		ft_putchar(' ');
	free(s.string);
	*re = *re + m[1];
}
