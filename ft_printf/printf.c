/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:22:52 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/07/03 11:21:24 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long		ft_pres(char **format, va_list ap)
{
	long	i;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			i = va_arg(ap, long);
			*format = *format + 1;
		}
		else if (ft_isdigit(**format))
		{
			i = ft_atl(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else
			i = 0;
	}
	else
		i = -1;
	return (i);
}

t_fo		ft_struct(char **format, va_list ap)
{
	t_fo	str;

	str.fl = ft_flags(format);
	str.w = ft_width(format, ap, &str.fl);
	str.p = ft_pres(format, ap);
	str.l = ft_len(format);
	return (str);
}

void		ft_int(t_type *t)
{
	t[0].c = 'd';
	t[0].f = &d_string;
	t[1].c = 'i';
	t[1].f = &d_string;
	t[2].c = 'o';
	t[2].f = &o_string;
	t[3].c = 'u';
	t[3].f = &u_string;
	t[4].c = 'x';
	t[4].f = &x_string;
	t[5].c = 'X';
	t[5].f = &upx_string;
	t[6].c = 'f';
	t[6].f = &f_string;
	t[7].c = 'c';
	t[7].f = &c_string;
	t[8].c = 's';
	t[8].f = &test_string;
	t[9].c = 'p';
	t[9].f = &p_string;
	t[10].c = '%';
	t[10].f = &ptg;
}

void		ft_help(char c, int *r)
{
	ft_putchar(c);
	*r = *r + 1;
}

int			ft_printf(const char *test, ...)
{
	t_n		n;

	ft_int(n.t);
	n.re = 0;
	n.format = (char *)&(*test);
	va_start(n.ap, test);
	while (*(n.format))
	{
		if (*(n.format) != '%')
			ft_help(*(n.format), &(n.re));
		else
		{
			n.format++;
			n.i = 0;
			n.str = ft_struct(&(n.format), n.ap);
			while (n.i < 11 && (n.t)[n.i].c != *(n.format))
				n.i++;
			(n.t[n.i]).f(n.ap, n.str, &(n.re));
		}
		n.format++;
	}
	va_end(n.ap);
	return (n.re);
	return (0);
}
