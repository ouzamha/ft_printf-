/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   racprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:30:22 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/06/28 22:52:52 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_num(char c)
{
	if (c == ' ')
		return (1);
	if (c == '#')
		return (2);
	if (c == '0')
		return (3);
	if (c == '-')
		return (4);
	if (c == '+')
		return (5);
	else
		return (0);
}

char		ft_flags(char **format)
{
	int		i;
	char	c;

	c = 0;
	while ((i = ft_num(**format)) > 0)
	{
		c += (1 << (i - 1));
		(*format)++;
	}
	return (c);
}

int			ft_width(char **format, va_list ap, char *fl)
{
	int		w;

	if (ft_isdigit(**format))
	{
		w = ft_atl(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		w = va_arg(ap, int);
		if (w < 0)
		{
			w = w * -1;
			*fl += 8;
		}
		(*format)++;
	}
	else
		w = -1;
	return (w);
}

int			ft_len1(char c)
{
	if (c == 'h')
		return (0);
	if (c == 'l')
		return (2);
	if (c == 'L')
		return (4);
	else
		return (-1);
}

int			ft_len(char **format)
{
	int		i;
	int		j;

	i = ft_len1(**format);
	if (i == 2 || i == 0 || i == 4)
	{
		(*format)++;
		j = ft_len1(**format);
		if (j == 2 || j == 0)
		{
			(*format)++;
			return (i + 1);
		}
		else
			return (i);
	}
	else
		return (i);
}
