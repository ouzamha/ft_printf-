/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 14:46:46 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/06/28 20:07:55 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		fl_limits(char *string, int l, t_fo str, int *re)
{
	int		i[3];

	i[0] = MAXI(l, str.w);
	i[1] = (str.fl & MINUS) ? 0 : i[0] - l;
	i[2] = -1;
	while (++i[2] < i[1])
		ft_putchar(' ');
	ft_putstr(string);
	i[2] += l;
	while (i[2]++ < i[0])
		ft_putchar(' ');
	*re = *re + i[0];
}

void		fl_inf(char *string, t_fo str, int *re, int sign)
{
	int		i[4];
	char	c;

	c = '\0';
	i[3] = ft_strlen(string);
	if (!(sign) && ((str.fl & PLUS) || (str.fl & SPACE)))
	{
		if (str.fl & PLUS)
			c = '+';
		else
			c = ' ';
		i[3]++;
	}
	i[0] = MAXI(i[3], str.w);
	i[1] = (str.fl & MINUS) ? 0 : (i[0] - i[3]);
	i[2] = -1;
	while (++i[2] < i[1])
		ft_putchar(' ');
	if (c)
		ft_putchar(c);
	ft_putstr(string);
	i[2] += i[3];
	while (i[2]++ < i[0])
		ft_putchar(' ');
	*re = *re + i[0];
}

void		f_string(va_list ap, t_fo str, int *re)
{
	if (str.l == 4)
		long_str(ap, str, re);
	else
		double_str(ap, str, re);
}
