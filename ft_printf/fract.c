/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:09:23 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/06/29 11:30:28 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_mul(t_node **base)
{
	int		i;
	int		carry;

	carry = 0;
	while ((*base)->next)
		*base = (*base)->next;
	while (1)
	{
		i = (*base)->data * 5 + carry;
		(*base)->data = i % 10;
		carry = i / 10;
		if (!((*base)->prev))
			break ;
		*base = (*base)->prev;
	}
	while (carry)
	{
		addnode(base, newnode(carry % 10));
		carry = carry / 10;
	}
}

t_node		*ft_base(int e)
{
	t_node	*base;
	int		i;

	i = 0;
	base = newnode(1);
	while (--i > e)
		ft_mul(&base);
	return (base);
}

void		ft_norm(t_node **node, int *carry, int j)
{
	if (j == 0)
	{
		*carry = *carry + (*node)->data;
		*node = (*node)->prev;
	}
	else
	{
		addnode(node, newnode(*carry % 10));
		*carry = *carry / 10;
	}
}

t_node		*ad(t_node *res, t_node *base, int l, int m)
{
	int		carry;
	t_node	*f;

	carry = 0;
	while (base->next)
		base = base->next;
	while (res->next)
		res = res->next;
	f = newnode(base->data);
	base = base->prev;
	while (++m)
	{
		if (base)
			ft_norm(&base, &carry, 0);
		if (m < l)
			ft_norm(&f, &carry, 1);
		else
		{
			ft_norm(&res, &carry, 0);
			ft_norm(&f, &carry, 1);
		}
	}
	return (f);
}

t_node		*ft_fracnode(unsigned long i, int e)
{
	t_node	*res;
	t_node	*base;
	t_node	*cpy;
	int		l[2];

	l[0] = -1;
	l[1] = e;
	res = newnode(0);
	base = ft_base(e);
	while (i != 0)
	{
		ft_mul(&base);
		if ((i >> 63) & 1)
		{
			cpy = res;
			res = ad(res, base, l[0], l[1]);
			l[0] = l[1];
			nodefree(cpy);
		}
		l[1]--;
		i = i << 1;
	}
	nodefree(base);
	return (res);
}
