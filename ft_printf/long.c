/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:47:16 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/07/07 18:21:28 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_nan(char *s, int *re)
{
	ft_putstr(s);
	*re = *re + ft_strlen(s);
}

unsigned long		*ft_getl(t_long l, int *e, int *k)
{
	unsigned long	*m;

	m = (unsigned long *)ft_malloc(sizeof(*m) * 2);
	*e = l.e - 16382 - MIN(ft_atoi("1"), (int)l.e);
	*k = MAXI(*e, ft_atoi("-1"));
	*k = MIN(*k, 63);
	if (*k >= 0)
	{
		m[1] = (l.fract) << (*k);
		m[1] = m[1] << 1;
		m[0] = l.fract >> (63 - *k);
	}
	else
	{
		m[0] = 0;
		m[1] = l.fract;
	}
	return (m);
}

t_node				**getnode(t_long l, int p)
{
	t_node			**res;
	unsigned long	*m;
	int				e[4];

	ft_zero(e, 4);
	m = ft_getl(l, e + 3, e + 2);
	res = (t_node **)ft_malloc(2 * sizeof(*res));
	if (p == 0)
	{
		res[1] = ft_fracnode(m[1], MIN(e[3], ft_atoi("-1")));
		e[0] = ft_prec(&res[1]);
		res[0] = ft_inte(m[0], e[3] - e[2], 0);
		e[1] = ft_after(res[0], e[0]);
		if (e[1])
			addnode(res, newnode(e[1]));
	}
	else
	{
		res[1] = ft_fracnode(m[1], MIN(e[3], ft_atoi("-1")));
		e[1] = ft_car(res[1], p);
		res[0] = ft_inte(m[0], e[3] - e[2], e[1]);
	}
	free(m);
	return (res);
}

void				getlong(t_long l, t_fo str, int *re)
{
	t_node		**floa;

	if (str.p == -1 || str.p >= 2147483648)
		str.p = 6;
	if (str.w >= 2147483648)
		str.w = -1;
	floa = getnode(l, str.p);
	*re = *re + ft_printflag(floa, str, (int)l.s);
	nodefree(floa[0]);
	nodefree(floa[1]);
	free(floa);
}

void				long_str(va_list ap, t_fo str, int *re)
{
	t_ldouble		l;

	l.var = va_arg(ap, long double);
	if ((l.ld).e == 32767)
	{
		if ((l.ld).fract & 4611686018427387904)
			ft_nan("nan", re);
		else
		{
			if ((l.ld).fract & 4611686018427387903)
				ft_nan("nan", re);
			else
			{
				if ((l.ld).s == 0)
					ft_nan("inf", re);
				else
					ft_nan("-inf", re);
			}
		}
	}
	else
		getlong(l.ld, str, re);
}
