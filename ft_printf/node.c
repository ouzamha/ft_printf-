/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:45:56 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/07/07 18:17:04 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			fn(t_node *node)
{
	int	count;

	count = 1;
	while (node->next)
	{
		node = node->next;
		count++;
	}
	return (count);
}

t_node		*newnode(int data)
{
	t_node	*node;

	node = (t_node*)ft_malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void		nodefree(t_node *res)
{
	t_node	*next;

	while (res)
	{
		next = res->next;
		free(res);
		res = next;
	}
}

void		ft_print(t_node *res)
{
	while (res != NULL)
	{
		ft_putnbr(res->data);
		res = res->next;
	}
}

void		addnode(t_node **node1, t_node *node2)
{
	(*node1)->prev = node2;
	node2->next = *node1;
	*node1 = node2;
}
