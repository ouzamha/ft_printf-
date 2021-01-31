/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inte.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:46:41 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/07/02 17:42:21 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_dataf(t_node **res, t_node **node1, t_node **node2, int *carry)
{
	int		data;

	data = *carry;
	data = data + (*node1)->data;
	data = data + (*node2)->data;
	*res = newnode(data % 10);
	*carry = data / 10;
	*node1 = (*node1)->prev;
	*node2 = (*node2)->prev;
}

void		ft_data(t_node **res, t_node **node1, t_node **node2, int *carry)
{
	int		data;
	t_node	*node;

	data = *carry;
	if (*node1 != NULL)
	{
		data = data + (*node1)->data;
		*node1 = (*node1)->prev;
	}
	if (*node2)
	{
		data = data + (*node2)->data;
		*node2 = (*node2)->prev;
	}
	node = newnode(data % 10);
	*carry = data / 10;
	node->next = *res;
	(*res)->prev = node;
	*res = node;
}

t_node		*nodeadd(t_node *node1, t_node *node2)
{
	t_node	*res;
	t_node	*f;
	int		carry;

	carry = 0;
	while (node1->next)
		node1 = node1->next;
	while (node2->next)
		node2 = node2->next;
	ft_dataf(&res, &node1, &node2, &carry);
	while (node1 || node2)
		ft_data(&res, &node1, &node2, &carry);
	if (carry == 1)
	{
		f = newnode(1);
		res->prev = f;
		f->next = res;
		res = f;
	}
	return (res);
}

void		nodemul(t_node **base, int i)
{
	int		carry;
	int		b;

	b = 1;
	carry = 0;
	while ((*base)->next != NULL)
		*base = (*base)->next;
	while (b == 1)
	{
		carry = (carry / 10) + (*base)->data * i;
		(*base)->data = carry % 10;
		if ((*base)->prev != NULL)
			*base = (*base)->prev;
		else
			b = 0;
	}
	while (carry / 10)
	{
		carry = carry / 10;
		addnode(base, newnode(carry % 10));
	}
}

t_node		*ft_inte(unsigned long i, int e, int carry)
{
	t_node	*res[3];
	int		j;

	j = 0;
	res[0] = newnode(carry);
	res[2] = newnode(1);
	while (j < e)
	{
		nodemul(res + 2, 2);
		j++;
	}
	while (i != 0)
	{
		if (i & 1)
		{
			res[1] = res[0];
			res[0] = nodeadd(res[0], res[2]);
			nodefree(res[1]);
		}
		nodemul(res + 2, 2);
		i = i >> 1;
		j++;
	}
	nodefree(res[2]);
	return (res[0]);
}
