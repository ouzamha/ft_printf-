/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 04:45:31 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/06/28 16:16:53 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		test_string(va_list ap, t_fo str, int *re)
{
	char	*st;
	int		i[4];
	char	*test;

	i[3] = -1;
	test = ft_strdup("(null)");
	st = va_arg(ap, char *);
	if (st == NULL)
		st = test;
	i[0] = (int)ft_strlen(st);
	if (str.p >= 0)
		i[0] = MIN(i[0], str.p);
	i[1] = MAXI(i[0], str.w);
	i[2] = (str.fl & MINUS) ? 0 : (i[1] - i[0]);
	while (++i[3] < i[2])
		ft_putchar(' ');
	while (i[3]++ < i[0] + i[2])
	{
		ft_putchar(*st);
		st++;
	}
	while (i[3]++ <= i[1])
		ft_putchar(' ');
	free(test);
	*re = *re + i[1];
}
