/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:04:49 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/06/28 20:14:35 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					onlyzero(t_fo str, int *re)
{
	int					i[4];
	char				*string;

	i[3] = -1;
	i[0] = 2;
	if (str.p == 0)
		string = ft_strdup("0x");
	else
	{
		string = ft_strdup("0x0");
		i[0]++;
	}
	i[1] = MAXI(i[0], str.w);
	i[2] = (str.fl & MINUS) ? 0 : (i[1] - i[0]);
	while (++i[3] < i[2])
		ft_putchar(' ');
	ft_putstr(string);
	i[3] += i[0];
	while (i[3]++ < i[1])
		ft_putchar(' ');
	free(string);
	*re = *re + i[1];
}

void					ft_notzeo(unsigned long long i, t_fo str, int *re)
{
	t_sh				s;
	int					m[2];
	char				c;

	c = ' ';
	s = shex(i, str, "0123456789abcdef", "0x");
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

void					p_string(va_list ap, t_fo str, int *re)
{
	unsigned long long	i;

	str.fl += HASH;
	i = ft_tyo(ap, 2);
	if (i == 0)
		onlyzero(str, re);
	else
		ft_notzeo(i, str, re);
}
