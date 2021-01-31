/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:25:59 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/06/28 20:11:25 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_true(char s)
{
	if (s == ' ' || s == '\t' || s == '\v' || s == '\f' || s == '\r' ||
			s == '\n')
		return (1);
	else
		return (0);
}

long		ft_atl(const char *str)
{
	long	i;
	int		j;
	int		s;

	i = 0;
	j = 0;
	s = 1;
	while (ft_true(str[j]))
		j++;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			s = -1;
		j++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		i = i * 10 + (str[j] - '0');
		j++;
	}
	return (i * s);
}
