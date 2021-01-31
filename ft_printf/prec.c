/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 23:11:08 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/06/28 19:47:59 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_node		*end(int j)
{
	int		i;
	t_node	*new;

	i = 1;
	new = newnode(0);
	while (j > i++)
		addnode(&new, newnode(0));
	return (new);
}

int			ft_car(t_node *res, long p)
{
	t_node	*new;
	int		j;

	j = 1;
	while (res->next && j <= p)
	{
		res = res->next;
		j++;
	}
	if (j < p)
	{
		new = end(p - j);
		new->prev = res;
		res->next = new;
		return (0);
	}
	else if (j != p)
	{
		res = res->prev;
		j = ft_prec(&(res->next));
		return (ft_after(res, j));
	}
	else
		return (0);
}

int			ft_round(int data, int prev)
{
	if (prev < 5)
		return (data);
	else if (prev > 5)
		return (data + 1);
	else
	{
		if (data % 2 == 0 || data == 9)
			return (data);
		else
			return (data + 1);
	}
}

int			ft_prec(t_node **res)
{
	int		re;

	re = (*res)->data;
	if (re == 5)
		if ((*res)->next)
			re = 6;
	nodefree(*res);
	*res = NULL;
	return (re);
}

int			ft_after(t_node *res, int prev)
{
	int		carry;

	while (res->next)
		res = res->next;
	carry = ft_round(res->data, prev);
	res->data = carry % 10;
	carry = carry / 10;
	while (carry && res->prev)
	{
		res = res->prev;
		carry = res->data + carry;
		res->data = carry % 10;
		carry = carry / 10;
	}
	return (carry);
}
