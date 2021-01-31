/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 01:00:15 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/07/02 17:44:48 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		c_string(va_list ap, t_fo str, int *res)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	i = MAXI(ft_atoi("1"), str.w);
	while (j < i)
	{
		if ((j == 0 && (str.fl & MINUS)) || (j == i - 1 && !(str.fl & MINUS)))
		{
			c = (char)va_arg(ap, int);
			ft_putchar(c);
		}
		else
			ft_putchar(' ');
		j++;
	}
	*res = *res + i;
}
