/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:19:46 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/07/07 18:12:50 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long		ft_shift(unsigned long m, int e)
{
	int j;

	j = 12 + MAXI(ft_atoi("0"), e);
	if (j >= 64)
		return (0);
	else
		return (m << j);
}

unsigned long		*dl(t_float *f, int *ex)
{
	unsigned long	*m;
	long			e;

	m = (unsigned long *)ft_malloc(2 * sizeof(*m));
	e = 1;
	*(m + 1) = 0;
	if (f->e == 0)
	{
		f->e = 1;
		e = 0;
	}
	*ex = MAXI(ft_atoi("-1"), (int)f->e - 1023);
	*ex = MIN(*ex, 52);
	m[1] = f->fract;
	if (*ex < 0)
	{
		m[1] = m[1] << 11;
		m[1] = m[1] + (e << 63);
	}
	else
		m[1] = ft_shift(m[1], *ex);
	m[0] = f->fract >> (52 - MAXI(*ex, 0));
	if (*ex >= 0)
		m[0] = m[0] + (e << *ex);
	return (m);
}

t_node				**floatnode(t_float f, long p)
{
	unsigned long	*m;
	t_node			**inte;
	int				i[3];

	i[1] = 0;
	i[2] = 0;
	m = dl(&f, (i + 2));
	inte = (t_node **)ft_malloc(2 * sizeof(*inte));
	if (p == 0)
	{
		inte[1] = ft_fracnode(m[1], MIN((int)f.e - 1023, ft_atoi("-1")));
		i[0] = ft_prec(&inte[1]);
		inte[0] = ft_inte(m[0], (int)f.e - 1023 - i[2], 0);
		i[1] = ft_after(inte[0], i[0]);
		if (i[1])
			addnode(&inte[0], newnode(i[1]));
	}
	else
	{
		inte[1] = ft_fracnode(m[1], MIN((int)f.e - 1023, ft_atoi("-1")));
		i[1] = ft_car(inte[1], p);
		inte[0] = ft_inte(m[0], (int)f.e - 1023 - i[2], i[1]);
	}
	free(m);
	return (inte);
}

void				fl_string(t_float f, t_fo str, int *re)
{
	t_node			**floa;

	if (str.p == -1 || str.p >= 2147483648)
		str.p = 6;
	if (str.w >= 2147483648)
		str.w = -1;
	floa = floatnode(f, str.p);
	*re = *re + ft_printflag(floa, str, (int)f.sign);
	nodefree(floa[0]);
	nodefree(floa[1]);
	free(floa);
}

void				double_str(va_list ap, t_fo str, int *re)
{
	t_myfloat		flo;

	flo.f = va_arg(ap, double);
	if ((flo.sf).e == 2047)
	{
		if ((flo.sf).fract != 0)
			fl_limits("nan", 3, str, re);
		else if ((flo.sf).sign == 0)
			fl_inf("inf", str, re, (int)(flo.sf).sign);
		else
			fl_inf("-inf", str, re, (int)(flo.sf).sign);
	}
	else
		fl_string(flo.sf, str, re);
}
